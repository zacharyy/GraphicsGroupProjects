#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object(std::string objectFileString);
    ~Object();
    void Update(unsigned int dt);
    void Render();

    glm::mat4 GetModel();

    bool loadOBJ(const char * path);
  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angle;
};

#endif /* OBJECT_H */
