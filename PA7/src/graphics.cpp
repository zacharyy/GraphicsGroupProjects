#include "graphics.h"

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

bool Graphics::Initialize(int width, int height, string objectFileString)
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

  // Create the object
	double earthDistance = 8;
	double earthSize = 1;
	double earthOV = 1;
	double earthRS = 1;
  m_sun = new Object("../objects/sphere.obj", "../objects/sun.jpg");
	m_earth = new PlanetObject("../objects/sphere.obj", "../objects/earth.jpg",earthDistance,earthSize,earthOV,earthRS);
	m_mars = new PlanetObject("../objects/sphere.obj", "../objects/mars.jpg",1.524 * earthDistance,0.542 * earthSize,0.809 * earthOV,0.972 * earthRS);


	m_mercury = new PlanetObject("../objects/sphere.obj", "../objects/mercury.jpg",0.387 * earthDistance,0.382 * earthSize,1.591 * earthOV,0.017 * earthRS);
	m_venus = new PlanetObject("../objects/sphere.obj", "../objects/venus.jpg",0.723 * earthDistance,0.949 * earthSize,1.174 * earthOV, -0.004 * earthRS);
	m_jupiter = new PlanetObject("../objects/sphere.obj", "../objects/jupiter.jpg",5.203 * earthDistance,11.209 * earthSize,0.440 * earthOV,2.414 * earthRS);
	m_saturn = new PlanetObject("../objects/sphere.obj", "../objects/saturn.jpg",9.582 * earthDistance,9.449 * earthSize,0.326 * earthOV,2.234 * earthRS);
	m_uranus = new PlanetObject("../objects/sphere.obj", "../objects/uranus.jpg",19.201 * earthDistance,4.007 * earthSize,0.228 * earthOV,-1.39 * earthRS);
	m_neptune = new PlanetObject("../objects/sphere.obj", "../objects/neptune.jpg",30.047 * earthDistance,3.883 * earthSize,0.181 * earthOV,1.484 * earthRS);
	m_pluto = new PlanetObject("../objects/sphere.obj", "../objects/pluto.jpg",39.481 * earthDistance,0.186 * earthSize,0.158 * earthOV,-0.156 * earthRS);

//moons
m_earthMoon = new MoonObject("../objects/sphere.obj", "../objects/earth_moon.jpg",0.384*earthDistance,0.272 * earthSize,earthOV,0.214 *earthRS,m_earth);
m_marsMoon1 = new MoonObject("../objects/sphere.obj", "../objects/earth_moon.jpg",0.13*earthDistance,0.1 * earthSize,0.88*earthOV,0.214 *earthRS,m_mars);
m_marsMoon2 = new MoonObject("../objects/sphere.obj", "../objects/earth_moon.jpg",0.2*earthDistance,0.05 * earthSize,0.1*earthOV,0.214 *earthRS,m_mars);
m_jupiterMoon1 = new MoonObject("../objects/sphere.obj", "../objects/Io.jpg",2*earthDistance,0.287 * earthSize,0.58*earthOV,0.228 *earthRS,m_jupiter);
m_jupiterMoon2 = new MoonObject("../objects/sphere.obj", "../objects/Europa.jpg",3.18*earthDistance,0.245*earthSize,0.46*earthOV,0.182 *earthRS,m_jupiter);
m_jupiterMoon3 = new MoonObject("../objects/sphere.obj", "../objects/Ganymede.png",5*earthDistance,0.413* earthSize,0.365*earthOV,0.245 *earthRS,m_jupiter);
m_jupiterMoon4 = new MoonObject("../objects/sphere.obj", "../objects/Callisto.jpg",8.9*earthDistance,0.378 * earthSize,0.275*earthOV,0.218 *earthRS,m_jupiter);
m_saturnRing = new MoonObject("../objects/ring.obj", "../objects/saturn_ring.png",0, 3*earthSize,0,2.234 * earthRS, m_saturn);



std::cout<<m_earthMoon->planet->orbitDistance<<' '<<m_saturnRing->planet->orbitDistance<<std::endl;
  normalView = true;
  topDownView = false;
  UpdatedTDView = false;
  moveTDCameraUp = false;
  moveTDCameraDown = false;
  moveTDCameraLeft = false;
  moveTDCameraRight = false;
  zoomInTDCamera = false;
  zoomOutTDCamera = false;
  planetSelector = 0;

  // Set up the shaders
  m_shader = new Shader();
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }

  // Add the vertex shader
  if(!m_shader->AddShader(GL_VERTEX_SHADER))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

  // Add the fragment shader
  if(!m_shader->AddShader(GL_FRAGMENT_SHADER))
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

  //enable depth testing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  return true;
}

