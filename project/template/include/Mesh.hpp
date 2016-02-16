#pragma once 

#include <vector>
#include "Texture.hpp"
#include "Vertex.hpp"
#include "Shader.hpp"

class Mesh {
    public:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        std::vector<Texture> textures;
        GLuint VAO;
        
        Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
        void Draw(Shader shader);
    private:
        GLuint VBO, EBO;
        void setupMesh();
};  
