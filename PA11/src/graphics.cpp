#include "graphics.h"
#include <cmath> //using for absolute value calculations

Graphics::Graphics()
{
	Magick::InitializeMagick(NULL);

	ambientValue = .2;
	cubeSpecular = .5;
	clubSpecular = .5;
	ballSpecular = .5;
	cutOffAngle = 5.0;
	brightness = 0;
	usingClub = false;
	baseClubPower = 1;

        fanSpeed = 0.26;

  cameraOrbitAngle = -1.575f; //will have to change depending on where we want the camera to face at the begining of the course
  turnCameraLeft = false;
  turnCameraRight = false;

  numberOfShots = 0;
  addShot = false;

  levelCleared = false;
  restart = false;
}

Graphics::~Graphics()
{
  delete dynamicsWorld;
  delete solver;
  delete collisionConfiguration;
  delete dispatcher;
  delete broadphase;

  dynamicsWorld = NULL;
  solver = NULL;
  collisionConfiguration = NULL;
  dispatcher = NULL;
  broadphase = NULL;
}

bool Graphics::Initialize(int width, int height)
{
  // Used for the linux OS
  #if !defined(__APPLE__) && !defined(MACOSX)
    // cout << glewGetString(GLEW_VERSION) << endl;
    glewExperimental = GL_TRUE;

    auto status = glewInit();

    // This is here to grab the error that comes from glew init.
    // This error is an GL_INVALID_ENUM that has no effects on the performance
    glGetError();

    //Check for error
    if (status != GLEW_OK)
    {
      std::cerr << "GLEW Error: " << glewGetErrorString(status) << "\n";
      return false;
    }
  #endif

  // For OpenGL 3
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Init Camera
  m_camera = new Camera();
  if(!m_camera->Initialize(width, height))
  {
    printf("Camera Failed to Initialize\n");
    return false;
  }

  /*Bullet*/
  /*Initialize and create physics world*/
  broadphase = new btDbvtBroadphase();
  collisionConfiguration = new btDefaultCollisionConfiguration();
  dispatcher = new btCollisionDispatcher(collisionConfiguration);
  solver = new btSequentialImpulseConstraintSolver();

  dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
  dynamicsWorld->setGravity(btVector3(0,-9.81,0));

  /*Create Objects*/

  /*//Create Board
  // Create the Front
  btTriangleMesh* objTriMeshF = new btTriangleMesh();
  m_front = new Object("../objects/front.obj", "../objects/red.png", objTriMeshF, 1);
  btCollisionShape *frontShape = new btBvhTriangleMeshShape(objTriMeshF, true);
  btDefaultMotionState* frontMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
  btScalar frontMass = 0; //setting mass to 0 makes it static
  btVector3 frontInertia(0, 0, 0);


  frontShape->calculateLocalInertia(frontMass, frontInertia);
  btRigidBody::btRigidBodyConstructionInfo frontRigidBodyCI(frontMass, frontMotionState, frontShape, frontInertia);
  frontRigidBody = new btRigidBody(frontRigidBodyCI);
frontRigidBody->setRestitution (0.5);
  frontRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(frontRigidBody);

  //Create the back
  btTriangleMesh* objTriMeshB = new btTriangleMesh();
  m_back = new Object("../objects/back.obj", "../objects/red.png", objTriMeshB, 1);
  btCollisionShape *backShape = new btBvhTriangleMeshShape(objTriMeshB, true);
  btDefaultMotionState* backMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
  btScalar backMass = 0; //setting mass to 0 makes it static
  btVector3 backInertia(0, 0, 0);

  backShape->calculateLocalInertia(backMass, backInertia);
  btRigidBody::btRigidBodyConstructionInfo backRigidBodyCI(backMass, backMotionState, backShape, backInertia);
  backRigidBody = new btRigidBody(backRigidBodyCI);
backRigidBody->setRestitution (0.5);
  backRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(backRigidBody);
  
  //Create the left
  btTriangleMesh* objTriMeshL = new btTriangleMesh();
  m_left = new Object("../objects/left.obj", "../objects/red.png", objTriMeshL, 1);
  btCollisionShape *leftShape = new btBvhTriangleMeshShape(objTriMeshL, true);
  btDefaultMotionState* leftMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
  btScalar leftMass = 0; //setting mass to 0 makes it static
  btVector3 leftInertia(0, 0, 0);

  leftShape->calculateLocalInertia(leftMass, leftInertia);
  btRigidBody::btRigidBodyConstructionInfo leftRigidBodyCI(leftMass, leftMotionState, leftShape, leftInertia);
  leftRigidBody = new btRigidBody(leftRigidBodyCI);
  leftRigidBody->setRestitution (0.5);
  leftRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(leftRigidBody);

  //Create the right
  btTriangleMesh* objTriMeshR = new btTriangleMesh();
  m_right = new Object("../objects/right.obj", "../objects/red.png", objTriMeshR, 1);
  btCollisionShape *rightShape = new btBvhTriangleMeshShape(objTriMeshR, true);
  btDefaultMotionState* rightMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
  btScalar rightMass = 0; //setting mass to 0 makes it static
  btVector3 rightInertia(0, 0, 0);

  rightShape->calculateLocalInertia(rightMass, rightInertia);
  btRigidBody::btRigidBodyConstructionInfo rightRigidBodyCI(rightMass, rightMotionState, rightShape, rightInertia);
  rightRigidBody = new btRigidBody(rightRigidBodyCI);
rightRigidBody->setRestitution (0.5);
  rightRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(rightRigidBody);


  //Create the bottom
  btTriangleMesh* objTriMeshBot = new btTriangleMesh();
  m_bottom = new Object("../objects/bottom.obj", "../objects/red.png", objTriMeshBot, 0);
  btCollisionShape *bottomShape = new btBoxShape(btVector3(12,0.3,20));
  btDefaultMotionState* bottomMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
  btScalar bottomMass = 0; //setting mass to 0 makes it static
  btVector3 bottomInertia(0, 0, 0);

  bottomShape->calculateLocalInertia(bottomMass, bottomInertia);
  btRigidBody::btRigidBodyConstructionInfo bottomRigidBodyCI(bottomMass, bottomMotionState, 	bottomShape, bottomInertia);
  bottomRigidBody = new btRigidBody(bottomRigidBodyCI);
	bottomRigidBody->setRestitution (0.5);
  bottomRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(bottomRigidBody);*/

  //Create course
  btTriangleMesh* objTriMeshCourse = new btTriangleMesh();
  m_course = new Object("../objects/testpista.obj", "../objects/red.png", objTriMeshCourse, 1);
  btCollisionShape *courseShape = new btBvhTriangleMeshShape(objTriMeshCourse, true);
  btDefaultMotionState* courseMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 1, 0, 1), btVector3(0, 0, 0)));
  btScalar courseMass = 0; //setting mass to 0 makes it static
  btVector3 courseInertia(0, 0, 0);

  courseShape->calculateLocalInertia(courseMass, courseInertia);
  btRigidBody::btRigidBodyConstructionInfo courseRigidBodyCI(courseMass, courseMotionState, courseShape, courseInertia);
  courseRigidBody = new btRigidBody(courseRigidBodyCI);
