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
  //Create Importer
  Assimp::Importer importer;
  //Make Scene
  const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);


  /*
  numVerts = mesh->mNumFaces*3; 
  vertexArray = new float[mesh->mNumFaces*3*3];
  normalArray = new float[mesh->mNumFaces*3*3];
  uvArray = new float[mesh->mNumFaces*3*2];

  std::vector m_Entries;
  std::vector m_Textures;
  m_Entries.resize(pScene->mNumMeshes);
  m_Textures.resize(pScene->mNumMaterials);
  */
  /*Make Verticies*/
   //aiMesh *mesh;

  for(unsigned int j=0; j < scene->mNumMeshes; j++)
  {
    aiMesh *mesh = scene->mMeshes[j];
    for (unsigned int i=0; i<mesh->mNumVertices; i++)
    {
      const aiVector3D* pPos = &(mesh->mVertices[i]);
      //const aiVector3D* pNormal = &(mesh->mNormals[i]) : &Zero3D;
      //const aiVector3D* pTexCoord = mesh->HasTextureCoords(0) ? &(mesh->mTextureCoords[0][i]) : &Zero3D;

      const aiMaterial *mtl = scene->mMaterials[mesh->mMaterialIndex];
      aiColor4D diffuse;
      aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse);
      //if (AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
      //{
        glm::vec3 color = glm::vec3(diffuse.r, diffuse.g, diffuse.b/*, diffuse.a*/);
      //}

      glm::vec3 vec = glm::vec3(pPos->x, pPos->y, pPos->z);
      Vertex *temp = new Vertex(vec, color);

      /*Vertex v(glm::vec3(pPos->x, pPos->y, pPos->z),
               glm::vec2(pTexCoord->x, pTexCoord->y)
               Vector3f(pNormal->x, pNormal->y, pNormal->z));*/
    
      Vertices.push_back(*temp);
    }
    /*Make Faces*/
    for (unsigned int i=0; i<mesh->mNumFaces; i++) 
    {
      const aiFace& Face = mesh->mFaces[i];
      assert(Face.mNumIndices == 3);
      Indices.push_back(Face.mIndices[0]);
      Indices.push_back(Face.mIndices[1]);
      Indices.push_back(Face.mIndices[2]);
    }
  }
  return true;
}