void Graphics::Update(unsigned int dt)
{
  // Update the object
  m_sun->Update(dt);
	m_earth->Update(dt, glm::mat4(1.0));
	m_mars->Update(dt, glm::mat4(1.0));
	m_mercury->Update(dt, glm::mat4(1.0));
	m_venus->Update(dt, glm::mat4(1.0));
	m_jupiter->Update(dt, glm::mat4(1.0));
	m_saturn->Update(dt, glm::mat4(1.0));
	m_uranus->Update(dt, glm::mat4(1.0));
	m_neptune->Update(dt, glm::mat4(1.0));
	m_pluto->Update(dt, glm::mat4(1.0));
	m_earthMoon->Update(dt, glm::mat4(1.0));
	m_marsMoon1->Update(dt, glm::mat4(1.0));
	m_marsMoon2->Update(dt, glm::mat4(1.0));
	m_jupiterMoon1->Update(dt, glm::mat4(1.0));	
	m_jupiterMoon2->Update(dt, glm::mat4(1.0));
	m_jupiterMoon3->Update(dt, glm::mat4(1.0));
	m_jupiterMoon4->Update(dt, glm::mat4(1.0));
	m_saturnRing->Update(dt, glm::mat4(1.0));
  /*if statement that put camera in normal mode*/
  if(normalView == true)
  {
    m_camera->NormalView();
  }

  /*if statement that put camera in top down mode*/
  if(topDownView == true && UpdatedTDView != true)
  {
    m_camera->currentTDEyePosition = m_camera->defaultTDEyePosition;
    m_camera->currentTDFocusPoint = m_camera->defaultTDFocusPoint;
    m_camera->TopDownView();
  }
  
  /*if statements that move camera in top down mode*/
  if(moveTDCameraUp == true && UpdatedTDView == true)
  {
    m_camera->currentTDEyePosition.z -= 2;
    m_camera->currentTDFocusPoint.z -= 2;
    m_camera->TopDownViewUpdated(m_camera->currentTDEyePosition, m_camera->currentTDFocusPoint);
    moveTDCameraUp = false;
  }
  if(moveTDCameraLeft == true && UpdatedTDView == true)
  {
    m_camera->currentTDEyePosition.x -= 2;
    m_camera->currentTDFocusPoint.x -= 2;
    m_camera->TopDownViewUpdated(m_camera->currentTDEyePosition, m_camera->currentTDFocusPoint);
    moveTDCameraLeft = false;
  }
  if(moveTDCameraDown == true && UpdatedTDView == true)
  {
    m_camera->currentTDEyePosition.z += 2;
    m_camera->currentTDFocusPoint.z += 2;
    m_camera->TopDownViewUpdated(m_camera->currentTDEyePosition, m_camera->currentTDFocusPoint);
    moveTDCameraDown = false;
  }
  if(moveTDCameraRight == true && UpdatedTDView == true)
  {
    m_camera->currentTDEyePosition.x += 2;
    m_camera->currentTDFocusPoint.x += 2;
    m_camera->TopDownViewUpdated(m_camera->currentTDEyePosition, m_camera->currentTDFocusPoint);
    moveTDCameraRight = false;
  }
  if(zoomInTDCamera == true && UpdatedTDView == true)
  {
    m_camera->currentTDEyePosition.y -= 2;
    m_camera->TopDownViewUpdated(m_camera->currentTDEyePosition, m_camera->currentTDFocusPoint);
    zoomInTDCamera = false;
  }  
  if(zoomOutTDCamera == true && UpdatedTDView == true)
  {
    m_camera->currentTDEyePosition.y += 2;
    m_camera->TopDownViewUpdated(m_camera->currentTDEyePosition, m_camera->currentTDFocusPoint);
    zoomOutTDCamera = false;
  }

  /*switch statement that moves camera between planets*/
  glm::mat4 temp;
  glm::vec3 eyePosition;
  glm::vec3 focusPoint;
  // camera will be placed PlanetSize * planetCameraDistanceScale away from planet
  int planetCameraDistanceScale = 5;
  switch(planetSelector)
  {
    case 1:
           temp = m_mercury->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_mercury->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_mercury->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_mercury->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 2:
           temp = m_venus->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_venus->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_venus->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_venus->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 3:
           temp = m_earth->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_earth->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_earth->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_earth->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 4:
           temp = m_mars->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_mars->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_mars->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_mars->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 5:
           temp = m_jupiter->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_jupiter->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_jupiter->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_jupiter->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 6:
           temp = m_saturn->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_saturn->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_saturn->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_saturn->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 7:
           temp = m_uranus->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_uranus->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_uranus->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_uranus->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 8:
           temp = m_neptune->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_neptune->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_neptune->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_neptune->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
    case 9:
           temp = m_pluto->GetModel();
           eyePosition = glm::vec3(temp[3]);
           eyePosition.x +=  m_pluto->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.y = m_pluto->GetPlanetSize() * planetCameraDistanceScale;
           eyePosition.z +=  m_pluto->GetPlanetSize() * planetCameraDistanceScale;
           focusPoint = glm::vec3(temp[3]);
           //std::cout << focusPoint.x << endl;
           m_camera->PlanetView(eyePosition, focusPoint);
           break;
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

  // Render the object
  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_sun->GetModel()));
  m_sun->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_earth->GetModel()));
  m_earth->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_mars->GetModel()));
  m_mars->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_mercury->GetModel()));
  m_mercury->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_venus->GetModel()));
  m_venus->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_jupiter->GetModel()));
  m_jupiter->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_saturn->GetModel()));
  m_saturn->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_uranus->GetModel()));
  m_uranus->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_neptune->GetModel()));
  m_neptune->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pluto->GetModel()));
  m_pluto->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_earthMoon->GetModel()));
  m_earthMoon->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_marsMoon1->GetModel()));
  m_marsMoon1->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_marsMoon2->GetModel()));
  m_marsMoon2->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_jupiterMoon1->GetModel()));
  m_jupiterMoon1->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_jupiterMoon2->GetModel()));
  m_jupiterMoon2->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_jupiterMoon3->GetModel()));
  m_jupiterMoon3->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_jupiterMoon4->GetModel()));
  m_jupiterMoon4->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_saturnRing->GetModel()));
  m_saturnRing->Render();

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

