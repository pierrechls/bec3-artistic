#pragma once
#include <GL/glew.h>
#include <string>
#include <assimp/scene.h>

using namespace std;

struct Texture {
    GLuint id;
    string type;
    aiString path;
}; 