courseRigidBody->setRestitution (0.5);
  courseRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(courseRigidBody);

  //Create windmill base
  btTriangleMesh* objTriMeshWindmill = new btTriangleMesh();
  m_windmill = new Object("../objects/windmill.obj", "../objects/granite.jpg", objTriMeshWindmill, 1);
  btCollisionShape *windmillShape = new btBvhTriangleMeshShape(objTriMeshWindmill, true);
  btDefaultMotionState* windmillMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 11, 37)));
  btScalar windmillMass = 0; //setting mass to 0 makes it static
  btVector3 windmillInertia(0, 0, 0);

  windmillShape->calculateLocalInertia(windmillMass, windmillInertia);
  btRigidBody::btRigidBodyConstructionInfo windmillRigidBodyCI(windmillMass, windmillMotionState, windmillShape, windmillInertia);
  windmillRigidBody = new btRigidBody(windmillRigidBodyCI);
windmillRigidBody->setRestitution (0.5);
  windmillRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(windmillRigidBody);

  // Create the fan
  btTriangleMesh* fanTriMesh = new btTriangleMesh();
  m_fan = new Object("../objects/fan.obj", "../objects/wood.jpg", fanTriMesh, 1);
  btCollisionShape *fanShape = new btBvhTriangleMeshShape(fanTriMesh, true);
  btDefaultMotionState* fanMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 10.5, 37)));
  btVector3 fanInertia(0,0,0);
  float fanMass = 5;

  fanShape->calculateLocalInertia(fanMass, fanInertia);
  btRigidBody::btRigidBodyConstructionInfo fanRigidBodyCI(fanMass, fanMotionState, fanShape, fanInertia);
  fanRigidBody = new btRigidBody(fanRigidBodyCI);
  fanRigidBody->setRestitution (0.5);
  fanRigidBody->setActivationState(DISABLE_DEACTIVATION);
  fanRigidBody->setLinearFactor(btVector3(0,0,0));
  dynamicsWorld->addRigidBody(fanRigidBody);

  //Create the ball
  btTriangleMesh* objTriMesh = new btTriangleMesh();
  m_ball = new Object("../objects/ball.obj", "../objects/metalball.png", objTriMesh, 0);
  //should be somewhere between .40 and .45 at the moment
  btCollisionShape *ballShape = new btSphereShape(.45); 
  btDefaultMotionState* ballMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 2, 80)));
  btScalar ballMass = 1;
  btVector3 ballInertia(0, 0, 0);

  ballShape->calculateLocalInertia(ballMass, ballInertia);
  btRigidBody::btRigidBodyConstructionInfo ballRigidBodyCI(ballMass, ballMotionState, ballShape, ballInertia);
  ballRigidBody = new btRigidBody(ballRigidBodyCI);
  ballRigidBody->setRestitution (0.5);
  ballRigidBody->setActivationState(DISABLE_DEACTIVATION);

  dynamicsWorld->addRigidBody(ballRigidBody);
	
	// Create the club
	double clubMass = 5;
  btTriangleMesh* clubTriMesh = new btTriangleMesh();
  m_club = new Object("../objects/cube.obj", "../objects/wood.jpg", clubTriMesh, 1);
  btCollisionShape *clubShape = new btBvhTriangleMeshShape(clubTriMesh, true);
  btDefaultMotionState* clubMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(5, 2, -13.8)));
	btVector3 clubInertia(0,0,0);

  clubShape->calculateLocalInertia(clubMass, clubInertia);
  btRigidBody::btRigidBodyConstructionInfo clubRigidBodyCI(clubMass, clubMotionState, clubShape, clubInertia);
  clubRigidBody = new btRigidBody(clubRigidBodyCI);
  clubRigidBody->setRestitution (0.5);
  clubRigidBody->setActivationState(DISABLE_DEACTIVATION);
	clubRigidBody->setLinearFactor(btVector3(0,0,0));
  dynamicsWorld->addRigidBody(clubRigidBody);

  // Create the cube
  btTriangleMesh* objTriMesh4 = new btTriangleMesh();
  m_cube = new Object("../objects/cube.obj", "../objects/portalCube.jpeg", objTriMesh4, 0);
  btCollisionShape *cubeShape = new btBoxShape(btVector3(1, 1, 1));
  //btCollisionShape *cubeShape = new btBvhTriangleMeshShape(objTriMesh4, true);
  btDefaultMotionState* cubeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 1, -5)));
  btScalar cubeMass = 1; 
  btVector3 cubeInertia(0, 0, 0);

  cubeShape->calculateLocalInertia(cubeMass, cubeInertia);
  btRigidBody::btRigidBodyConstructionInfo cubeRigidBodyCI(cubeMass, cubeMotionState, cubeShape, cubeInertia);
  cubeRigidBody = new btRigidBody(cubeRigidBodyCI);
  cubeRigidBody->setActivationState(DISABLE_DEACTIVATION);

  dynamicsWorld->addRigidBody(cubeRigidBody);

  // Set up the shader
  lightingType = 0;
  newLightingType = 0;

  m_shader = new Shader();
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }

  // Add the vertex shader
  if(!m_shader->AddShader(GL_VERTEX_SHADER, lightingType))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

  // Add the fragment shader
  if(!m_shader->AddShader(GL_FRAGMENT_SHADER, lightingType))
  {
    printf("Fragment Shader failed to Initialize\n");
    return false;
  }

  // Connect the program
  if(!m_shader->Finalize())
  {
    printf("Program to Finalize\n");
    return false;
  }

  // Locate the projection matrix in the shader
  m_projectionMatrix = m_shader->GetUniformLocation("projectionMatrix");

  if (m_projectionMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_projectionMatrix not found\n");
    return false;
  }

  // Locate the view matrix in the shader
  m_viewMatrix = m_shader->GetUniformLocation("viewMatrix");
  if (m_viewMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_viewMatrix not found\n");
    return false;
  }

  // Locate the model matrix in the shader
  m_modelMatrix = m_shader->GetUniformLocation("modelMatrix");
  if (m_modelMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_modelMatrix not found\n");
    return false;
  }

  m_LightPosition = m_shader->GetUniformLocation("LightPosition");
  if (m_LightPosition == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_LightPosition not found\n");
    return false;
  }

  m_cutOff = m_shader->GetUniformLocation("cutOff");
  if (m_cutOff == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_cutOff not found\n");
    return false;
  }

  m_spotLight = m_shader->GetUniformLocation("SpotLight");
  if (m_spotLight == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_spotLight not found\n");
    return false;
  }

  brightness = m_shader->GetUniformLocation("Brightness");
  if (brightness == INVALID_UNIFORM_LOCATION) 
  {
    printf("brightness not found\n");
    return false;
  }

  //enable depth testing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  return true;
}

