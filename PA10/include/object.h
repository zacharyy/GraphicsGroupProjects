#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"
#include "mesh.h"
class Object
{
  public:
    Object();
    Object(std::string objectFileString, std::string textureFileString, btTriangleMesh* triMesh, bool useTriMesh);
    ~Object();
    void Update(unsigned int dt);
    void Render(Shader *m_shader, float);

    glm::mat4 GetModel();

    void loadOBJ(const char * path, btTriangleMesh* triMesh, bool useTriMesh);
		std::string textureFile;
    glm::mat4 model;

    //double speedScaler;
    //bool sizeScaler;

  private:
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;
    GLuint texture;

    float angle;

    std::vector<Mesh> meshes;
};

#endif /* OBJECT_H */
