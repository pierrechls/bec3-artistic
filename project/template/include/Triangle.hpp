#pragma once

#include "glimac/glm.hpp"
#include <GL/glew.h>
#include "Shader.hpp"

class Triangle{

public:

	Shader shaderColor;

	Triangle();
	void draw(float frequence);
	
private:

	int cptRandom;
	float randomPosition[16];


	GLuint  VBO, VAO;
	GLfloat vertices[9];

};