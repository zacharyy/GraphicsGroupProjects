#include "object.h"
#include <cstdlib>
#include <ctime>

Object::Object(std::string objectFileString)
{  

  const char *input;
  input = objectFileString.c_str();

  // Read our .obj file
  bool res = loadOBJ(input);

  if(res == false)
  {
    std::cout << "Error: Failed to load object file." << std::endl;
  }

  angle = 0.0f;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
  //glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt)
{
  angle += dt * M_PI/5000;
  //model = glm::translate( glm::mat4(1.0f),glm::vec3(8.0*sin(angle), 0.0, 8.0*cos(angle)));
  model = glm::scale(glm::vec3(1.0, 1.0, 1.0));   
  model = glm::rotate( model, (angle*2), glm::vec3(1.0f, 0.0f, 0.0f));

}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

/*Function that will load object files*/
bool Object::loadOBJ(const char * path)
{
  bool hasUV; //set to one if file has vt data
  bool hasNormal;  //set to one of file has vn data

  FILE * file = fopen(path, "r");
  if( file == NULL ){
    printf("Impossible to open the file !\n");
    return false;
  }
  //used to generate a random float
  srand(static_cast<unsigned int>(clock()));

  for(;;)
  {
    char lineHeader[128];
    // read the first word of the line
    int res = fscanf(file, "%s", lineHeader);
    if (res == EOF)
    {
      break; // EOF = End Of File. Quit the loop.
    }

    /*Load Vertices*/

    //regular vertices (v)
    if ( strcmp( lineHeader, "v" ) == 0 ){
      glm::vec3 position;
      glm::vec3 color;
      fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z);
      //randomly choose a color
      color.x = double(rand()) / (double(RAND_MAX) + 1.0);
      color.y = double(rand()) / (double(RAND_MAX) + 1.0);
      color.z = double(rand()) / (double(RAND_MAX) + 1.0);
      //create a new vertex with the position and color
      Vertex *tempVertex = new Vertex(position, color);
      //add this vertex to model
      Vertices.push_back(*tempVertex);
    }
    //uv vertices (vt)
    else if ( strcmp( lineHeader, "vt" ) == 0 ){
      hasUV = true;
      //not doing anything with uv vectors for now
    }
    //normal vertices (vn)
    else if ( strcmp( lineHeader, "vn" ) == 0 ){
      hasNormal = true;
      //not doing anything with normal vectors for now
    }

    /*Load Faces*/

    else if ( strcmp( lineHeader, "f" ) == 0 ){
      //make indices to hold the 3 different types of vertices
      unsigned int vertexIndex[3],uvIndex[3], normalIndex[3];
      //if faces look like: f # # #
      if(hasUV == false && hasNormal == false)
      {
        fscanf(file, "%d %d %d\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);
        Indices.push_back(vertexIndex[0]);
        Indices.push_back(vertexIndex[1]);
        Indices.push_back(vertexIndex[2]);
      }
      //if faces look like: f #//# #//# #//# 
      else if(hasUV == false && hasNormal == true)
      {
        fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], 
                                               &vertexIndex[1], &normalIndex[1],
                                               &vertexIndex[2], &normalIndex[2]);
        Indices.push_back(vertexIndex[0]);
        Indices.push_back(vertexIndex[1]);
        Indices.push_back(vertexIndex[2]);
      }
      //if faces look like: f #/# #/# #/# 
      else if(hasUV == true && hasNormal == false)
      {
        fscanf(file, "%d/%d %d/%d %d/%d\n", &vertexIndex[0], &uvIndex[0], 
                                            &vertexIndex[1], &uvIndex[1],
                                            &vertexIndex[2], &uvIndex[2]);
        Indices.push_back(vertexIndex[0]);
        Indices.push_back(vertexIndex[1]);
        Indices.push_back(vertexIndex[2]);
      }
      //if faces look like: f #/#/# #/#/# #/#/# 
      else if(hasUV == true && hasNormal == true)
      {
        fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                                     &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                                     &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
        Indices.push_back(vertexIndex[0]);
        Indices.push_back(vertexIndex[1]);
        Indices.push_back(vertexIndex[2]);
      }
    }
  }
  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }
  
  return true;
}

