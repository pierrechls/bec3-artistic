#pragma once
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Image.hpp>
#include <glimac/FilePath.hpp>

#include <GL/glew.h>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>

#include "Graphics.hpp"
#include "Sound.hpp"

using namespace std;
using namespace glimac;

class Engine
{
    public:

      Engine();
      void run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);
      void stop();
      
    private:
      Sound     _Sound;
      Graphics  _Graphics;
      float frequency;

      void Event(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);

};

