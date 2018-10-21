#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"
#include "mesh.h"
class Object
{
  public:
    Object(std::string objectFileString);
    ~Object();
    void Update(unsigned int dt);
    void Render();

    glm::mat4 GetModel();

    void loadOBJ(const char * path);
  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;
		GLuint texture;

    float angle;

    std::vector<Mesh> meshes;
};

#endif /* OBJECT_H */
