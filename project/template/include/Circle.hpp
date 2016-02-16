#pragma once
#include <glimac/Image.hpp>
#include <string>
#include <map>
#include "Shader.hpp"


class Circle{

public:

	Shader shaderTexture;

	Circle();
	void draw(float frequence, float multi);
private:

	std::unique_ptr<glimac::Image>                        HUDtexture;
	std::map<std::string, std::unique_ptr<glimac::Image>> HUDtextures;

	GLuint  VBO, VAO, EBO;
	GLuint  Textures;
	GLfloat vertices[32];
	GLuint  indices[6];

};