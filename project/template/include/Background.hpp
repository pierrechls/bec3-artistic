#pragma once
#include <glimac/Image.hpp>
#include <string>
#include <map>
#include "Shader.hpp"

class Background{

public:

	Shader shaderTexture;

	Background();
	void draw(float frequence, float multi);
private:

	std::unique_ptr <glimac::Image>                        HUDtexture;
	std::map <std::string, std::unique_ptr<glimac::Image>> HUDtextures;

	GLuint  VBO, VAO, EBO;
	GLuint  TextureBlack;
	GLuint  TextureWhite;
	GLuint  TextureActual;

	GLfloat vertices[32];
	GLuint  indices[6];

};