#include "Graphics.hpp"
#include <iostream>
#include <string>

Graphics::Graphics()
{
	groupA = false;
	groupB = true;
	groupC = false;
	groupD = false;
	groupE = false;
}


void Graphics::draw(float* frequencies)
{
    setfrequenciesChannel(frequencies);

    //if(groupA) _Square.draw( frequenciesChannel[0] );


    _Triangle.draw(frequencies[2]);

    //Draw circle with bass (channel 3, groupe B)
    _Circle.draw(frequenciesChannel[2], 1.0);
    _Circle.draw(frequenciesChannel[2], 0.2);
    _Circle.draw(frequenciesChannel[2], 0.5);
    
    //Draw background with music (channel 0, groupe A)
    if(groupA) _Background.draw(frequenciesChannel[ 2 ], 900);
}

void Graphics::setfrequenciesChannel(float* newFrequenciesChannel)
{
	for(int i = 0; i < NOMBRE_CHANNEL; i++)
	{
		frequenciesChannel[i] = newFrequenciesChannel[i];
	}
}

void Graphics::Event(string touch)
{
  /////////////////////////
  /*   DISPLAY GROUPE    */
  /////////////////////////

  if( touch == "a" ) groupA = !groupA;
  if( touch == "b" ) groupB = !groupB;
  if( touch == "c" ) groupC = !groupC;
  if( touch == "d" ) groupD = !groupD;
  if( touch == "e" ) groupE = !groupE;
}