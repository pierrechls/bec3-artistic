#include "Engine.hpp"

using namespace std;
using namespace glimac;

Engine::Engine(){}

void Engine::run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done)
{
  
  ///////////////////
  /*   SDL EVENTS  */
  ///////////////////
  
  Event(windowManager, screenWidth, screenHeight, done);  


  ///////////////////
  /*  FMOD SOUNDS  */
  ///////////////////
  
  _Sound.update();
  for(int i = 0; i < NOMBRE_CHANNEL; i++) //Get frequencies for all sounds
  {
    frequencies[ i ] = _Sound.getFrequencyChannel( i );
  }

  ///////////////////
  /* DRAW GRAPHICS */
  ///////////////////

  glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _Graphics.draw( frequencies, 800.0f, 600.0f );

  windowManager->swapBuffers();
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

        //GROUP A
        if(windowManager->isKeyPressed(SDLK_a))
        {
          _Sound.Event("a");
          _Graphics.Event("a");
        }

        //GROUP B
        if(windowManager->isKeyPressed(SDLK_b))
        {
          _Sound.Event("b");
          _Graphics.Event("b");
        }

        //GROUP C
        if(windowManager->isKeyPressed(SDLK_c))
        {
          _Sound.Event("c");
          _Graphics.Event("c");
        }

        //GROUP E
        if(windowManager->isKeyPressed(SDLK_d))
        {
          _Sound.Event("d");
          _Graphics.Event("d");
        }

        //GROUP E
        if(windowManager->isKeyPressed(SDLK_e))
        {
          _Sound.Event("e");
          _Graphics.Event("e");
        }

        //ACTIVE OR NOT FLANGER EFFECT
        if(windowManager->isKeyPressed(SDLK_f))
        {
          _Sound.Event("f");
        }

        //ACTIVE OR NOT LOWPASS EFFECT
        if(windowManager->isKeyPressed(SDLK_l))
        {
          _Sound.Event("l");
        }
      break;
    }
  }
}

void Engine::stop()
{
  _Sound.stop();
}