#include "camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}

bool Camera::Initialize(int w, int h)
{
  //--Init the view and projection matrices
  //  if you will be having a moving camera the view matrix will need to more dynamic
  //  ...Like you should update it before you render more dynamic 
  //  for this project having them static will be fine
  
  //Set default eye position and focus point for camera
  defaultTDEyePosition = glm::vec3(0.0, 600.0, 1.0);
  defaultTDFocusPoint = glm::vec3(0.0, 0.0, 0.0);
  //Initially set updated camera positions to default positions
  currentTDEyePosition = defaultTDEyePosition;
  currentTDFocusPoint = currentTDEyePosition;

  //initially set camera to normal view
  NormalView();

  projection = glm::perspective( 45.0f, //the FoV typically 90 degrees is good which is what this is set to
                                 float(w)/float(h), //Aspect Ratio, so Circles stay Circular
                                 0.01f, //Distance to the near plane, normally a small value like this
                                 10000000.0f); //Distance to the far plane, 
  return true;
}

glm::mat4 Camera::GetProjection()
{
  return projection;
}

glm::mat4 Camera::GetView()
{
  return view;
}

/*this function will put the camera in "normal mode" by changing where its eye position and focus point*/
void Camera::NormalView()
{
  view = glm::lookAt( glm::vec3(0.0, 200.0, -500.0), //Eye Position
                      glm::vec3(0.0, 0.0, 0.0), //Focus point
                      glm::vec3(0.0, 1.0, 0.0)); //Positive Y is up
}
/*this function will put the camera in a top down position by changing where its eye position and focus point*/
void Camera::TopDownView()
{
  view = glm::lookAt( defaultTDEyePosition, //Eye Position
                      defaultTDFocusPoint, //Focus point
                      glm::vec3(0.0, 1.0, 0.0)); //Positive Y is up
}

/*Realized after the project was submitted that TopDownViewUpdated() and PlanetView() are essentially doing the same thing and can proably be combined into a more generic function such as "UpdateCamera()"*/

/*this function will move the camera when it is in top down mode by changing its eye position and focus point based on user input*/
void Camera::TopDownViewUpdated(glm::vec3 eyePosition, glm::vec3 focusPoint)
{
  view = glm::lookAt( eyePosition, //Eye Position
                      focusPoint, //Focus point
                      glm::vec3(0.0, 1.0, 0.0)); //Positive Y is up
}

/*this function will move the camera to follow a planet by changing its eye position and focus point based on the planets size and model position*/
void Camera::PlanetView(glm::vec3 eyePosition, glm::vec3 focusPoint)
{
  view = glm::lookAt( eyePosition, //Eye Position
                      focusPoint, //Focus point
                      glm::vec3(0.0, 1.0, 0.0)); //Positive Y is up
}



