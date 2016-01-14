#include "Engine.hpp"

using namespace std;
using namespace glimac;

Engine::Engine()
{
  
  ///////////////////////////////////////////
  /* Create a System object and initialize */
  ///////////////////////////////////////////

  result = FMOD::System_Create(&system);
  ERRCHECK(result);

  result = system->getVersion(&version);
  ERRCHECK(result);

  if (version < FMOD_VERSION)
  {
      cout << "Error!  You are using an old version of FMOD " << version << ". This program requires " << FMOD_VERSION << endl;
      exit(1);
  }

  result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);

    result = system->createSound("assets/sounds/drumloop.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[0]);
    ERRCHECK(result);
    result = system->createSound("assets/sounds/jaguar.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[1]);
    ERRCHECK(result);
    result = system->createSound("assets/sounds/c.ogg", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[2]);
    ERRCHECK(result);
    result = system->createSound("assets/sounds/d.ogg", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[3]);
    ERRCHECK(result);
    result = system->createSound("assets/sounds/e.ogg", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[4]);
    ERRCHECK(result);

    result = system->createChannelGroup("Group A", &groupA);
    ERRCHECK(result);

    result = system->createChannelGroup("Group B", &groupB);
    ERRCHECK(result);

    result = system->getMasterChannelGroup(&masterGroup);
    ERRCHECK(result);

    result = masterGroup->addGroup(groupA);
    ERRCHECK(result);

    result = masterGroup->addGroup(groupB);
    ERRCHECK(result);

    cout << "                                                       (drumloop.wav)" << endl;
    cout << "                                                      /              " << endl;
    cout << "                                              (groupA)               " << endl;
    cout << "                                     (reverb)/        \\             " << endl;
    cout << "                                    /                  (jaguar.wav)  " << endl;
    cout << "(soundcard)--(lowpass)--(mastergroup)                                " << endl;
    cout << "                                    \\                  (c.ogg)      " << endl;
    cout << "                                     (flange)         /              " << endl;
    cout << "                                             \\(groupB)--(d.ogg)     " << endl;
    cout << "                                                      \\             " << endl;
    cout << "                                                       (e.ogg)       " << endl;
    cout << "Press 'A' to mute/unmute group A" << endl;
    cout << "Press 'B' to mute/unmute group B" << endl;
    cout << " " << endl;
    cout << "Press 'R' to place reverb on group A" << endl;
    cout << "Press 'F' to place flange on group B" << endl;
    cout << "Press 'L' to place lowpass on master group (everything)" << endl;
    cout << "Press 'Esc' to quit" << endl;
    cout << "" << endl;

  
    ///////////////////////////
    /* Start all the sounds! */
    ///////////////////////////

    for (count = 0; count < 5; count++)
    {
        result = system->playSound(FMOD_CHANNEL_FREE, sound[count], true, &channel[count]);
        ERRCHECK(result);
        if (count < 2)
        {
            result = channel[count]->setChannelGroup(groupA);
        }
        else
        {
            result = channel[count]->setChannelGroup(groupB);
        }
        ERRCHECK(result);
        result = channel[count]->setPaused(false);
        ERRCHECK(result);
    }

    /////////////////////////////////////////////////////////////
    /* Create the DSP effects we want to apply to our submixes */
    /////////////////////////////////////////////////////////////

    result = system->createDSPByType(FMOD_DSP_TYPE_SFXREVERB, &dspreverb);
    ERRCHECK(result);

    result = system->createDSPByType(FMOD_DSP_TYPE_FLANGE, &dspflange);
    ERRCHECK(result);
    result = dspflange->setParameter(FMOD_DSP_FLANGE_RATE, 1.0f);
    ERRCHECK(result);

    result = system->createDSPByType(FMOD_DSP_TYPE_LOWPASS, &dsplowpass);
    ERRCHECK(result);
    result = dsplowpass->setParameter(FMOD_DSP_LOWPASS_CUTOFF, 500.0f);
    ERRCHECK(result);

}

void Engine::run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done)
{
  Event(windowManager, screenWidth, screenHeight, done);  

        system->update();

        int  channelsplaying = 0;

        system->getChannelsPlaying(&channelsplaying);

        printf("Channels Playing %2d\r", channelsplaying);

        fflush(stdout);
        Sleep(10);

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

        //LOWPASS
        if(windowManager->isKeyPressed(SDLK_a))
        {
          static bool mute = true;
          groupA->setMute(mute);
          mute = !mute;
        }

        //HIGHPASS
        if(windowManager->isKeyPressed(SDLK_b))
        {
          static bool mute = true;
          groupB->setMute(mute);
          mute = !mute;
        }

        //ECHO
        if(windowManager->isKeyPressed(SDLK_r))
        {
          static bool reverb = true;
          
          if (reverb)
          {
            groupA->addDSP(dspreverb, 0);
          }
          else
          {
            dspreverb->remove();
          }

          reverb = !reverb;
        }

        if(windowManager->isKeyPressed(SDLK_f))
        {
          static bool flange = true;
          if (flange)
          {
            groupB->addDSP(dspflange, 0);
          }
          else
          {
            dspflange->remove();
          }

          flange = !flange;
        }

        if(windowManager->isKeyPressed(SDLK_l))
        {
          static bool lowpass = true;
          if (lowpass)
          {
            masterGroup->addDSP(dsplowpass, 0);
          }
          else
          {
            dsplowpass->remove();
          }

          lowpass = !lowpass;
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