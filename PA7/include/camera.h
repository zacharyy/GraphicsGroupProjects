#ifndef CAMERA_H
#define CAMERA_H

#include "graphics_headers.h"

class Camera
{
  public:
    Camera();
    ~Camera();
    bool Initialize(int w, int h);
    glm::mat4 GetProjection();
    glm::mat4 GetView();
  
    /*functions that will change camera view*/
    void NormalView();
    void TopDownView();
    void TopDownViewUpdated(glm::vec3 eyePosition, glm::vec3 focusPoint);
    void PlanetView(glm::vec3 eyePosition, glm::vec3 focusPoint);

    /*variables that will help move the camera in top down mode*/
    glm::vec3 defaultTDEyePosition; //default eye position of the top down camera
    glm::vec3 defaultTDFocusPoint; //default focus point of the top down camera
    glm::vec3 currentTDEyePosition; //updated eye position of the top down camera
    glm::vec3 currentTDFocusPoint; //updated focus point of the top down camera

  private:
    glm::mat4 projection;
    glm::mat4 view;
};

#endif /* CAMERA_H */
