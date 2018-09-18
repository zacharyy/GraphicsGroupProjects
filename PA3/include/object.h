#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void PlanetUpdate(unsigned int dt, bool pspin_reverse, bool pspin_stop, 
                      bool prevolution_reverse, bool prevolution_stop);
    void UpdateMoon(unsigned int dt, glm::mat4 parent_model,
                    bool& mspin_reverse, bool& mspin_stop, 
                    bool& mrevolution_reverse, bool& mrevolution_stop);
    void Render();

    glm::mat4 GetModel();
    
    Object *moon;

  private:
    //class
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    //float angle;
    float spin_angle; //spin
    float rev_angle; //revolution
};

#endif /* OBJECT_H */
