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
    string playerName;

    btRigidBody *ballRigidBody;
    btRigidBody *boardRigidBody;
    btRigidBody *cheek1RigidBody;
    btRigidBody *cheek2RigidBody;
    btRigidBody *eye1RigidBody;
    btRigidBody *eye2RigidBody;

    btRigidBody *cubeRigidBody;
    btRigidBody *backRigidBody;
    btRigidBody *frontRigidBody;
    btRigidBody *leftRigidBody;
    btRigidBody *rightRigidBody;
    btRigidBody *bottomRigidBody;
    btRigidBody *splashBoardRigidBody;
    btRigidBody *curveRigidBody;
    btRigidBody *dividerRigidBody;
    btRigidBody *trianglesRigidBody;
    btRigidBody *paddle1RigidBody;
    btRigidBody *paddle2RigidBody;
    btRigidBody *plungerRigidBody;
    btRigidBody *leftDividerRigidBody;
    btRigidBody *rightDividerRigidBody;
    btRigidBody *tailRigidBody;
    btRigidBody *splashboardRigidBody;

   void UpdateShader(int newLightingType);
   void ResetGame();
   void UpdateScore();

   int lightingType;
   int newLightingType;
   float ambientValue;
   float bumperSpecular;
   float flipperSpecular;
   float ballSpecular;
   float cutOffAngle;
   float brightness;

		float paddle1Rot;
		float paddle2Rot;

  btVector3 ballPosition;

  btVector3 plungerPosition;
  float basePlungerPower;
  float plungerPowerMuliplier;
  bool usingPlunger;
  bool setMultiplier;

  int ballsLeft;
  bool endOfGame;
  bool reset;

	bool topDownView;
	bool frontView;
	bool backView;
  private:
    std::string ErrorString(GLenum error);
    int score;
    bool collides;
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
    Object *m_topCurve;
    Object *m_splashBoard;
    Object *m_divider;
    Object *m_triangles;
    Object *m_paddle1;
    Object *m_paddle2;
    Object *m_cheek1;
    Object *m_cheek2;
    Object *m_eye1;
    Object *m_eye2;
    Object *m_cube;
    Object *m_plunger;
    Object *m_rightDivider;
    Object *m_leftDivider;
    Object *m_tail;
    Object *m_splashboard;

    btBroadphaseInterface *broadphase;
    btDefaultCollisionConfiguration *collisionConfiguration;
    btCollisionDispatcher *dispatcher;
    btSequentialImpulseConstraintSolver *solver;
    btDiscreteDynamicsWorld *dynamicsWorld;
};

#endif /* GRAPHICS_H */
