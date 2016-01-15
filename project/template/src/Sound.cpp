#include "Engine.hpp"

using namespace std;
using namespace glimac;

Sound::Sound()
{
  
  ///////////////////////////////////////////
  /* Create a System object and initialize */
  ///////////////////////////////////////////

  result = FMOD::System_Create(&system);
  ERRCHECK(result);

  result = system->getVersion(&version);
  ERRCHECK(result);

  if (version < FMOD_VERSION)
  {
      cout << "Error!  You are using an old version of FMOD " << version << ". This program requires " << FMOD_VERSION << endl;
      exit(1);
  }

  result = system->init(32, FMOD_INIT_NORMAL, 0);
  ERRCHECK(result);


  ///////////////////////////////
  /*       IMPORT SOUNDS       */
  ///////////////////////////////

  //SOUNDS TO CHANNEL A (NB = 2)
  nb_SoundGroupA = 2;
  result = system->createSound("assets/sounds/BASS_Kombi2.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[0]); ERRCHECK(result);
  result = system->createSound("assets/sounds/DRUMS_MidiClap1.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[1]); ERRCHECK(result);
  
  //SOUNDS TO CHANNEL B (NB = 1)
  nb_SoundGroupB = 1;
  result = system->createSound("assets/sounds/BEAT_JetBd2.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[2]); ERRCHECK(result);

  //SOUNDS TO CHANNEL C (NB = 1)
  nb_SoundGroupC = 1;
  result = system->createSound("assets/sounds/SOUND_JetPad2.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[3]); ERRCHECK(result);

  //SOUNDS TO CHANNEL D (NB = 1)
  nb_SoundGroupD = 1;
  result = system->createSound("assets/sounds/SOUND_Kull.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[4]); ERRCHECK(result);

  //SOUNDS TO CHANNEL E (NB = 1)
  nb_SoundGroupE = 1;
  result = system->createSound("assets/sounds/SOUND_Nord.wav", FMOD_SOFTWARE | FMOD_LOOP_NORMAL, 0, &sound[5]); ERRCHECK(result);


  ///////////////////////////////
  /*      CREATE CHANNELS      */
  ///////////////////////////////

  //CREATE CHANNELS
  result = system->createChannelGroup("Group A", &groupA); ERRCHECK(result);
  result = system->createChannelGroup("Group B", &groupB); ERRCHECK(result);
  result = system->createChannelGroup("Group C", &groupC); ERRCHECK(result);
  result = system->createChannelGroup("Group D", &groupD); ERRCHECK(result);
  result = system->createChannelGroup("Group E", &groupE); ERRCHECK(result);


  ///////////////////////////////
  /*       ADD TO MASTER       */
  ///////////////////////////////

  result = system->getMasterChannelGroup(&masterGroup); ERRCHECK(result);
  
  result = masterGroup->addGroup(groupA); ERRCHECK(result);
  result = masterGroup->addGroup(groupB); ERRCHECK(result);
  result = masterGroup->addGroup(groupC); ERRCHECK(result);
  result = masterGroup->addGroup(groupD); ERRCHECK(result);
  result = masterGroup->addGroup(groupE); ERRCHECK(result);
  
  cout << "Press 'A' to mute/unmute group A" << endl;
  cout << "Press 'B' to mute/unmute group B" << endl;
  cout << " " << endl;
  cout << "Press 'R' to place reverb on group A" << endl;
  cout << "Press 'F' to place flange on group B" << endl;
  cout << "Press 'L' to place lowpass on master group (everything)" << endl;
  cout << "Press 'Esc' to quit" << endl;
  cout << "" << endl;

  
  ///////////////////////////////
  /*       START SOUNDS        */
  ///////////////////////////////

  for (count = 0; count < NOMBRE_CHANNEL ; count++)
  {
    result = system->playSound(FMOD_CHANNEL_FREE, sound[count], true, &channel[count]);
    ERRCHECK(result);

    if (count < nb_SoundGroupA ){
      result = channel[count]->setChannelGroup(groupA);
    }


    else if ( count < nb_SoundGroupA + nb_SoundGroupB ){
      result = channel[count]->setChannelGroup(groupB);
    }

    else if ( count < nb_SoundGroupA + nb_SoundGroupB + nb_SoundGroupC ){
      result = channel[count]->setChannelGroup(groupC);
    }
    
    else if ( count < nb_SoundGroupA + nb_SoundGroupB + nb_SoundGroupC + nb_SoundGroupD ){
      result = channel[count]->setChannelGroup(groupD);
    }
    
    else if ( count < nb_SoundGroupA + nb_SoundGroupB + nb_SoundGroupC + nb_SoundGroupD + nb_SoundGroupE ){
      result = channel[count]->setChannelGroup(groupE);
    }

    ERRCHECK(result);

    result = channel[count]->setPaused(false); ERRCHECK(result);
  }

  static bool mute = true;
  groupA->setMute(mute);
  groupC->setMute(mute);
  groupD->setMute(mute);
  groupE->setMute(mute);
  mute = !mute;


  ///////////////////////////////
  /*       CREATE EFFECT       */
  ///////////////////////////////

  result = system->createDSPByType(FMOD_DSP_TYPE_SFXREVERB, &dspreverb); ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_FLANGE, &dspflange); ERRCHECK(result);
  result = dspflange->setParameter(FMOD_DSP_FLANGE_RATE, 1.0f); ERRCHECK(result);
  result = system->createDSPByType(FMOD_DSP_TYPE_LOWPASS, &dsplowpass); ERRCHECK(result);
  result = dsplowpass->setParameter(FMOD_DSP_LOWPASS_CUTOFF, 500.0f); ERRCHECK(result);

}

void Sound::update()
{
  system->update();
  int  channelsplaying = 0;
  system->getChannelsPlaying(&channelsplaying);

  //On récupère les fréqunces du spectre
  result = channel[0]->getSpectrum(spectreChannel1, TAILLE_SPECTRE, 0, FMOD_DSP_FFT_WINDOW_RECT); ERRCHECK(result);
  result = channel[1]->getSpectrum(spectreChannel2, TAILLE_SPECTRE, 0, FMOD_DSP_FFT_WINDOW_RECT); ERRCHECK(result);
  result = channel[2]->getSpectrum(spectreChannel3, TAILLE_SPECTRE, 0, FMOD_DSP_FFT_WINDOW_RECT); ERRCHECK(result);
  result = channel[3]->getSpectrum(spectreChannel4, TAILLE_SPECTRE, 0, FMOD_DSP_FFT_WINDOW_RECT); ERRCHECK(result);
  result = channel[4]->getSpectrum(spectreChannel5, TAILLE_SPECTRE, 0, FMOD_DSP_FFT_WINDOW_RECT); ERRCHECK(result);
  result = channel[5]->getSpectrum(spectreChannel6, TAILLE_SPECTRE, 0, FMOD_DSP_FFT_WINDOW_RECT); ERRCHECK(result);

  fflush(stdout);
  Sleep(10);
}

void Sound::stop()
{
  for (count = 0; count < NOMBRE_SOUND ; count++)
  {
    result = sound[count]->release();
    ERRCHECK(result);
  }

  result = dspreverb->release();  ERRCHECK(result);
  result = dspflange->release();  ERRCHECK(result);
  result = dsplowpass->release(); ERRCHECK(result);

  result = groupA->release(); ERRCHECK(result);
  result = groupB->release(); ERRCHECK(result);
  result = groupC->release(); ERRCHECK(result);
  result = groupD->release(); ERRCHECK(result);
  result = groupE->release(); ERRCHECK(result);

  result = system->close();   ERRCHECK(result);
  result = system->release(); ERRCHECK(result);
}

float Sound::getFrequencyChannel(int numberChannel)
{
       if(numberChannel == 1) return spectreChannel1 [258];
  else if(numberChannel == 2) return spectreChannel2 [258];
  else if(numberChannel == 3) return spectreChannel3 [258];
  else if(numberChannel == 4) return spectreChannel4 [258];
  else if(numberChannel == 5) return spectreChannel5 [258];
  else                        return spectreChannel6 [258];
}

void Sound::ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << endl;
        exit(-1);
    }
}

void Sound::Event(string touch)
{
  
  /////////////////////////
  /*     MUTE GROUPE     */
  /////////////////////////

  if( touch == "a" )
  {
    static bool mute = false;
    groupA->setMute(mute);
    mute = !mute;
  }
  
  if( touch == "b" )
  {
    static bool mute = true;
    groupB->setMute(mute);
    mute = !mute;
  }

  if( touch == "c" )
  {
    static bool mute = false;
    groupC->setMute(mute);
    mute = !mute;
  }

  if( touch == "d" )
  {
    static bool mute = false;
    groupD->setMute(mute);
    mute = !mute;
  }

  if( touch == "e" )
  {
    static bool mute = false;
    groupE->setMute(mute);
    mute = !mute;
  }

  /////////////////////////
  /*    EFFECTS GROUPE   */
  /////////////////////////

  if( touch == "r" || touch == "R")
  {
    static bool reverb = true;
          
    if (reverb)
    {
      groupA->addDSP(dspreverb, 0);
    }
    else
    {
      dspreverb->remove();
    }

    reverb = !reverb;
  }

  if( touch == "f" || touch == "F")
  {
    static bool flange = true;
    if (flange)
    {
      groupB->addDSP(dspflange, 0);
    }
    else
    {
      dspflange->remove();
    }

    flange = !flange;
  }

  if( touch == "l" || touch == "L")
  {
    static bool lowpass = true;
    if (lowpass)
    {
      masterGroup->addDSP(dsplowpass, 0);
    }
    else
    {
      dsplowpass->remove();
    }

    lowpass = !lowpass;
  }
}
