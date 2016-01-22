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

using namespace std;
using namespace glimac;
using namespace glm;

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