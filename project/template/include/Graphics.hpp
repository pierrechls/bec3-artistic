#pragma once

#include "Shader.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Background.hpp"
#include "Triangle.hpp"
#include "Model.hpp"
#include "Camera.hpp"

#define NOMBRE_CHANNEL 6

class Graphics{

public:

	Graphics();
	void draw(float* frequencies, float screenWidth, float screenHeight);
	void Event(string touch);

private:

	bool groupA, groupB, groupC, groupD, groupE;

	float frequenciesChannel[ NOMBRE_CHANNEL ];
	void setfrequenciesChannel(float* newFrequenciesChannel);

	Square     _Square;
	Circle     _Circle;
	Triangle   _Triangle;
	Background _Background;

	Camera _Camera;

	Shader _ShaderModel;
	Model  _Model;

	float angle;

};