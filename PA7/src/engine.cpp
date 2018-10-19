
#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
}

Engine::Engine(string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

bool Engine::Initialize(string objectFileString)
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, objectFileString))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    // handle key down events here
    if (m_event.key.keysym.sym == SDLK_ESCAPE)
    {
      m_running = false;
    }

    /*Controls for camera*/
    //if n is pressed put camera in normal view mode
    else if(m_event.key.keysym.sym == SDLK_n)
    {
      m_graphics->normalView = true;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 0;
    }
    //if t is pressed put camera in top down view mode
    else if(m_event.key.keysym.sym == SDLK_t)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = true;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 0;
    }
    //if 1 is pressed show Mercury
    else if(m_event.key.keysym.sym == SDLK_1)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 1;
    }
    //if 2 is pressed show Venus
    else if(m_event.key.keysym.sym == SDLK_2)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 2;
    }
    //if 3 is pressed show Earth
    else if(m_event.key.keysym.sym == SDLK_3)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 3;
    }
    //if 4 is pressed show Mars
    else if(m_event.key.keysym.sym == SDLK_4)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 4;
    }
    //if 5 is pressed show Jupiter
    else if(m_event.key.keysym.sym == SDLK_5)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 5;
    }
    //if 6 is pressed show Saturn
    else if(m_event.key.keysym.sym == SDLK_6)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 6;
    }
    //if 7 is pressed show Uranus
    else if(m_event.key.keysym.sym == SDLK_7)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 7;
    }
    //if 8 is pressed show Neptune
    else if(m_event.key.keysym.sym == SDLK_8)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 8;
    }
    //if 9 is pressed show Pluto
    else if(m_event.key.keysym.sym == SDLK_9)
    {
      m_graphics->normalView = false;
      m_graphics->topDownView = false;
      m_graphics->UpdatedTDView = false;
      m_graphics->planetSelector = 9;
    }
    //controls for camera movement
    //if w is pressed move top down camera up
    else if(m_event.key.keysym.sym == SDLK_w && m_graphics->topDownView == true)
    {
        m_graphics->UpdatedTDView = true;
	m_graphics->moveTDCameraUp = true;
    }
    //if a is pressed move top down camera left
    else if(m_event.key.keysym.sym == SDLK_a && m_graphics->topDownView == true)
    {
        m_graphics->UpdatedTDView = true;
	m_graphics->moveTDCameraLeft = true;
    }
    //if s is pressed move top down camera down
    else if(m_event.key.keysym.sym == SDLK_s && m_graphics->topDownView == true)
    {
        m_graphics->UpdatedTDView = true;
	m_graphics->moveTDCameraDown = true;
    }
    //if d is pressed move top down camera right
    else if(m_event.key.keysym.sym == SDLK_d && m_graphics->topDownView == true)
    {
        m_graphics->UpdatedTDView = true;
	m_graphics->moveTDCameraRight = true;
    }
    //if e is pressed zoom top down camera in
    else if(m_event.key.keysym.sym == SDLK_e && m_graphics->topDownView == true)
    {
        m_graphics->UpdatedTDView = true;
	m_graphics->zoomInTDCamera = true;
    }
    //if q is pressed zoom top down camera out
    else if(m_event.key.keysym.sym == SDLK_q && m_graphics->topDownView == true)
    {
        m_graphics->UpdatedTDView = true;
	m_graphics->zoomOutTDCamera = true;
    }
    /*Simulation Controls*/
    else if(m_event.key.keysym.sym == SDLK_EQUALS)
    {
      if(m_graphics->speedScaler == 0 || m_graphics->speedScaler  < 0.001) m_graphics->speedScaler = .001;
      else if(m_graphics->speedScaler <= 1000000) m_graphics->speedScaler *= 2;
    }
    else if(m_event.key.keysym.sym == SDLK_MINUS)
    {
      if(m_graphics->speedScaler > 0) m_graphics->speedScaler /= 2;
    }
    else if(m_event.key.keysym.sym == SDLK_p)
    {
      m_graphics->UpdateScale();
    }
  }
}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}
