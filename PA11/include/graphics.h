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
    //btRigidBody *cylinderRigidBody;
    //btRigidBody *cubeRigidBody;

    btRigidBody *courseRigidBody; //second level
    btRigidBody *course2RigidBody; //third level
    btRigidBody *course3RigidBody; //first level

    btRigidBody *windmillRigidBody;
    btRigidBody *windmill2RigidBody;
    btRigidBody *fanRigidBody;
    btRigidBody *fan2RigidBody;
    btRigidBody *fan3RigidBody;
    btRigidBody *gateRigidBody;
    btRigidBody *gate2RigidBody;

    btRigidBody *clubRigidBody;

    btRigidBody *flagRigidBody;

    void UpdateShader(int newLightingType);
    void OutputScorecard();

    int lightingType;
    int newLightingType;
    float ambientValue;
    float windmillSpecular;
    float clubSpecular;
    float ballSpecular;
    float gateSpecular;
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

     int numberOfPistas = 3;
    /*2, 4, 7*/
    int par[3];
    /*0, 0, 0*/
    int score[3];
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
 
    Object *m_course;  //second level
    Object *m_course2;  //third level
    Object *m_course3;  //first level

    Object *m_windmill;
    Object *m_windmill2;
    Object *m_windmill3;
    Object *m_fan;
    Object *m_fan2;
    Object *m_gate;
    Object *m_gate2;

    //Object *m_cylinder;
    //Object *m_cube;
    Object *m_club;

    Object *m_flag;

    btBroadphaseInterface *broadphase;
    btDefaultCollisionConfiguration *collisionConfiguration;
    btCollisionDispatcher *dispatcher;
    btSequentialImpulseConstraintSolver *solver;
    btDiscreteDynamicsWorld *dynamicsWorld;
};

#endif /* GRAPHICS_H */
