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

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_mars->GetModel()));
  m_neptune->Render();

  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pluto->GetModel()));
  m_pluto->Render();

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

