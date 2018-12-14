
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
    if (m_event.key.keysym.sym == SDLK_SPACE)
    {
      //if the z position greater than a certain threshold, move it back by setting its velocity to a negative value
      //also set the plunger multiplyer to the distance pulled back
     /* if( m_graphics->plungerPosition.z() >= -2.5)
      {
        m_graphics->plungerRigidBody->setLinearVelocity(btVector3(0,0,-.2));
        m_graphics->plungerPowerMuliplier = -1.0 * m_graphics->plungerPosition.z();
      }
      //if the z position less than a certain threshold, stop moving it
      else
      {
        m_graphics->plungerRigidBody->setLinearVelocity(btVector3(0,0,0));
      }*/
      //makes sure club cant be used when ball is in motion (prevents shot counter from going off)
      if(m_graphics->ballIsMoving == false)
      {
        m_graphics->usingClub = true;
      }
    }
    /*if (m_event.key.keysym.sym == SDLK_w)
    {
      m_graphics->cubeRigidBody->applyCentralImpulse(btVector3(0,0,1.5));
    }

    if (m_event.key.keysym.sym == SDLK_s)
    {
      m_graphics->cubeRigidBody->applyCentralImpulse(btVector3(0,0,-1.5));
    }

    if (m_event.key.keysym.sym == SDLK_a)
    {
      m_graphics->cubeRigidBody->applyCentralImpulse(btVector3(1.5,0,0));
    }

    if (m_event.key.keysym.sym == SDLK_d)
    {
      m_graphics->cubeRigidBody->applyCentralImpulse(btVector3(-1.5,0,0));
    }*/
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
    }    
    if (m_event.key.keysym.sym == SDLK_y)
    {
			m_graphics->ballSpecular -= .1;
    }
		// windmill specular
    if (m_event.key.keysym.sym == SDLK_u)
    {
			m_graphics->windmillSpecular += .1;
    } 
    if (m_event.key.keysym.sym == SDLK_i)
    {
			m_graphics->windmillSpecular -= .1;
    }	
		// club specular
    if (m_event.key.keysym.sym == SDLK_o)
    {
			m_graphics->clubSpecular += .1;
    }
    if (m_event.key.keysym.sym == SDLK_p)
    {
			m_graphics->clubSpecular -= .1;
    }
    if (m_event.key.keysym.sym == SDLK_g)
    {
			m_graphics->gateSpecular += .1;
    }
    if (m_event.key.keysym.sym == SDLK_h)
    {
			m_graphics->gateSpecular -= .1;
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
			m_graphics->brightness += .3;
    }
    if (m_event.key.keysym.sym == SDLK_x)
    {
			m_graphics->brightness -= .3;
			//m_graphics->clubRigidBody->setAngularVelocity(btVector3(0,0.1,0));
    }
    if(m_event.key.keysym.sym == SDLK_LEFT)
    {
      m_graphics->clubRigidBody->setAngularVelocity(btVector3(0,.3,0));
    }
    if(m_event.key.keysym.sym == SDLK_RIGHT)
    {
      m_graphics->clubRigidBody->setAngularVelocity(btVector3(0,-.3,0));
    }
    //press +/= to increase fan speed
    if (m_event.key.keysym.sym == SDLK_EQUALS)
    {
      m_graphics->fanSpeed += .02;
    }
    //press -/_ to decrease fan speed
    if (m_event.key.keysym.sym == SDLK_MINUS)
    {
      m_graphics->fanSpeed -= .02;
    }
    //press q to turn camera left
    if (m_event.key.keysym.sym == SDLK_q)
    {
      m_graphics->turnCameraLeft = true;
    }
    //press e to turn camera right
    if (m_event.key.keysym.sym == SDLK_e)
    {
      m_graphics->turnCameraRight = true;
    }
    //press r to restart
    /*if (m_event.key.keysym.sym == SDLK_r)
    {
      m_graphics->restart = true;
    }*/
    if (m_event.key.keysym.sym == SDLK_1)
    {
      m_graphics->levelSelectionSwitch = 1;
    }
    if (m_event.key.keysym.sym == SDLK_2)
    {
      m_graphics->levelSelectionSwitch = 2;
    }
    if (m_event.key.keysym.sym == SDLK_3)
    {
      m_graphics->levelSelectionSwitch = 3;
    }
    if (m_event.key.keysym.sym == SDLK_BACKQUOTE)
    {
      if(m_graphics->currentLevel != m_graphics->numberOfPistas)
      {
        m_graphics->levelSelectionSwitch = m_graphics->currentLevel+1;
      }
      else
      {
        m_graphics->levelSelectionSwitch = 1;
      }
    }
    if (m_event.key.keysym.sym == SDLK_r && m_graphics->levelCleared == true)
    {
      for(int i=0; i<m_graphics->numberOfPistas; i++)
      {
        m_graphics->score[i] = 0;
      }
      cout << endl;
      m_graphics->numberOfShots = 0;
      m_graphics->OutputScorecard();
    }
  }
  else if (m_event.type == SDL_KEYUP)
  {
    if (m_event.key.keysym.sym == SDLK_SPACE)
    {
      m_graphics->usingClub = false;
    }
		if(m_event.key.keysym.sym == SDLK_LEFT)
		{
			m_graphics->clubRigidBody->setAngularVelocity(btVector3(0,0,0));
		}
		if(m_event.key.keysym.sym == SDLK_RIGHT)
		{
			m_graphics->clubRigidBody->setAngularVelocity(btVector3(0,0,0));
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
