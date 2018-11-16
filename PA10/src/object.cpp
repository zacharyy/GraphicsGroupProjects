#include "object.h"
#include "shader.h"
#include <cstdlib>
#include <ctime>
Object::Object()
{

}
Object::Object(std::string objectFileString, std::string textureFileString, btTriangleMesh* triMesh, bool useTriMesh)
{  

  const char *input;
  input = objectFileString.c_str();
	
  textureFile = textureFileString;


  // Read our .obj file
  loadOBJ(input, triMesh, useTriMesh);

  angle = 0.0f;
  //speedScaler = 0.001;

}
Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt)
{
    	model = translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
    	model = rotate(model, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    	model = translate(model, glm::vec3(-1.0f, 0.0f, 0.0f));
}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render(Shader *m_shader, float specular)
{
	meshes[0].Draw(m_shader, specular);
}

/*Function that will load object files*/
void Object::loadOBJ(const char * path, btTriangleMesh* triMesh, bool useTriMesh)
{
	//std::cout << textureFile << std::endl;
  //Create Importer
  Assimp::Importer importer;
  //Make Scene
  const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);

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
      const aiVector3D pTexCoord = mesh->mTextureCoords[0][j];

      aiMaterial *mtl = scene->mMaterials[mesh->mMaterialIndex];
      aiColor3D diffuse;
      aiColor3D ambient;
      aiColor3D specular;

      mtl->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse);
      mtl->Get(AI_MATKEY_COLOR_AMBIENT, ambient);
      mtl->Get(AI_MATKEY_COLOR_SPECULAR, specular);

      glm::vec3 vec = glm::vec3(pPos->x, pPos->y, pPos->z);
				
      glm::vec3 normal = glm::vec3(mesh->mNormals[j].x,mesh->mNormals[j].y,mesh->mNormals[j].z);
      Vertex *temp = new Vertex(vec, normal , glm::vec2(pTexCoord.x, pTexCoord.y), glm::vec3(diffuse.r, diffuse.g, diffuse.b), glm::vec3(ambient.r, ambient.g, ambient.b), glm::vec3(specular.r, specular.g, specular.b));
      v.push_back(*temp);
    }

    /*Make Faces*/
    for (unsigned int j=0; j < mesh->mNumFaces; j++) 
    {
      const aiFace& Face = mesh->mFaces[j];
      //make bullet tri meshes
      if(useTriMesh)
      {
        for (int jindex = 0; jindex < 3; jindex++)
        {
          aiVector3D position = scene->mMeshes[0]->mVertices[Face.mIndices[jindex]];
          triArray[jindex] = btVector3(position.x, position.y, position.z);
          Indices.push_back( Face.mIndices[jindex] );
        }
        triMesh->addTriangle(triArray[0], triArray[1], triArray[2]);
      }
      assert(Face.mNumIndices == 3);
      ind.push_back(Face.mIndices[0]);
      ind.push_back(Face.mIndices[1]);
      ind.push_back(Face.mIndices[2]);
    }
		meshes.push_back(Mesh(v,ind,textureFile));
	}	
  //return true;
}
