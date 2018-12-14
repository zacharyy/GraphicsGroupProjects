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
    //btRigidBody *boardRigidBody;
    btRigidBody *cylinderRigidBody;
    btRigidBody *cubeRigidBody;
    /*btRigidBody *backRigidBody;
    btRigidBody *frontRigidBody;
    btRigidBody *leftRigidBody;
    btRigidBody *rightRigidBody;
    btRigidBody *bottomRigidBody;*/

    btRigidBody *courseRigidBody;
    btRigidBody *course2RigidBody;
    btRigidBody *windmillRigidBody;
    btRigidBody *windmill2RigidBody;
    btRigidBody *fanRigidBody;
    btRigidBody *fan2RigidBody;
    btRigidBody *gateRigidBody;
    btRigidBody *gate2RigidBody;

    btRigidBody *clubRigidBody;

    void UpdateShader(int newLightingType);
    void OutputScorecard();

    int lightingType;
    int newLightingType;
    float ambientValue;
    float cubeSpecular;
    float clubSpecular;
    float ballSpecular;
    float cutOffAngle;
    float brightness;

    //variables for club
    btVector3 clubPosition;
    btVector3 ballPosition;
    btVector3 previousBallVelocity;
    btVector3 previousBallPosition;
    bool ballIsMoving;
    float baseClubPower;
    float clubPowerMuliplier;
    bool usingClub;
    bool setMultiplier;

    float fanSpeed;

    float cameraOrbitAngle;
    bool turnCameraLeft;
    bool turnCameraRight;

    int numberOfShots;
    bool addShot;

    bool levelCleared;

    int levelSelectionSwitch;
    int currentLevel;

     int numberOfPistas = 2;
    /*2, 4, 7*/
    int par[2];
    /*0, 0, 0*/
    int score[2];
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
    /*Object *m_front;
    Object *m_back;
    Object *m_left;
    Object *m_right;
    Object *m_bottom;*/
 
    Object *m_course;
    Object *m_course2;
    Object *m_windmill;
    Object *m_windmill2;
    Object *m_fan;
    Object *m_fan2;
    Object *m_gate;
    Object *m_gate2;

    Object *m_cylinder;
    Object *m_cube;
    Object *m_club;
    btBroadphaseInterface *broadphase;
    btDefaultCollisionConfiguration *collisionConfiguration;
    btCollisionDispatcher *dispatcher;
    btSequentialImpulseConstraintSolver *solver;
    btDiscreteDynamicsWorld *dynamicsWorld;
};

#endif /* GRAPHICS_H */
