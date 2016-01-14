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

using namespace std;
using namespace glimac;

#define TAILLE_SPECTRE 512


class Sound
{
    public:

      Sound();
      void update();
      void stop();
      void Event(string touch);
      float getFrequency();

    private:

      FMOD::System       *system;
      FMOD::Sound        *sound[5];
      FMOD::Channel      *channel[5];
      FMOD::ChannelGroup *groupA, *groupB, *masterGroup;
      FMOD::DSP          *dspreverb, *dspflange, *dsplowpass;
      FMOD_RESULT         result;
      int                 count;
      unsigned int        version;

      float spectre[ TAILLE_SPECTRE ];

      void ERRCHECK(FMOD_RESULT result);

};

