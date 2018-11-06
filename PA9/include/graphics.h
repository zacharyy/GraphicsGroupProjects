#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt);
    void Render();
    btTransform newtrans;

    btRigidBody *ballRigidBody;
    btRigidBody *boardRigidBody;
    btRigidBody *cylinderRigidBody;
    btRigidBody *cubeRigidBody;
    btRigidBody *backRigidBody;
    btRigidBody *frontRigidBody;
    btRigidBody *leftRigidBody;
    btRigidBody *rightRigidBody;
    btRigidBody *bottomRigidBody;

   void UpdateShader(int newLightingType);

   int lightingType;
   int newLightingType;
   float ambientValue;
   float cubeSpecular;
   float cylSpecular;
   float ballSpecular;
   float cutOffAngle;
   float brightness;

  private:
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;
    GLint m_LightPosition;
    GLint m_cutOff;
    GLint m_spotLight;

    Object *m_ball;
    Object *m_front;
    Object *m_back;
    Object *m_left;
    Object *m_right;
    Object *m_bottom;
    Object *m_cylinder;
    Object *m_cube;
    btBroadphaseInterface *broadphase;
    btDefaultCollisionConfiguration *collisionConfiguration;
    btCollisionDispatcher *dispatcher;
    btSequentialImpulseConstraintSolver *solver;
    btDiscreteDynamicsWorld *dynamicsWorld;
};

#endif /* GRAPHICS_H */
