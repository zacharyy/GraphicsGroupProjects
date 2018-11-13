
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
	static bool ballLaunched = false;
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

    if (m_event.key.keysym.sym == SDLK_w)
    {
			// Probably change this so its actually the plunger hitting the ball, maybe give plunger a linear velocity to push the ball and that linear velocity gets bigger the longer the button is held down
      m_graphics->ballRigidBody->applyCentralImpulse(btVector3(0,0,5));
    }

    if (m_event.key.keysym.sym == SDLK_s)
    {
     // m_graphics->cubeRigidBody->applyCentralImpulse(btVector3(0,0,-1));
    }

    if (m_event.key.keysym.sym == SDLK_a)
    {
				//m_graphics->paddle1Rot += .3;
				//Need to rotate to top then stop then start rotating back down to starting position unless button is held
				m_graphics->paddle1RigidBody->setAngularVelocity(btVector3(0,0.1,0));
    }

    if (m_event.key.keysym.sym == SDLK_d)
    {
			//m_graphics->paddle2Rot -= .3;
				m_graphics->paddle2RigidBody->setAngularVelocity(btVector3(0,-0.1,0));
    }
    if (m_event.key.keysym.sym == SDLK_v)
    {
      m_graphics->newLightingType = 0;
    }
    if (m_event.key.keysym.sym == SDLK_f)
    {
      m_graphics->newLightingType = 1;
    }
    if (m_event.key.keysym.sym == SDLK_n)
    {
			m_graphics->ambientValue += .1;
    }
    if (m_event.key.keysym.sym == SDLK_m)
    {
			m_graphics->ambientValue -= .1;
    }
		// ball specular
    if (m_event.key.keysym.sym == SDLK_t)
    {
			m_graphics->ballSpecular += .1;
    }    if (m_event.key.keysym.sym == SDLK_y)
    {
			m_graphics->ballSpecular -= .1;
    }
		// cube specular
    if (m_event.key.keysym.sym == SDLK_u)
    {
			m_graphics->cubeSpecular += .1;
    } 
		if (m_event.key.keysym.sym == SDLK_i)
    {
			m_graphics->cubeSpecular -= .1;
    }	
		// cylinder specular
    if (m_event.key.keysym.sym == SDLK_o)
    {
			m_graphics->cylSpecular += .1;
    }
    if (m_event.key.keysym.sym == SDLK_p)
    {
			m_graphics->cylSpecular -= .1;
    }
		//cut off angle of spot light
    if (m_event.key.keysym.sym == SDLK_j)
    {
			m_graphics->cutOffAngle += .5;
    }
    if (m_event.key.keysym.sym == SDLK_k)
    {
			m_graphics->cutOffAngle -= .5;
    }
		//brightness of spot light
    if (m_event.key.keysym.sym == SDLK_z)
    {
			m_graphics->brightness += .2;
    }
    if (m_event.key.keysym.sym == SDLK_x)
    {
			m_graphics->brightness -= .2;
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
