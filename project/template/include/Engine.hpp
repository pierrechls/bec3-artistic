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

#include "Shader.hpp"
#include "Form.hpp"

using namespace std;
using namespace glimac;

#define TAILLE_SPECTRE 512


class Engine
{
    public:

      FMOD::System       *system;
      FMOD::Sound        *sound[5];
      FMOD::Channel      *channel[5];
      FMOD::ChannelGroup *groupA, *groupB, *masterGroup;
      FMOD::DSP          *dspreverb, *dspflange, *dsplowpass;
      FMOD_RESULT         result;
      int                 key, count;
      unsigned int        version;

      float spectre[ TAILLE_SPECTRE ];


      Form _Form;

      Engine();
      void run(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);
      void stop();
      void Event(SDLWindowManager* windowManager, GLuint screenWidth, GLuint screenHeight, bool* done);
      void ERRCHECK(FMOD_RESULT result);
    private:

};

