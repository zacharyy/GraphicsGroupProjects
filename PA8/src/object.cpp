#include "object.h"
#include <cstdlib>
#include <ctime>
Object::Object()
{

}
Object::Object(std::string objectFileString, std::string textureFileString, btTriangleMesh* triMesh)
{  

  const char *input;
  input = objectFileString.c_str();
	
	textureFile = textureFileString;


  // Read our .obj file
  loadOBJ(input, triMesh);

  angle = 0.0f;
	speedScaler = 0.001;
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
  angle += ((speedScaler * 10/(2*M_PI)*dt/1000));
  //glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f * cos(angle/5), 0.0f,5.0f * sin(angle/5)));
  model = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));
	model = glm::scale(model, glm::vec3(1, 1, 1));

}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render()
{
	meshes[0].Draw();
}

/*Function that will load object files*/
void Object::loadOBJ(const char * path, btTriangleMesh* triMesh)
{
  //Create Importer
  Assimp::Importer importer;
  //Make Scene
  const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

  btVector3 triArray[3];

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

      for (int jindex = 0; jindex < 3; jindex++)
      {
        aiVector3D position = scene->mMeshes[0]->mVertices[Face.mIndices[jindex]];
        triArray[jindex] = btVector3(position.x, position.y, position.z);
        Indices.push_back( Face.mIndices[jindex] );
      }
      triMesh->addTriangle(triArray[0], triArray[1], triArray[2]);

      assert(Face.mNumIndices == 3);
      ind.push_back(Face.mIndices[0]);
      ind.push_back(Face.mIndices[1]);
      ind.push_back(Face.mIndices[2]);
    }
		meshes.push_back(Mesh(v,ind,textureFile));
	}	
  //return true;
}

