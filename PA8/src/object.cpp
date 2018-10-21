#include "object.h"
#include <cstdlib>
#include <ctime>

Object::Object(std::string objectFileString)
{  

  const char *input;
  input = objectFileString.c_str();

	Magick::InitializeMagick(NULL);


  // Read our .obj file
  loadOBJ(input);

  angle = 0.0f;
/*
  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);*/
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
	for(int i = 0; i < 2; i++)
	{
  	/*glEnableVertexAttribArray(0);
  	glEnableVertexAttribArray(1);

  	glBindBuffer(GL_ARRAY_BUFFER, VB);
  	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  	glDrawElements(GL_TRIANGLES, meshes[i].Indices.size(), GL_UNSIGNED_INT, 0);

  	glDisableVertexAttribArray(0);
  	glDisableVertexAttribArray(1);*/
		meshes[i].Draw();
	}
}

/*Function that will load object files*/
void Object::loadOBJ(const char * path)
{
  //Create Importer
  Assimp::Importer importer;
  //Make Scene
  const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);

  /*Make Verticies*/
  int meshNumber = scene->mNumMeshes;
  for(int i=0; i < meshNumber; i++)
  {
		std::vector<Vertex> v;
		std::vector<unsigned int> ind;
    aiMesh *mesh = scene->mMeshes[i];
    for (unsigned int j=0; j<mesh->mNumVertices; j++)
    {
      const aiVector3D* pPos = &(mesh->mVertices[j]);
      //const aiVector3D* pNormal = &(mesh->mNormals[i]) : &Zero3D;
      const aiVector3D pTexCoord = mesh->mTextureCoords[0][j];

      /*Vertex v(glm::vec3(pPos->x, pPos->y, pPos->z),
               glm::vec2(pTexCoord->x, pTexCoord->y)
               Vector3f(pNormal->x, pNormal->y, pNormal->z));*/

      /*aiMaterial *mtl = scene->mMaterials[mesh->mMaterialIndex];
      aiColor4D diffuse;
      aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse);
      if (AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
      {
        if(diffuse.r != 0.6f && diffuse.g != 0.6f && diffuse.b != 0.6f)
        {
          glm::vec3 vec = glm::vec3(pPos->x, pPos->y, pPos->z);
          Vertex *temp = new Vertex(vec, color);
          Vertices.push_back(*temp);
        }
        else
        {*/
          glm::vec3 color;
          color.x = double(rand()) / (double(RAND_MAX) + 1.0);
          color.y = double(rand()) / (double(RAND_MAX) + 1.0);
          color.z = double(rand()) / (double(RAND_MAX) + 1.0);
          glm::vec3 vec = glm::vec3(pPos->x, pPos->y, pPos->z);
          Vertex *temp = new Vertex(vec, color, glm::vec2(pTexCoord.x, pTexCoord.y));
          v.push_back(*temp);
        /*}
      }
      else
      {
          std::cout << "Failed to load vertex." << std::endl;
      }*/
    }

    /*Make Faces*/
    for (unsigned int j=0; j < mesh->mNumFaces; j++) 
    {
      const aiFace& Face = mesh->mFaces[j];
      assert(Face.mNumIndices == 3);
      ind.push_back(Face.mIndices[0]);
      ind.push_back(Face.mIndices[1]);
      ind.push_back(Face.mIndices[2]);
    }
		// Hard coded for buddha object
		if(i == 0)
			meshes.push_back(Mesh(v,ind,"../objects/granite.jpg"));
		else
			meshes.push_back(Mesh(v,ind,"../objects/checker.jpg"));
  }
  //return true;
}

