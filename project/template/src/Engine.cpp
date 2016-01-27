#include "Engine.hpp"
#include <glimac/Program.hpp>

using namespace std;
using namespace glimac;

Engine::Engine(){
  mySession.initFromFile("assets/conf/Bec3.json");
  stateLightA = stateLightB = stateLightC = stateLightD = stateLightE = false;
}

void Engine::run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done)
{
  ///////////////////
  /*   SDL EVENTS  */
  ///////////////////
  mySession.updateObjects();
  
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
  _Graphics.draw( frequencies, 800.0f, 600.0f);

  windowManager->swapBuffers();
}

void Engine::Event(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done)
{
  SDL_Event e;
  while(windowManager->pollEvent(e))
  {
    if(e.type == SDL_QUIT) {
      (*done) =  true; // Leave the loop after this iteration
    }

    switch( e.type )
    {
      case SDL_KEYDOWN:
              
        //QUIT
        if(windowManager->isKeyPressed(SDLK_ESCAPE))
        {
          (*done) =  true;
        }

      break;
    }
  }

  //GROUP A
  if( mySession.getObjectState( "LightA" ).getBool() != stateLightA )
  {
    stateLightA = !stateLightA;
    _Sound.Event("GroupA");
    _Graphics.Event("GroupA");
  }

  //GROUP B
  if( mySession.getObjectState( "LightB" ).getBool() != stateLightB )
  {
    stateLightB = !stateLightB;
    _Sound.Event("GroupB");
    _Graphics.Event("GroupB");
  }

  //GROUP C
  if( mySession.getObjectState( "LightC" ).getBool() != stateLightC )
  {
    stateLightC = !stateLightC;
    _Sound.Event("GroupC");
    _Graphics.Event("GroupC");
  }

  //GROUP D
  if( mySession.getObjectState( "LightD" ).getBool() != stateLightD )
  {
    stateLightD = !stateLightD;
    _Sound.Event("GroupD");
    _Graphics.Event("GroupD");
  }

  //GROUP E
  if( mySession.getObjectState( "LightE" ).getBool() != stateLightE )
  {
    stateLightE = !stateLightE;
    _Sound.Event("GroupE");
    _Graphics.Event("GroupE");
  }

}

void Engine::stop()
{
  _Sound.stop();
}