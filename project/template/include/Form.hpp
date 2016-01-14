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

class Form{

public:

	Shader shader;

	Form();
	void draw(SDLWindowManager* windowManager, float screenWidth, float screenHeight, float frequence);

private:

	std::unique_ptr<Image>              HUDtexture;
	map<string, std::unique_ptr<Image>> HUDtextures;

	GLuint  VBO, VAO, EBO;
	GLuint  Textures;
	GLfloat vertices[32];
	GLuint  indices[6];

};