void Graphics::Update(unsigned int dt)
{
  if(lightingType != newLightingType)
  {
    UpdateShader(newLightingType);
  }

  ballPosition = ballRigidBody->getCenterOfMassPosition();

  /*code for camera*/
  if(turnCameraLeft == true)
  {
    cameraOrbitAngle -= ((M_PI)*dt/(1000));
    turnCameraLeft = false;
  }
  if(turnCameraRight == true)
  {
    cameraOrbitAngle += ((M_PI)*dt/(1000));
    turnCameraRight = false;
  }

  //cameraOrbitAngle += ((M_PI)*dt/(5000));
  //cout << cameraOrbitAngle << endl;
  m_camera->UpdateView(glm::vec3(ballPosition.x()+(10*cos(cameraOrbitAngle)), ballPosition.y()+5, ballPosition.z()+(10*sin(cameraOrbitAngle))), glm::vec3(ballPosition.x(), ballPosition.y(), ballPosition.z()));

  btTransform trans;
  btScalar m[16];
  dynamicsWorld->stepSimulation(dt, 10);

  courseRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_course->model = glm::make_mat4(m);

  windmillRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_windmill->model = glm::make_mat4(m);

  //reset ball if it goes out of bounds
  if(ballPosition.y()<=-10)
  {
    trans.setOrigin(btVector3(previousBallPosition.x(), previousBallPosition.y(), previousBallPosition.z()));

    ballRigidBody->setWorldTransform(trans);
    ballRigidBody->setLinearVelocity(btVector3(0.0, 0.0, 0.0));
    ballRigidBody->setAngularVelocity(btVector3(0.0, 0.0, 0.0));
    ballIsMoving = false;
  }

  //if ball is in the hole display scorecard/go to win state
  if(abs(0-ballPosition.x())<=2.0f && ballPosition.y() <= -2.0f && abs(80-ballPosition.z())<=2.0f &&
     levelCleared == false)
  {
    cout << "Course Cleared!" << endl;
    //will probably reformat this eventually to make it look nicer
    cout << "Hole	1	2	3	4	5	6	7	8	9..." << endl;
    cout << "Par	2	?	?	?	?	?	?	?	?..." << endl;
    //if we end up doing multiple holes we could store shots per hole in an array
    cout << "Shots" << "\t" << numberOfShots << "	0	0	0	0	0	0	0	0..." << endl;
    cout << "Press R to Restart" << endl;
    levelCleared = true;
  }

  //if level cleared make ball stay near hole entrance (will prevent ball/camera from free falling)
  if(levelCleared == true)
  {
    trans.setOrigin(btVector3(0.0f, -2.0f, 80.0f));
    ballRigidBody->setWorldTransform(trans);
  }

  if(restart == true)
  {
    levelCleared = false;
    trans.setOrigin(btVector3(0, 2, 0));
    ballRigidBody->setWorldTransform(trans);
    ballRigidBody->getMotionState()->getWorldTransform(trans);
    trans.getOpenGLMatrix(m);
    m_ball->model = glm::make_mat4(m);
    ballRigidBody->setLinearVelocity(btVector3(0.0, 0.0, 0.0));
    ballRigidBody->setAngularVelocity(btVector3(0.0, 0.0, 0.0));
    ballIsMoving = false;
    numberOfShots = 0;
    restart = false;
  }

  ballRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_ball->model = glm::make_mat4(m);

  //cout << fanSpeed << endl;
  fanRigidBody->setAngularVelocity(btVector3(0,0,fanSpeed));
  fanRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_fan->model = glm::make_mat4(m);

  /***Code for ball drag***/
  btVector3 ballVelocity = ballRigidBody->getLinearVelocity();
  //cout << ballVelocity.x() << "\t" << ballVelocity.y() << "\t" << ballVelocity.z() << endl;

  if(abs(ballVelocity.x()) >= 0.015 ||
     abs(ballVelocity.y()) >= 0.015 ||
     abs(ballVelocity.z()) >= 0.015 )
  {
    ballIsMoving = true;
    //cout << "Ball is moving" << endl;
  }
  else
  {
    ballIsMoving = false;
    //cout << "Ball is not moving" << endl;
  }

  if(ballIsMoving)
  {
    ballRigidBody->setLinearVelocity(btVector3(ballVelocity.x()/1.005, 
                                               ballVelocity.y()/1.005, 
                                               ballVelocity.z()/1.005));
  }
  if(!ballIsMoving && 
    //this will let the ball bounce off walls without stopping (may need some tuning)
    (abs(previousBallVelocity.x() - ballVelocity.x()) <= .001 &&
     abs(previousBallVelocity.y() - ballVelocity.y()) <= .001 &&
     abs(previousBallVelocity.z() - ballVelocity.z()) <= .001 ))
  {
    ballRigidBody->setLinearVelocity(btVector3(0.0, 0.0, 0.0));
    ballRigidBody->setAngularVelocity(btVector3(0.0, 0.0, 0.0));
  }
  previousBallVelocity = ballVelocity;

    /***Code for club movement***/

	//cout << clubRigidBody->getOrientation().getAngle() << endl;
	static bool clubUsed = false;
	btQuaternion quat = clubRigidBody->getOrientation();
  clubPosition = clubRigidBody->getCenterOfMassPosition();
	float xAxis, yAxis, zAxis;
	clubRigidBody->getOrientation().getEulerZYX(zAxis,yAxis,xAxis);
	//cout << "x" << xAxis << " y" << yAxis << " z" << zAxis << endl;
	static int constant;

	if(xAxis > 3.1 && !clubUsed)
	{
		//cout << "here" << endl;
		constant = -1;
	}
	else if(xAxis == 0 && !clubUsed)
		constant = 1;
	if(usingClub)
	{
		clubUsed = true;
		//cout << "club in use" << endl;
		if(true)
		{
			float x = constant * -cos(yAxis)*0.05;
			float z = sin(yAxis)*0.05;
			clubRigidBody->setAngularVelocity(btVector3(x,0,z));
			clubPowerMuliplier += .02;
		}
		else
		{
			clubRigidBody->setAngularVelocity(btVector3(0,0,0));
		}
	}
  else if(usingClub == false && !((xAxis >= -0.2 && xAxis <= 0.2 || xAxis >= 3.0) && (xAxis >= -0.2 && zAxis <= 0.2 || zAxis >= 3.0)))
  {
    //velocity is determined by the base power times the multiplier (+.5 to negate possible negative value)
    float z = baseClubPower*clubPowerMuliplier + 0.5;
    //sanity check to make sure z is not negative
    if(z < 0)
    {
      z *= -1.0;
    }
    //cout << z << endl;
    clubRigidBody->setAngularVelocity(btVector3(constant * cos(yAxis)*z,0,-sin(yAxis)*z));
    addShot = true;
  }
  //once it has reached its original position, its velocity is zero
  else if(usingClub == false)
  {
		clubUsed = false;
    if(addShot == true)
    {
      numberOfShots++;
      cout << "Shots taken: " << numberOfShots << endl;
      addShot = false;
    }
		if(ballIsMoving)
		{
      trans.setRotation(btQuaternion(0,0,0,1));
    	clubRigidBody->setWorldTransform(trans);
		}
		clubPowerMuliplier = 0;
		//cout << "club not in use" << endl;
    //cout << plungerPosition.z()  << endl;
    clubRigidBody->setAngularVelocity(btVector3(0,0,0));
  }
  //cubeRigidBody->getMotionState()->getWorldTransform(trans);
  //trans.getOrigin() += btVector3(0,0,0.1);
  /***Moves club to ball when ball is stationary and update previous position of ball***/
  if(!ballIsMoving)
  {
		int yTemp = yAxis;
		if(xAxis > 3)
			yTemp = -yTemp;
    trans.setOrigin(btVector3(ballPosition.x() + 3 * sin(yAxis), ballPosition.y() + 3, ballPosition.z() + constant * 3 * cos(yAxis)));
    trans.setRotation(clubRigidBody->getOrientation());

    clubRigidBody->setWorldTransform(trans);

    previousBallPosition = ballPosition;
  }
  clubRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_club->model = glm::make_mat4(m);

  //cout << ballPosition.x() << "\t" << ballPosition.y() << "\t" << ballPosition.z() << endl;

  //cubeRigidBody->applyCentralImpulse(btVector3(.4,0,0.4));
  cubeRigidBody->getMotionState()->getWorldTransform(trans);

  trans.getOpenGLMatrix(m);
  m_cube->model = glm::make_mat4(m);
  //std::cout<<trans.getOrigin().getX() << " " << trans.getOrigin().getY()<< " " << trans.getOrigin().getZ() << std::endl;
}

