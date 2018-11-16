
#include "engine.h"
/*
struct AudioData
{
Uint8* position;
Uint32 length;
};

void audioCallback(void* userData, Uint8* stream, int streamLength)
{
AudioData* audio = (AudioData*)userData;

if (audio->length == 0)
{
return;
}

Uint32 length = (Uint32)streamLength;

length = (length > audio->length ? audio->length : length);

SDL_memcpy(stream, audio->position, length);

audio->position += length;
audio->length -= length;
}*/

Engine::Engine(string name, string pn, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  //playerName = pn;
  m_FULLSCREEN = false;
}

Engine::Engine(string name, string pn)
{
  m_WINDOW_NAME = name;
  //playerName = pn;
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
	// Audio Stuff
	/*SDL_Init(SDL_INIT_AUDIO);

	SDL_AudioSpec wavSpec;
	Uint8* wavStart;
	Uint32 wavLength;
	string filePath = "../objects/ding.wav";

	if(SDL_LoadWAV("ding.wav", &wavSpec, &wavStart, &wavLength) == NULL)
	{
	cerr << "Error: file could not be loaded as an audio file." << endl;
	}

	AudioData audio;
	audio.position = wavStart;
	audio.length = wavLength;
	wavSpec.callback = audioCallback;
	wavSpec.userdata = &audio;

	SDL_AudioDeviceID audioDevice;
	audioDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);

	if (audioDevice == 0)
	{
		cerr << "Error: " << SDL_GetError() << endl;
	}
	SDL_PauseAudioDevice(audioDevice, 0);

	while (audio.length > 0)
	{
		SDL_Delay(100);
	}*/
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  //m_graphics->playerName = playerName;
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

    //hold space to use plunger
    if (m_event.key.keysym.sym == SDLK_SPACE)
    {
      //if the z position greater than a certain threshold, move it back by setting its velocity to a negative value
      //also set the plunger multiplyer to the distance pulled back
      if( m_graphics->plungerPosition.z() >= -2.5)
      {
        m_graphics->plungerRigidBody->setLinearVelocity(btVector3(0,0,-.2));
        m_graphics->plungerPowerMuliplier = -1.0 * m_graphics->plungerPosition.z();
      }
      //if the z position less than a certain threshold, stop moving it
      else
      {
        m_graphics->plungerRigidBody->setLinearVelocity(btVector3(0,0,0));
      }
      m_graphics->usingPlunger = true;
    }
    //press left shift to use left flipper/bumper
    if (m_event.key.keysym.sym == SDLK_LSHIFT)
    {
				//m_graphics->paddle1Rot += .3;
				//Need to rotate to top then stop then start rotating back down to starting position unless button is held
				btQuaternion quat;
				btScalar z,y,x;
				quat = m_graphics->paddle1RigidBody->getOrientation();
				y = quat.getAngle();
				if(y > 3)
					m_graphics->paddle1RigidBody->setAngularVelocity(btVector3(0,1,0));
    }
    //press right shift to use right flipper/bumper
    if (m_event.key.keysym.sym == SDLK_RSHIFT)
    {
			//m_graphics->paddle2Rot -= .3;
				btQuaternion quat;
				btScalar z,y,x;
				quat = m_graphics->paddle2RigidBody->getOrientation();
				y = quat.getAngle();
				if(y > 3)
					m_graphics->paddle2RigidBody->setAngularVelocity(btVector3(0,-1,0));
    }
    //press r to restart
    if (m_event.key.keysym.sym == SDLK_r)
    {
      m_graphics->reset = true;
    }
    //press r for per vertex lighting
    if (m_event.key.keysym.sym == SDLK_v)
    {
      m_graphics->newLightingType = 0;
    }
    //press f for per fragment lighting
    if (m_event.key.keysym.sym == SDLK_f)
    {
      m_graphics->newLightingType = 1;
    }
    //press n to increase ambient lighting
    if (m_event.key.keysym.sym == SDLK_n)
    {
      m_graphics->ambientValue += .1;
    }
    //press m to decrease ambient lighting
    if (m_event.key.keysym.sym == SDLK_m)
    {
      m_graphics->ambientValue -= .1;
    }
    // press t to increase ball specular lighting
    if (m_event.key.keysym.sym == SDLK_t)
    {
      m_graphics->ballSpecular += .1;
    }
    // press y to decrease ball specular lighting
    if (m_event.key.keysym.sym == SDLK_y)
    {
      m_graphics->ballSpecular -= .1;
    }
    // press u to increase flipper specular lighting
    if (m_event.key.keysym.sym == SDLK_u)
    {
      m_graphics->flipperSpecular += .1;
    } 
    // press i to decrease flipper specular lighting
    if (m_event.key.keysym.sym == SDLK_i)
    {
      m_graphics->flipperSpecular -= .1;
    }	
    // press o to increase bumper specular lighting
    if (m_event.key.keysym.sym == SDLK_o)
    {
      m_graphics->bumperSpecular += .1;
    }
    // press p to decrease bumper specular lighting
    if (m_event.key.keysym.sym == SDLK_p)
    {
      m_graphics->bumperSpecular -= .1;
    }
    //press j to increase spotlight radius
    if (m_event.key.keysym.sym == SDLK_j)
    {
      m_graphics->cutOffAngle += .5;
    }
    //press k to decrease spotlight radius
    if (m_event.key.keysym.sym == SDLK_k)
    {
      m_graphics->cutOffAngle -= .5;
    }
    //press z to increase brightness spotlight
    if (m_event.key.keysym.sym == SDLK_z)
    {
      m_graphics->brightness[0] += .2;
    }
    //press x to decrease brightness spotlight
    if (m_event.key.keysym.sym == SDLK_x)
    {
      m_graphics->brightness[0] -= .2;
    }

    /*Camera Controls*/
    //if w is pressed move top down camera up
    else if(m_event.key.keysym.sym == SDLK_w)
    {
        m_graphics->UpdatedView = true;
	m_graphics->moveCameraUp = true;
    }
    //if a is pressed move top down camera left
    else if(m_event.key.keysym.sym == SDLK_a)
    {
        m_graphics->UpdatedView = true;
	m_graphics->moveCameraLeft = true;
    }
    //if s is pressed move top down camera down
    else if(m_event.key.keysym.sym == SDLK_s)
    {
        m_graphics->UpdatedView = true;
	m_graphics->moveCameraDown = true;
    }
    //if d is pressed move top down camera right
    else if(m_event.key.keysym.sym == SDLK_d)
    {
        m_graphics->UpdatedView = true;
	m_graphics->moveCameraRight = true;
    }
    //if e is pressed zoom top down camera in
    else if(m_event.key.keysym.sym == SDLK_e)
    {
        m_graphics->UpdatedView = true;
	m_graphics->zoomInCamera = true;
    }
    //if q is pressed zoom top down camera out
    else if(m_event.key.keysym.sym == SDLK_q)
    {
        m_graphics->UpdatedView = true;
	m_graphics->zoomOutCamera = true;
    }
    //press , for top down view
    if (m_event.key.keysym.sym == SDLK_COMMA)
    {
			m_graphics->topDownView = true;
			m_graphics->frontView = false;
			m_graphics->backView = false;
    }
    //press . for front view
    if (m_event.key.keysym.sym == SDLK_PERIOD)
    {
			m_graphics->topDownView = false;
			m_graphics->frontView = true;
			m_graphics->backView = false;
    }
    //press / for back view
    if (m_event.key.keysym.sym == SDLK_SLASH)
    {
			m_graphics->topDownView = false;
			m_graphics->frontView = false;
			m_graphics->backView = true;
    }
  }
  else if (m_event.type == SDL_KEYUP)
  {
		// Handle the paddles coming back down from the top when the button is released
    if (m_event.key.keysym.sym == SDLK_LSHIFT)
    {
			btQuaternion quat;
			btScalar z,y,x;
			quat = m_graphics->paddle1RigidBody->getOrientation();
			y = quat.getAngle();
			if(y < 3)
				m_graphics->paddle1RigidBody->setAngularVelocity(btVector3(0,-1,0));
    }

    if (m_event.key.keysym.sym == SDLK_RSHIFT)
    {
			btQuaternion quat;
			btScalar z,y,x;
			quat = m_graphics->paddle2RigidBody->getOrientation();
			y = quat.getAngle();
			if(y < 3)
				m_graphics->paddle2RigidBody->setAngularVelocity(btVector3(0,1,0));
    }
    //release space to let plunger go, also displays ball count
    if (m_event.key.keysym.sym == SDLK_SPACE)
    {
      m_graphics->usingPlunger = false;
      cout << "Balls left: " << m_graphics->ballsLeft << endl;
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
