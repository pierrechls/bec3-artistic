#include "Graphics.hpp"
#include <iostream>
#include <string>

Graphics::Graphics()
{
}


void Graphics::draw(float frequence)
{
    _Form.draw(frequence);
    _Form.drawCircle(frequence, 300);
    _Form.drawCircle(frequence, 600);
}