void Graphics::Render()
{
  //clear the screen
  glClearColor(0.0, 0.0, 0.2, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Start the correct program
  m_shader->Enable();

  // Send in the projection and view to the shader
  glUniformMatrix4fv(m_projectionMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetProjection())); 
  glUniformMatrix4fv(m_viewMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetView())); 

  //Lighting
  glUniform4fv(m_shader->GetUniformLocation("LightPosition"), 1, glm::value_ptr(glm::vec4(100.0, 100.0, 100.0, 1)));
  glUniform4fv(m_shader->GetUniformLocation("AmbientProduct"),1,glm::value_ptr(glm::vec4(ambientValue,ambientValue,ambientValue, 1))); 
  glUniform1f(m_shader->GetUniformLocation("cutOff"), glm::tan( glm::radians( cutOffAngle ) ) );

  glm::vec4 tmpVec = m_ball->GetModel() * glm::vec4( 0.0, 0.0, 0.0, 1.0 );
  glUniform3fv( m_spotLight,1, glm::value_ptr(glm::vec3(tmpVec.x, tmpVec.y, tmpVec.z)));

  glUniform1f(m_shader->GetUniformLocation("Brightness"), 5.0+brightness);
  
  // Render the objects
  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_ball->GetModel()));
  m_ball->Render(m_shader, ballSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_club->GetModel()));
  m_club->Render(m_shader, clubSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_cube->GetModel()));
  m_cube->Render(m_shader, cubeSpecular);

  /*glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_front->GetModel()));
  m_front->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_back->GetModel()));
  m_back->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_left->GetModel()));
  m_left->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_right->GetModel()));
  m_right->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_bottom->GetModel()));
  m_bottom->Render(m_shader, .5);*/

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_course->GetModel()));
  m_course->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_windmill->GetModel()));
  m_windmill->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_fan->GetModel()));
  m_fan->Render(m_shader, .5);

  // Get any errors from OpenGL
  auto error = glGetError();
  if ( error != GL_NO_ERROR )
  {
    string val = ErrorString( error );
    std::cout<< "Error initializing OpenGL! " << error << ", " << val << std::endl;
  }
}

