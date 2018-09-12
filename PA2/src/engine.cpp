
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

bool Engine::Initialize()
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
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
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

  bool s_r = false; 
  bool s_s = false;
  bool r_r = false; 
  bool r_s = false;


  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the user input
    while(SDL_PollEvent(&m_event) != 0)
    {
      User_input(s_r, s_s, r_r, r_s);
    }

    // Update and render the graphics
    m_graphics->Update(m_DT, s_r, s_s, r_r, r_s);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::User_input(bool& spin_reverse, bool& spin_stop, bool& revolution_reverse, bool& revolution_stop)
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
    else if(m_event.key.keysym.sym == SDLK_1)//if 1 is pressed
    {
      if(spin_reverse == false)
      {
        spin_reverse = true;
      }
      else if(spin_reverse == true)
      {
        spin_reverse = false;
      }
    }
    else if(m_event.key.keysym.sym == SDLK_2)//if 2 is pressed
    {
      if(spin_stop == false)
      {
        spin_stop = true;
      }
      else if(spin_stop == true)
      {
        spin_stop = false;
      }
    }
  }
  else if (m_event.type == SDL_MOUSEBUTTONDOWN)
  {
    if (m_event.button.button == SDL_BUTTON_LEFT)//if lmb is pressed
    {
      if(revolution_reverse == false)
      {
        revolution_reverse = true;
      }
      else if(revolution_reverse == true)
      {
        revolution_reverse = false;
      }
    }
    else if (m_event.button.button == SDL_BUTTON_RIGHT)//if rmb is pressed
    {
      if(revolution_stop == false)
      {
        revolution_stop = true;
      }
      else if(revolution_stop == true)
      {
        revolution_stop = false;
      }
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
