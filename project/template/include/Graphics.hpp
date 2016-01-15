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

class Graphics{

public:

	Graphics();
	void draw(float frequence);

private:

	Form _Form;

};