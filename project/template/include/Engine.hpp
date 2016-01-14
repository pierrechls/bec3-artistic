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

#include "Form.hpp"
#include "Sound.hpp"

using namespace std;
using namespace glimac;

class Engine
{
    public:

      Engine();
      void run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);
    
    private:
      Sound _Sound;
      Form _Form;
      float frequency;

      void Event(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);

};

