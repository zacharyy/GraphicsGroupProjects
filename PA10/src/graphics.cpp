#include "graphics.h"

Graphics::Graphics()
{
	Magick::InitializeMagick(NULL);

	ambientValue = .2;
	bumperSpecular = .5;
	flipperSpecular = .5;
	ballSpecular = .5;
	cutOffAngle = 5.0;
	brightness = 0;
	paddle1Rot = 3;
	paddle2Rot = 3;
	score = 0;
	collides = false;
	ballsLeft = 2;
	cout << "Balls left: 3" << endl;
	endOfGame = false;
	reset = false;

	frontView = true;
	backView = false;
	topDownView = false;
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
  dynamicsWorld->setGravity(btVector3(0,-9.81,-0.1));

  /*Create Objects*/

  //Create Board
  // Create the Front
  btTriangleMesh* objTriMeshF = new btTriangleMesh();
  m_front = new Object("../objects/front.obj", "../objects/wood.jpg", objTriMeshF, 1);
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
  m_back = new Object("../objects/back.obj", "../objects/wood.jpg", objTriMeshB, 1);
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
  m_left = new Object("../objects/left.obj", "../objects/wood.jpg", objTriMeshL, 1);
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
  m_right = new Object("../objects/right.obj", "../objects/wood.jpg", objTriMeshR, 1);
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
  m_bottom = new Object("../objects/bottom.obj", "../objects/board.jpg", objTriMeshBot, 0);
  btCollisionShape *bottomShape = new btBoxShape(btVector3(12,0.3,20));
  btDefaultMotionState* bottomMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0)));
  btScalar bottomMass = 0; //setting mass to 0 makes it static
  btVector3 bottomInertia(0, 0, 0);

  bottomShape->calculateLocalInertia(bottomMass, bottomInertia);
  btRigidBody::btRigidBodyConstructionInfo bottomRigidBodyCI(bottomMass, bottomMotionState, 	bottomShape, bottomInertia);
  bottomRigidBody = new btRigidBody(bottomRigidBodyCI);
	bottomRigidBody->setRestitution (0.5);
  bottomRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(bottomRigidBody);

  //Create the top curve
  btTriangleMesh* objTriMeshCurve = new btTriangleMesh();
  m_topCurve = new Object("../objects/topcurve.obj", "../objects/wood.jpg", objTriMeshCurve, 1);
  btCollisionShape *curveShape = new btBvhTriangleMeshShape(objTriMeshCurve, true);
  btDefaultMotionState* curveMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0)));
  btScalar curveMass = 0; //setting mass to 0 makes it static
  btVector3 curveInertia(0, 0, 0);

  curveShape->calculateLocalInertia(curveMass, curveInertia);
  btRigidBody::btRigidBodyConstructionInfo curveRigidBodyCI(curveMass, curveMotionState, curveShape, curveInertia);
  curveRigidBody = new btRigidBody(curveRigidBodyCI);
  curveRigidBody->setRestitution (0.5);
  curveRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(curveRigidBody);

  //Create the SplashBoard
  btTriangleMesh* objTriMeshSplashBoard = new btTriangleMesh();
  m_splashBoard = new Object("../objects/splashboard.obj", "../objects/splashboard.jpg", objTriMeshSplashBoard, 1);
  btCollisionShape *splashBoardShape = new btBvhTriangleMeshShape(objTriMeshSplashBoard, true);
  btDefaultMotionState* splashBoardMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0)));
  btScalar splashBoardMass = 0; //setting mass to 0 makes it static
  btVector3 splashBoardInertia(0, 0, 0);

  splashBoardShape->calculateLocalInertia(splashBoardMass, splashBoardInertia);
  btRigidBody::btRigidBodyConstructionInfo splashBoardRigidBodyCI(splashBoardMass, splashBoardMotionState, splashBoardShape, splashBoardInertia);
  splashBoardRigidBody = new btRigidBody(splashBoardRigidBodyCI);
  splashBoardRigidBody->setRestitution (0.5);
  splashBoardRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(splashBoardRigidBody);

  //Create the divider
  btTriangleMesh* objTriMeshDivider = new btTriangleMesh();
  m_divider = new Object("../objects/divider.obj", "../objects/wood.jpg", objTriMeshDivider, 1);
  btCollisionShape *dividerShape = new btBvhTriangleMeshShape(objTriMeshDivider, true);
  btDefaultMotionState* dividerMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0)));
  btScalar dividerMass = 0; //setting mass to 0 makes it static
  btVector3 dividerInertia(0, 0, 0);

  dividerShape->calculateLocalInertia(dividerMass, dividerInertia);
  btRigidBody::btRigidBodyConstructionInfo dividerRigidBodyCI(dividerMass, dividerMotionState, dividerShape, dividerInertia);
  dividerRigidBody = new btRigidBody(dividerRigidBodyCI);
  dividerRigidBody->setRestitution (0.5);
  dividerRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(dividerRigidBody);

  //Create the triangles
  btTriangleMesh* objTriMeshTriangles = new btTriangleMesh();
  m_triangles = new Object("../objects/triangles.obj", "../objects/wood.jpg", objTriMeshTriangles, 1);
  btCollisionShape *trianglesShape = new btBvhTriangleMeshShape(objTriMeshTriangles, true);
  btDefaultMotionState* trianglesMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0)));
  btScalar trianglesMass = 0; //setting mass to 0 makes it static
  btVector3 trianglesInertia(0, 0, 0);

  trianglesShape->calculateLocalInertia(trianglesMass, dividerInertia);
  btRigidBody::btRigidBodyConstructionInfo trianglesRigidBodyCI(trianglesMass, trianglesMotionState, trianglesShape, trianglesInertia);
  trianglesRigidBody = new btRigidBody(trianglesRigidBodyCI);
  trianglesRigidBody->setRestitution (0.5);
  trianglesRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(trianglesRigidBody);

	// Create left divider
  btTriangleMesh* leftDividerMesh = new btTriangleMesh();
  m_leftDivider = new Object("../objects/leftdivider.obj", "../objects/wood.jpg", leftDividerMesh, 1);
  btCollisionShape *leftDividerShape = new btBvhTriangleMeshShape(leftDividerMesh, true);
  btDefaultMotionState* leftDividerMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0.5)));

  leftDividerShape->calculateLocalInertia(trianglesMass, dividerInertia);
  btRigidBody::btRigidBodyConstructionInfo leftDividerRigidBodyCI(trianglesMass, leftDividerMotionState, leftDividerShape, trianglesInertia);
  leftDividerRigidBody = new btRigidBody(leftDividerRigidBodyCI);
  leftDividerRigidBody->setRestitution (0.5);
  leftDividerRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(leftDividerRigidBody);

	// Create right divider
  btTriangleMesh* rightDividerMesh = new btTriangleMesh();
  m_rightDivider = new Object("../objects/rightdivider.obj", "../objects/wood.jpg", rightDividerMesh, 1);
  btCollisionShape *rightDividerShape = new btBvhTriangleMeshShape(rightDividerMesh, true);
  btDefaultMotionState* rightDividerMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0.5)));

  rightDividerShape->calculateLocalInertia(trianglesMass, dividerInertia);
  btRigidBody::btRigidBodyConstructionInfo rightDividerRigidBodyCI(trianglesMass, rightDividerMotionState, rightDividerShape, trianglesInertia);
  rightDividerRigidBody = new btRigidBody(rightDividerRigidBodyCI);
  rightDividerRigidBody->setRestitution (0.5);
  rightDividerRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(rightDividerRigidBody);

	// Create tail?
  btTriangleMesh* tailDividerMesh = new btTriangleMesh();
  m_tail = new Object("../objects/tail.obj", "../objects/wood.jpg", tailDividerMesh, 1);
  btCollisionShape *tailShape = new btBvhTriangleMeshShape(tailDividerMesh, true);
  btDefaultMotionState* tailMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));

  tailShape->calculateLocalInertia(trianglesMass, dividerInertia);
  btRigidBody::btRigidBodyConstructionInfo tailRigidBodyCI(trianglesMass, tailMotionState, tailShape, trianglesInertia);
  tailRigidBody = new btRigidBody(tailRigidBodyCI);
  tailRigidBody->setRestitution (0.5);
  tailRigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(tailRigidBody);

  // Create the cylinder bumper cheek1
  btTriangleMesh* objTriMesh3 = new btTriangleMesh();
  m_cheek1 = new Object("../objects/cheek.obj", "../objects/cheek.jpg", objTriMesh3, 0);
  btCollisionShape *cylinderShape = new btCylinderShape(btVector3(1.5, 1.5, 1.5));
  //btCollisionShape *cylinderShape = new btBvhTriangleMeshShape(objTriMesh3, true);
  btDefaultMotionState* cylinderMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(7, 1, 2)));
  btScalar cylinderMass = 0; //setting mass to 0 makes it static
  btVector3 cylinderInertia(0, 0, 0);

  cylinderShape->calculateLocalInertia(cylinderMass, cylinderInertia);
  btRigidBody::btRigidBodyConstructionInfo cylinderRigidBodyCI(cylinderMass, cylinderMotionState, cylinderShape, cylinderInertia);
  cheek1RigidBody = new btRigidBody(cylinderRigidBodyCI);
  cheek1RigidBody->setRestitution (0.8);
  cheek1RigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(cheek1RigidBody);

  // Create the cylinder bumper cheek2
  btTriangleMesh* objTriMesh5 = new btTriangleMesh();
  m_cheek2 = new Object("../objects/cheek.obj", "../objects/cheek.jpg", objTriMesh5, 0);
  btCollisionShape *cylinderShape2 = new btCylinderShape(btVector3(1.5, 1.5, 1.5));
  //btCollisionShape *cylinderShape = new btBvhTriangleMeshShape(objTriMesh5, true);
  btDefaultMotionState* cylinderMotionState2 = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(-4.5, 1, 2)));
  btScalar cylinderMass2 = 0; //setting mass to 0 makes it static
  btVector3 cylinderInertia2(0, 0, 0);

  cylinderShape2->calculateLocalInertia(cylinderMass2, cylinderInertia2);
  btRigidBody::btRigidBodyConstructionInfo cylinderRigidBodyCI2(cylinderMass2, cylinderMotionState2, cylinderShape2, cylinderInertia2);
  cheek2RigidBody = new btRigidBody(cylinderRigidBodyCI2);
  cheek2RigidBody->setRestitution (0.8);
  cheek2RigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(cheek2RigidBody);

  // Create the cylinder bumper eye1
  btTriangleMesh* objTriMesh6 = new btTriangleMesh();
  m_eye1 = new Object("../objects/eye.obj", "../objects/eye.jpg", objTriMesh6, 0);
  btCollisionShape *cylinderShape3 = new btCylinderShape(btVector3(1, 1.5, 1));
  //btCollisionShape *cylinderShape = new btBvhTriangleMeshShape(objTriMesh6, true);
  btDefaultMotionState* cylinderMotionState3 = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(5.3, 1, 6)));
  btScalar cylinderMass3 = 0; //setting mass to 0 makes it static
  btVector3 cylinderInertia3(0, 0, 0);

  cylinderShape3->calculateLocalInertia(cylinderMass3, cylinderInertia3);
  btRigidBody::btRigidBodyConstructionInfo cylinderRigidBodyCI3(cylinderMass3, cylinderMotionState3, cylinderShape3, cylinderInertia3);
  eye1RigidBody = new btRigidBody(cylinderRigidBodyCI3);
  eye1RigidBody->setRestitution (0.8);
  eye1RigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(eye1RigidBody);

  // Create the cylinder bumper eye2
  btTriangleMesh* objTriMesh7 = new btTriangleMesh();
  m_eye2 = new Object("../objects/eye.obj", "../objects/eye.jpg", objTriMesh7, 0);
  btCollisionShape *cylinderShape4 = new btCylinderShape(btVector3(1, 1.5, 1));
  //btCollisionShape *cylinderShape = new btBvhTriangleMeshShape(objTriMesh7, true);
  btDefaultMotionState* cylinderMotionState4 = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(-2.8, 1, 6)));
  btScalar cylinderMass4 = 0; //setting mass to 0 makes it static
  btVector3 cylinderInertia4(0, 0, 0);

  cylinderShape4->calculateLocalInertia(cylinderMass4, cylinderInertia4);
  btRigidBody::btRigidBodyConstructionInfo cylinderRigidBodyCI4(cylinderMass4, cylinderMotionState4, cylinderShape4, cylinderInertia4);
  eye2RigidBody = new btRigidBody(cylinderRigidBodyCI4);
  eye2RigidBody->setRestitution (0.8);
  eye2RigidBody->setActivationState(DISABLE_DEACTIVATION);
  dynamicsWorld->addRigidBody(eye2RigidBody);

  //Create the ball
  btTriangleMesh* objTriMesh = new btTriangleMesh();
  m_ball = new Object("../objects/ball.obj", "../objects/ball.png", objTriMesh, 0);
  btCollisionShape *ballShape = new btSphereShape(.5); 
  btDefaultMotionState* ballMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(-10, 2, -4)));
  btScalar ballMass = 1;
  btVector3 ballInertia(0, 0, 0);

  ballShape->calculateLocalInertia(ballMass, ballInertia);
  btRigidBody::btRigidBodyConstructionInfo ballRigidBodyCI(ballMass, ballMotionState, ballShape, ballInertia);
  ballRigidBody = new btRigidBody(ballRigidBodyCI);
  ballRigidBody->setRestitution (0.5);
  ballRigidBody->setActivationState(DISABLE_DEACTIVATION);

  dynamicsWorld->addRigidBody(ballRigidBody);

 /* // Create the cube
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
*/
  btScalar paddleMass = 1; 
	// Create paddle 1
  btTriangleMesh* paddle1TriMesh = new btTriangleMesh();
  m_paddle1 = new Object("../objects/leftflipper.obj", "../objects/wood.jpg", paddle1TriMesh, 1);
  btCollisionShape *paddle1Shape = new btBvhTriangleMeshShape(paddle1TriMesh, true);
  btDefaultMotionState* paddle1MotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(5, 1, -13.8)));

  paddle1Shape->calculateLocalInertia(paddleMass, dividerInertia);
  btRigidBody::btRigidBodyConstructionInfo paddle1RigidBodyCI(paddleMass, paddle1MotionState, paddle1Shape, trianglesInertia);
  paddle1RigidBody = new btRigidBody(paddle1RigidBodyCI);
  paddle1RigidBody->setRestitution (0.5);
  paddle1RigidBody->setActivationState(DISABLE_DEACTIVATION);
	paddle1RigidBody->setLinearFactor(btVector3(0,0,0));
  dynamicsWorld->addRigidBody(paddle1RigidBody);
	// Create paddle 2
  btTriangleMesh* paddle2TriMesh = new btTriangleMesh();
  m_paddle2 = new Object("../objects/rightflipper.obj", "../objects/wood.jpg", paddle2TriMesh, 1);
  btCollisionShape *paddle2Shape = new btBvhTriangleMeshShape(paddle2TriMesh, true);
  btDefaultMotionState* paddle2MotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(-1.25, 1, -13.8)));

  paddle2Shape->calculateLocalInertia(paddleMass, trianglesInertia);
  btRigidBody::btRigidBodyConstructionInfo paddle2RigidBodyCI(paddleMass, paddle2MotionState, paddle2Shape, trianglesInertia);
  paddle2RigidBody = new btRigidBody(paddle2RigidBodyCI);
  paddle2RigidBody->setRestitution (0.5);
  paddle2RigidBody->setActivationState(DISABLE_DEACTIVATION);
	paddle2RigidBody->setLinearFactor(btVector3(0,0,0));
  dynamicsWorld->addRigidBody(paddle2RigidBody);

	// Create plunger
  btTriangleMesh* plungerTriMesh = new btTriangleMesh();
  m_plunger = new Object("../objects/plunger.obj", "../objects/wood.jpg", plungerTriMesh, 1);
  btCollisionShape *plungerShape = new btBvhTriangleMeshShape(plungerTriMesh, true);
  btDefaultMotionState* plungerMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 180, 0, 1), btVector3(0, 0, 0)));
  btScalar plungerMass = 1; 

  paddle2Shape->calculateLocalInertia(plungerMass, trianglesInertia);
  btRigidBody::btRigidBodyConstructionInfo plungerRigidBodyCI(plungerMass, plungerMotionState, plungerShape, trianglesInertia);
  plungerRigidBody = new btRigidBody(plungerRigidBodyCI);
  plungerRigidBody->setRestitution (0.5);
  plungerRigidBody->setActivationState(DISABLE_DEACTIVATION);
  plungerRigidBody->setLinearFactor(btVector3(0,0,0));
  dynamicsWorld->addRigidBody(plungerRigidBody);

  // Create splash board
  btTriangleMesh* splashboardTriMesh = new btTriangleMesh();
  m_splashboard = new Object("../objects/splashboard.obj", "../objects/splashboard.jpg", splashboardTriMesh, 1);
  btCollisionShape *splashShape = new btBvhTriangleMeshShape(splashboardTriMesh, true);
  btDefaultMotionState* splashMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
  btScalar splashMass = 1; 

  paddle2Shape->calculateLocalInertia(splashMass, trianglesInertia);
  btRigidBody::btRigidBodyConstructionInfo splashRigidBodyCI(splashMass, splashMotionState, splashShape, trianglesInertia);
  splashboardRigidBody = new btRigidBody(splashRigidBodyCI);
  splashboardRigidBody->setRestitution (0.5);
  splashboardRigidBody->setActivationState(DISABLE_DEACTIVATION);
  splashboardRigidBody->setLinearFactor(btVector3(0,0,0));
  dynamicsWorld->addRigidBody(splashboardRigidBody);


  basePlungerPower = 1.5;
  plungerPowerMuliplier = 1.0;
  usingPlunger = false;

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
	// Camera update
  if(topDownView == true)
  {
    m_camera->UpdateView(glm::vec3(0.0, 50.0, -1.0), glm::vec3(0.0, 0.0, 0.0));
  }
	else if(frontView == true)
	{
    m_camera->UpdateView(glm::vec3(0.0, 30.0, -30.0), glm::vec3(0.0, 0.0, 0.0));
	}
	else if(backView == true)
	{
    m_camera->UpdateView(glm::vec3(0.0, 40.0, 20.0), glm::vec3(0.0, 0.0, 0.0));
	}



  if(lightingType != newLightingType)
  {
    UpdateShader(newLightingType);
  }

  btTransform trans;
  btScalar m[16];
  dynamicsWorld->stepSimulation(dt, 10);

  ballRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_ball->model = glm::make_mat4(m);

  cheek1RigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_cheek1->model = glm::make_mat4(m);

  cheek2RigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_cheek2->model = glm::make_mat4(m);

  eye1RigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_eye1->model = glm::make_mat4(m);

  eye2RigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_eye2->model = glm::make_mat4(m);

  backRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_back->model = glm::make_mat4(m);

  frontRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_front->model = glm::make_mat4(m);

  leftRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_left->model = glm::make_mat4(m);

  rightRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_right->model = glm::make_mat4(m);

  bottomRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_bottom->model = glm::make_mat4(m);

  curveRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_topCurve->model = glm::make_mat4(m);

  curveRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_divider->model = glm::make_mat4(m);

  curveRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_triangles->model = glm::make_mat4(m);

  rightDividerRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_rightDivider->model = glm::make_mat4(m);

  leftDividerRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_leftDivider->model = glm::make_mat4(m);

  curveRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_tail->model = glm::make_mat4(m);

  plungerRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_plunger->model = glm::make_mat4(m);

  splashboardRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_splashboard->model = glm::make_mat4(m);

	btQuaternion quat;
	btScalar z,y,x;
	quat = paddle1RigidBody->getOrientation();
	//quat.getEulerZYX(z,y,x);
	//cout << z << " " << y << " " << x << endl;
	y = quat.getAngle();
	if((y < 2 && y > 1.2 && paddle1RigidBody->getAngularVelocity().getY() > 0) || (y < 3.2 && y > 3 && paddle1RigidBody->getAngularVelocity().getY() < 0))
	{
		paddle1RigidBody->setAngularVelocity(btVector3(0,0,0));
	}
	//cout << "Paddle1 angle" << quat.getAngle() << endl;
	//if(quat.getAngle() > 1) quat.setEuler(0,1,0);
  paddle1RigidBody->getMotionState()->getWorldTransform(trans);
	trans.setRotation(quat);
  trans.getOpenGLMatrix(m);
  m_paddle1->model = glm::make_mat4(m);

	quat = paddle2RigidBody->getOrientation();
	//quat.getEulerZYX(z,y,x);
	//cout << z << " " << y << " " << x << endl;
	y = quat.getAngle();
	if((y > 1.2 && y < 2 && paddle2RigidBody->getAngularVelocity().getY() < 0) || ( y > 3 && paddle2RigidBody->getAngularVelocity().getY() > 0))
	{
		paddle2RigidBody->setAngularVelocity(btVector3(0,0,0));
	}
	//cout << "Paddle2 angle" << quat.getAngle() << endl;
	//if(quat.getAngle() > 1) quat.setEuler(0,1,0);
  paddle2RigidBody->getMotionState()->getWorldTransform(trans);
	trans.setRotation(quat);
  trans.getOpenGLMatrix(m);
  m_paddle2->model = glm::make_mat4(m);
  //cubeRigidBody->getMotionState()->getWorldTransform(trans);
  //trans.getOrigin() += btVector3(0,0,0.1);
  
  //cubeRigidBody->applyCentralImpulse(btVector3(.4,0,0.4));
  //cubeRigidBody->getMotionState()->getWorldTransform(trans);

  //trans.getOpenGLMatrix(m);
  //m_cube->model = glm::make_mat4(m);
  //std::cout<<trans.getOrigin().getX() << " " << trans.getOrigin().getY()<< " " << trans.getOrigin().getZ() << std::endl;


  plungerPosition = plungerRigidBody->getCenterOfMassPosition();
  if(usingPlunger == false && plungerPosition.z() <= 0)
  {
    float z = basePlungerPower*plungerPowerMuliplier + 0.5;
    //sanity check to make sure z is not negative
    if(z < 0)
    {
      z *= -1.0;
    }
    //cout << z << endl;
    plungerRigidBody->setLinearVelocity(btVector3(0,0,z));
  }
  else if(usingPlunger == false && plungerPosition.z() >= 0)
  {
    //cout << plungerPosition.z()  << endl;
    plungerRigidBody->setLinearVelocity(btVector3(0,0,0));
  }

  ballPosition = ballRigidBody->getCenterOfMassPosition();
  UpdateScore();
  //cout << ballPosition.z() << endl;
  if(ballPosition.z() <= -18.8)
  {
    if(ballsLeft > 0)
    {
      trans.setOrigin(btVector3(-10, 2, -6));
	ballsLeft--;
        ballRigidBody->setWorldTransform(trans);
        ballRigidBody->getMotionState()->getWorldTransform(trans);
        trans.getOpenGLMatrix(m);
        m_ball->model = glm::make_mat4(m);
        //cout << ballsLeft << endl;
        //ballRigidBody->setWorldTransform();
    }
    else if(endOfGame == false)
    {
      endOfGame = true;
      cout << "GAME OVER" << endl;
      cout << playerName <<"'s Score: "<<score<<endl;

      cout << "Press R to Restart" << endl;
    }
  }

  if(reset == true)
  {
    trans.setOrigin(btVector3(-10, 2, -6));
    ballRigidBody->setWorldTransform(trans);
    ballRigidBody->getMotionState()->getWorldTransform(trans);
    trans.getOpenGLMatrix(m);
    m_ball->model = glm::make_mat4(m);
    ballsLeft = 2;
    cout << "Balls left: 3" << endl;
    endOfGame = false;
    reset = false;
  }
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

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_cheek1->GetModel()));
  m_cheek1->Render(m_shader, bumperSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_cheek2->GetModel()));
  m_cheek2->Render(m_shader, bumperSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_eye1->GetModel()));
  m_eye1->Render(m_shader, bumperSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_eye2->GetModel()));
  m_eye2->Render(m_shader, bumperSpecular);


  //glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_cube->GetModel()));
  //m_cube->Render(m_shader, cubeSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_front->GetModel()));
  m_front->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_back->GetModel()));
  m_back->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_left->GetModel()));
  m_left->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_right->GetModel()));
  m_right->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_topCurve->GetModel()));
  m_topCurve->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_divider->GetModel()));
  m_divider->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_triangles->GetModel()));
  m_triangles->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_bottom->GetModel()));
  m_bottom->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_paddle1->GetModel()));
  m_paddle1->Render(m_shader, flipperSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_paddle2->GetModel()));
  m_paddle2->Render(m_shader, flipperSpecular);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_plunger->GetModel()));
  m_plunger->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_rightDivider->GetModel()));
  m_rightDivider->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_leftDivider->GetModel()));
  m_leftDivider->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_tail->GetModel()));
  m_tail->Render(m_shader, .5);

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_splashboard->GetModel()));
  m_splashboard->Render(m_shader, .5);
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

