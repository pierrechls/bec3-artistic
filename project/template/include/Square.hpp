#pragma once

#include "glimac/glm.hpp"
#include <GL/glew.h>
#include "Shader.hpp"

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