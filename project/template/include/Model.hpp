#pragma once
#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.hpp"
#include "Texture.hpp"
#include <glimac/Image.hpp>

class Model 
{
    public:
        Model();
        Model(std::string path);
        void Draw(Shader shader);
        std::vector<Mesh> meshes;
        std::vector<Texture> textures_loaded;

    private:
        
        std::string directory;
        void loadModel(std::string path);
        void processNode(aiNode* node, const aiScene* scene);
        Mesh processMesh(aiMesh* mesh, const aiScene* scene);
        GLint TextureFromFile(const char* path, std::string directory);
        std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};
