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

    if(groupA) _Form.draw( frequenciesChannel[0] );
    _Circle.draw(frequenciesChannel[1], 600);
    
    _Background.draw(frequenciesChannel[1], 900);
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