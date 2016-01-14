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

#include "wincompat.h"
#include <fmodex/fmod.hpp>
#include <fmodex/fmod_dsp.h>
#include <fmodex/fmod_errors.h>

//#include "Shader.hpp"
//#include "Sound.hpp"

using namespace std;
using namespace glimac;


class Engine
{
    public:

      FMOD::System     *system;
      FMOD::Sound      *sound;
      FMOD::Channel    *channel;
      FMOD::DSP        *dsplowpass;
      FMOD::DSP        *dsphighpass;
      FMOD::DSP        *dspecho;
      FMOD::DSP        *dspflange;
      FMOD::DSP        *dspdistortion;
      FMOD::DSP        *dspchorus;
      FMOD::DSP        *dspparameq;
      FMOD_RESULT       result;
      unsigned int      version;

      Engine();
      void run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);
      void stop();
      void ERRCHECK(FMOD_RESULT result);
    private:

};

