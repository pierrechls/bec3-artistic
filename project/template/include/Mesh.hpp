#pragma once 

#include <vector>
#include <sstream>
#include <string>
#include "Texture.hpp"
#include "Vertex.hpp"
#include "Shader.hpp"

using namespace std;

class Mesh {
    public:
        vector<Vertex> vertices;
        vector<GLuint> indices;
        vector<Texture> textures;
        GLuint VAO;
        
        Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
        void Draw(Shader shader);
    private:
        GLuint VBO, EBO;
        
        void setupMesh();
};  
