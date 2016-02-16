#pragma once

#include <glimac/SDLWindowManager.hpp>
#include <Bec3-lib/Bec3.hpp>
#include "Graphics.hpp"
#include "Sound.hpp"

#define NOMBRE_CHANNEL 6

class Engine
{
    public:

      Engine();
      void run(glimac::SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);
      void stop();
      
    private:
      Bec3 mySession;

      bool stateLightA, stateLightB, stateLightC, stateLightD, stateLightE;

      Sound     _Sound;
      Graphics  _Graphics;
      float frequencies [ NOMBRE_CHANNEL ];
      void Event(glimac::SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);

};

