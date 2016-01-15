#include "Graphics.hpp"
#include <iostream>
#include <string>

Graphics::Graphics()
{
}


void Graphics::draw(float* frequencies)
{
    setfrequenciesChannel(frequencies);

    _Form.draw( frequenciesChannel[1] );
    _Form.drawCircle(frequenciesChannel[1], 600);
    _Form.drawCircle(frequenciesChannel[1], 900);
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
    
}