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
#include "Square.hpp"
#include "Circle.hpp"
#include "Background.hpp"
#include "Triangle.hpp"

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

	bool groupA, groupB, groupC, groupD, groupE;

	float frequenciesChannel[ NOMBRE_CHANNEL ];
	void setfrequenciesChannel(float* newFrequenciesChannel);
	
	Square _Square;
	Circle _Circle;
	Triangle _Triangle;
	Background _Background;

};