void Graphics::ResetGame()
{
  btTransform trans;
  btScalar m[16];
  trans.setOrigin(btVector3(-10, 2, -6));
  ballsLeft--;
  ballRigidBody->setWorldTransform(trans);
  ballRigidBody->getMotionState()->getWorldTransform(trans);
  trans.getOpenGLMatrix(m);
  m_ball->model = glm::make_mat4(m);
  reset = false;
}

void Graphics::UpdateScore(){
  btVector3 tmp;
  tmp = ballRigidBody->getCenterOfMassPosition();
  glm::vec2 ball = glm::vec2(tmp.x(),tmp.z());
  tmp = cheek1RigidBody->getCenterOfMassPosition();
  glm::vec2 cheek1 = glm::vec2(tmp.x(),tmp.z());
  tmp = cheek2RigidBody->getCenterOfMassPosition();
  glm::vec2 cheek2 = glm::vec2(tmp.x(),tmp.z());
  tmp = eye1RigidBody->getCenterOfMassPosition();
  glm::vec2 eye1 = glm::vec2(tmp.x(),tmp.z());
  tmp = eye2RigidBody->getCenterOfMassPosition();
  glm::vec2 eye2 = glm::vec2(tmp.x(),tmp.z());

  if(glm::distance(ball,cheek1)<=2.05 && collides ==false )
  {
	score+=100;std::cout<<"score:"<<score<<endl;
	collides = true;
	return;
  }

  if(glm::distance(ball,cheek2)<=2.05 && collides ==false )
  {
	score+=100;std::cout<<"score:"<<score<<endl;
	collides = true;
	return;
  }

  if(glm::distance(ball,eye1)<=1.55 && collides ==false )
  {
	score+=200;std::cout<<"score:"<<score<<endl;
	collides = true;
	return;
  }

  if(glm::distance(ball,eye2)<=1.55 && collides ==false )
  {
	score+=200;std::cout<<"score:"<<score<<endl;
	collides = true;
	return;
  }

  if(glm::distance(ball,cheek1)>2.05 && glm::distance(ball,cheek2)>2.05 && glm::distance(ball,eye1)>1.55 && glm::distance(ball,eye2)>1.55 && collides == true)
  {
	collides = false;
	return;
  }
}
