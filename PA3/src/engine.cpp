
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

  //variables for planet controls
  bool ps_r = false; 
  bool ps_s = false;
  bool pr_r = false; 
  bool pr_s = false;

  //variables for moon controls
  bool ms_r = false; 
  bool ms_s = false;
  bool mr_r = false; 
  bool mr_s = false;


  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the user input
    while(SDL_PollEvent(&m_event) != 0)
    {
      User_input(ps_r, ps_s, pr_r, pr_s, ms_r, ms_s, mr_r, mr_s);
    }

    // Update and render the graphics
    m_graphics->Update(m_DT, ps_r, ps_s, pr_r, pr_s, ms_r, ms_s, mr_r, mr_s);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::User_input(bool& pspin_reverse, bool& pspin_stop, 
bool& prevolution_reverse, bool& prevolution_stop,
bool& mspin_reverse, bool& mspin_stop, 
bool& mrevolution_reverse, bool& mrevolution_stop)
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    // handle key down events here

    if(m_event.key.keysym.sym == SDLK_ESCAPE)
    {
      m_running = false;
    }

    /*Control for planets*/

    //if 1 or right arrow is pressed, reverse the spin of the planet
    else if(m_event.key.keysym.sym == SDLK_1 || m_event.key.keysym.sym == SDLK_RIGHT)
    {
      if(pspin_reverse == false)
      {
        pspin_reverse = true;
      }
      else if(pspin_reverse == true)
      {
        pspin_reverse = false;
      }
    }
    //if 2 or left arrow is pressed, stop the spin of the planet
    else if(m_event.key.keysym.sym == SDLK_2 || m_event.key.keysym.sym == SDLK_LEFT)
    {
      if(pspin_stop == false)
      {
        pspin_stop = true;
      }
      else if(pspin_stop == true)
      {
        pspin_stop = false;
      }
    }
    //if up arrow is pressed, reverse the revolution of the planet
    else if(m_event.key.keysym.sym == SDLK_UP)
    {
      if(prevolution_reverse == false)
      {
        prevolution_reverse = true;
      }
      else if(prevolution_reverse == true)
      {
        prevolution_reverse = false;
      }
    }
    //if down arrow is pressed, stop the revolution of the planet
    else if(m_event.key.keysym.sym == SDLK_DOWN)
    {
      if(prevolution_stop == false)
      {
        prevolution_stop = true;
      }
      else if(prevolution_stop == true)
      {
        prevolution_stop = false;
      }
    }

    /*Control for moons*/

    //if 3 or right arrow is pressed, reverse the spin of the moon
    else if(m_event.key.keysym.sym == SDLK_3)
    {
      if(mspin_reverse == false)
      {
        mspin_reverse = true;
      }
      else if(mspin_reverse == true)
      {
        mspin_reverse = false;
      }
    }
    //if 4 is pressed, stop the spin of the moon
    else if(m_event.key.keysym.sym == SDLK_2 || m_event.key.keysym.sym == SDLK_4)
    {
      if(mspin_stop == false)
      {
        mspin_stop = true;
      }
      else if(mspin_stop == true)
      {
        mspin_stop = false;
      }
    }
    //if 5 is pressed, reverse the revolution of the moon
    else if(m_event.key.keysym.sym == SDLK_5)
    {
      if(mrevolution_reverse == false)
      {
        mrevolution_reverse = true;
      }
      else if(mrevolution_reverse == true)
      {
        mrevolution_reverse = false;
      }
    }
    //if 6 is pressed, stop the revolution of the moon
    else if(m_event.key.keysym.sym == SDLK_6)
    {
      if(mrevolution_stop == false)
      {
        mrevolution_stop = true;
      }
      else if(mrevolution_stop == true)
      {
        mrevolution_stop = false;
      }
    }

  }
  else if (m_event.type == SDL_MOUSEBUTTONDOWN)
  {
    /*Control for planets (mouse inputs)*/

    //if lmb is pressed, reverse the revolution of the planet
    if (m_event.button.button == SDL_BUTTON_LEFT)
    {
      if(prevolution_reverse == false)
      {
        prevolution_reverse = true;
      }
      else if(prevolution_reverse == true)
      {
        prevolution_reverse = false;
      }
    }
    //if rmb is pressed, stop the revolution of the planet
    else if (m_event.button.button == SDL_BUTTON_RIGHT)
    {
      if(prevolution_stop == false)
      {
        prevolution_stop = true;
      }
      else if(prevolution_stop == true)
      {
        prevolution_stop = false;
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