std::string Graphics::ErrorString(GLenum error)
{
  if(error == GL_INVALID_ENUM)
  {
    return "GL_INVALID_ENUM: An unacceptable value is specified for an enumerated argument.";
  }

  else if(error == GL_INVALID_VALUE)
  {
    return "GL_INVALID_VALUE: A numeric argument is out of range.";
  }

  else if(error == GL_INVALID_OPERATION)
  {
    return "GL_INVALID_OPERATION: The specified operation is not allowed in the current state.";
  }

  else if(error == GL_INVALID_FRAMEBUFFER_OPERATION)
  {
    return "GL_INVALID_FRAMEBUFFER_OPERATION: The framebuffer object is not complete.";
  }

  else if(error == GL_OUT_OF_MEMORY)
  {
    return "GL_OUT_OF_MEMORY: There is not enough memory left to execute the command.";
  }
  else
  {
    return "None";
  }
}

void Graphics::UpdateShader(int newLightingType)
{
  m_shader->Initialize();
  m_shader->AddShader(GL_VERTEX_SHADER, newLightingType);
  m_shader->AddShader(GL_FRAGMENT_SHADER, newLightingType);		      
  m_shader->Finalize();
  m_shader->Enable();

  lightingType = newLightingType;

  m_modelMatrix = m_shader->GetUniformLocation("modelMatrix");
  m_viewMatrix = m_shader->GetUniformLocation("viewMatrix");
  m_projectionMatrix = m_shader->GetUniformLocation("projectionMatrix");
  m_spotLight = m_shader->GetUniformLocation("SpotLight");
}
