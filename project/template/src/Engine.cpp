#include "Engine.hpp"

using namespace std;
using namespace glimac;

Engine::Engine()
{
  this->system        = 0;
  this->sound         = 0;
  this->channel       = 0;
  this->dsplowpass    = 0;
  this->dsphighpass   = 0;
  this->dspecho       = 0;
  this->dspflange     = 0;
  this->dspdistortion = 0;
  this->dspchorus     = 0;
  this->dspparameq    = 0;

  this->result = FMOD::System_Create(&system);
  ERRCHECK(result);

  result = system->getVersion(&version);
  ERRCHECK(result);

  if (version < FMOD_VERSION)
  {
    cout << "Error!  You are using an old version of FMOD" << version << ". This program requires " << FMOD_VERSION << endl;
    exit(-1);
  }

  result = system->init(32, FMOD_INIT_NORMAL, 0);
  ERRCHECK(result);

  result = system->createSound("assets/sounds/drumloop.wav", FMOD_SOFTWARE, 0, &sound);
  ERRCHECK(result);

  cout << "Press SPACE to paused/unpause sound." << endl;
  cout << "Press a to toggle dsplowpass effect." << endl;
  cout << "Press z to toggle dsphighpass effect" << endl;
  cout << "Press e to toggle dspecho effect." << endl;
  cout << "Press r to toggle dspflange effect." << endl;
  cout << "Press t to toggle dspdistortion effect." << endl;
  cout << "Press y to toggle dspchorus effect." << endl;
  cout << "Press u to toggle dspparameq effect." << endl;
  cout << "Press 'Esc' to quit" << endl;

  result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
  ERRCHECK(result);

  ////////////////////////////////////////
  //  Create some effects to play with  //
  ////////////////////////////////////////

  result = system->createDSPByType(FMOD_DSP_TYPE_LOWPASS, &dsplowpass);
  ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_HIGHPASS, &dsphighpass);
  ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dspecho);
  ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_FLANGE, &dspflange);
  ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_DISTORTION, &dspdistortion);
  ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_CHORUS, &dspchorus);
  ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_PARAMEQ, &dspparameq);
  ERRCHECK(result);

}

void Engine::run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done)
{
  Event(windowManager, screenWidth, screenHeight, done);  

        system->update();

        bool paused = 0;
        bool dsplowpass_active;
        bool dsphighpass_active;
        bool dspecho_active;
        bool dspflange_active;
        bool dspdistortion_active;
        bool dspchorus_active;
        bool dspparameq_active;

        dsplowpass   ->getActive(&dsplowpass_active);
        dsphighpass  ->getActive(&dsphighpass_active);
        dspecho      ->getActive(&dspecho_active);
        dspflange    ->getActive(&dspflange_active);
        dspdistortion->getActive(&dspdistortion_active);
        dspchorus    ->getActive(&dspchorus_active);
        dspparameq   ->getActive(&dspparameq_active);

        if (channel)
        {
            result = channel->getPaused(&paused);
            if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
            {
                ERRCHECK(result);
            }
        }

        /*cout << (paused               ? "Paused" : "Playing") 
             << (dsplowpass_active    ? "x" : " ")
             << (dsphighpass_active   ? "x" : " ")
             << (dspecho_active       ? "x" : " ")
             << (dspflange_active     ? "x" : " ")
             << (dspdistortion_active ? "x" : " ")
             << (dspchorus_active     ? "x" : " ")
             << (dspparameq_active    ? "x" : " ")
        << endl;*/

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        windowManager->swapBuffers();
}

void stop()
{
  /*result = sound->release();
  ERRCHECK(result);
  result = system->close();
  ERRCHECK(result);
  result = system->release();
  ERRCHECK(result);*/
}

void Engine::Event(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done)
{
  SDL_Event e;
  while(windowManager->pollEvent(e))
  {
    if(e.type == SDL_QUIT) {
      (*done) = true; // Leave the loop after this iteration
    }
    switch( e.type )
    {
      case SDL_KEYDOWN:
              
        //QUIT
        if(windowManager->isKeyPressed(SDLK_ESCAPE))
        {
          (*done) = true;
        }

        //PLAY/PAUSE
        if(windowManager->isKeyPressed(SDLK_SPACE))
        {
          bool paused;

          channel->getPaused(&paused);
          ERRCHECK(result);

          paused = !paused;

          result = channel->setPaused(paused);
          ERRCHECK(result);
        }

        //LOWPASS
        if(windowManager->isKeyPressed(SDLK_a))
        {
          bool active;

          result = dsplowpass->getActive(&active);
          ERRCHECK(result);

          if (active)
          {
              result = dsplowpass->remove();
              ERRCHECK(result);
          }
          else
            {
                result = system->addDSP(dsplowpass, 0);
                ERRCHECK(result);
            }
          }

          //HIGHPASS
          if(windowManager->isKeyPressed(SDLK_z))
          {
            bool active;

            result = dsphighpass->getActive(&active);
            ERRCHECK(result);

            if (active)
            {
                result = dsphighpass->remove();
                ERRCHECK(result);
            }
            else
            {
                result = system->addDSP(dsphighpass, 0);
                ERRCHECK(result);
            }
          }

          //ECHO
          if(windowManager->isKeyPressed(SDLK_e))
          {
            bool active;

            result = dspecho->getActive(&active);
            ERRCHECK(result);

            if (active)
            {
                result = dspecho->remove();
                ERRCHECK(result);
            }
            else
            {
                result = system->addDSP(dspecho, 0);
                ERRCHECK(result);

                result = dspecho->setParameter(FMOD_DSP_ECHO_DELAY, 50.0f);
                ERRCHECK(result);
            }
          }

          if(windowManager->isKeyPressed(SDLK_r))
          {
            bool active;

            result = dspflange->getActive(&active);
            ERRCHECK(result);

            if (active)
            {
                result = dspflange->remove();
                ERRCHECK(result);
            }
            else
            {
                result = system->addDSP(dspflange, 0);
                ERRCHECK(result);
            }
          }

          if(windowManager->isKeyPressed(SDLK_t))
          {
            bool active;

            result = dspdistortion->getActive(&active);
            ERRCHECK(result);

            if (active)
            {
                result = dspdistortion->remove();
                ERRCHECK(result);
            }
            else
            {
                result = system->addDSP(dspdistortion, 0);
                ERRCHECK(result);

                result = dspdistortion->setParameter(FMOD_DSP_DISTORTION_LEVEL, 0.8f);
                ERRCHECK(result);
            }
          }

          if(windowManager->isKeyPressed(SDLK_y))
              {
            bool active;

            result = dspchorus->getActive(&active);
            ERRCHECK(result);

            if (active)
            {
                result = dspchorus->remove();
                ERRCHECK(result);
            }
            else
            {
                result = system->addDSP(dspchorus, 0);
                ERRCHECK(result);
            }
          }

          if(windowManager->isKeyPressed(SDLK_u))
          {
            bool active;

            result = dspparameq->getActive(&active);
            ERRCHECK(result);

            if (active)
            {
                result = dspparameq->remove();
                ERRCHECK(result);
            }
            else
            {
                result = system->addDSP(dspparameq, 0);
                ERRCHECK(result);

                result = dspparameq->setParameter(FMOD_DSP_PARAMEQ_CENTER, 5000.0f);
                ERRCHECK(result);
                result = dspparameq->setParameter(FMOD_DSP_PARAMEQ_GAIN, 0.0f);
                ERRCHECK(result);
            }
          }
      break;
    }
  }
}

void Engine::ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << endl;
        exit(-1);
    }
}