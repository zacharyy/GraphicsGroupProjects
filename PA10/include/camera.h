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
    void UpdateView(glm::vec3 eyePosition, glm::vec3 focusPoint);

    glm::vec3 currentEyePosition; //updated eye position of the top down camera
    glm::vec3 currentFocusPoint; //updated focus point of the top down camera

  private:
    glm::mat4 projection;
    glm::mat4 view;
};

#endif /* CAMERA_H */
