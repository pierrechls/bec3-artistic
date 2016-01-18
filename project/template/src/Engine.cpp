#include "Engine.hpp"

using namespace std;
using namespace glimac;

Engine::Engine(){}

void Engine::run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done)
{
  
  //Event SDL Key
  Event(windowManager, screenWidth, screenHeight, done);  

  //Update Sound
  _Sound.update();
  
  //Get frequencies for all sounds
  for(int i = 0; i < NOMBRE_CHANNEL; i++)
  {
    frequencies[ i ] = _Sound.getFrequencyChannel( i );
  }

  ///////////////////
  /* DRAW GRAPHICS */
  ///////////////////

  glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _Graphics.draw( frequencies );

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

        //LOWPASS
        if(windowManager->isKeyPressed(SDLK_a))
        {
          _Sound.Event("a");
          _Graphics.Event("a");
        }

        //HIGHPASS
        if(windowManager->isKeyPressed(SDLK_b))
        {
          _Sound.Event("b");
          _Graphics.Event("b");
        }

        //LOWPASS
        if(windowManager->isKeyPressed(SDLK_c))
        {
          _Sound.Event("c");
          _Graphics.Event("c");
        }

        //HIGHPASS
        if(windowManager->isKeyPressed(SDLK_d))
        {
          _Sound.Event("d");
          _Graphics.Event("d");
        }

        //LOWPASS
        if(windowManager->isKeyPressed(SDLK_e))
        {
          _Sound.Event("e");
          _Graphics.Event("e");
        }

        //ECHO
        if(windowManager->isKeyPressed(SDLK_r))
        {
          _Sound.Event("r");
        }

        if(windowManager->isKeyPressed(SDLK_f))
        {
          _Sound.Event("f");
        }

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