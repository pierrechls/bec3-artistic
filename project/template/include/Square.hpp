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

class Square{

public:

	Shader shaderColor;

	Square();
	void draw(float frequence);
	
private:

	GLuint  VBO, VAO, EBO;
	GLfloat vertices[32];
	GLuint  indices[6];

};