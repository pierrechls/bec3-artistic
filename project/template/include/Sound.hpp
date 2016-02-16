#pragma once

#include "wincompat.h"
#include <fmodex/fmod.hpp>
#include <fmodex/fmod_dsp.h>
#include <fmodex/fmod_errors.h>

#define TAILLE_SPECTRE 512
#define NOMBRE_SOUND   6
#define NOMBRE_CHANNEL 6


class Sound
{
    public:

      Sound();
      void  update();
      void  stop();
      void  Event(string touch);
      float getFrequencyChannel(int numberChannel);

    private:

      FMOD::System       *system;
      FMOD::Sound        *sound[NOMBRE_SOUND];
      FMOD::Channel      *channel[NOMBRE_CHANNEL];
      FMOD::ChannelGroup *groupA, *groupB, *groupC, *groupD, *groupE, *masterGroup;
      FMOD::DSP          *dspflange, *dsplowpass;
      FMOD_RESULT        result;

      int                nb_SoundGroupA, nb_SoundGroupB, nb_SoundGroupC, nb_SoundGroupD, nb_SoundGroupE;

      int                 count;
      unsigned int        version;

      float               spectreChannel1[ TAILLE_SPECTRE ],
                          spectreChannel2[ TAILLE_SPECTRE ],
                          spectreChannel3[ TAILLE_SPECTRE ],
                          spectreChannel4[ TAILLE_SPECTRE ],
                          spectreChannel5[ TAILLE_SPECTRE ],
                          spectreChannel6[ TAILLE_SPECTRE ];

      void ERRCHECK(FMOD_RESULT result);

};

