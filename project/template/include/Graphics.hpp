#pragma once
#include "glimac/glm.hpp"
#include <glimac/SDLWindowManager.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <GL/glew.h>
#include "Shader.hpp"
#include "Form.hpp"

using namespace std;
using namespace glimac;
using namespace glm;

#define NOMBRE_CHANNEL 6

class Graphics{

public:

	Graphics();
	void draw(float* frequencies);
	void Event(string touch);

private:
	float frequenciesChannel[ NOMBRE_CHANNEL ];
	void setfrequenciesChannel(float* newFrequenciesChannel);
	Form _Form;

};