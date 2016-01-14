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
  frequency = _Sound.getFrequency();


  ///////////////////
  /* DRAW GRAPHICS */
  ///////////////////

  glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _Form.draw(frequency);
  _Form.drawCircle();

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
        }

        //HIGHPASS
        if(windowManager->isKeyPressed(SDLK_b))
        {
          _Sound.Event("b");
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