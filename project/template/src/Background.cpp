#include "Background.hpp"
#include <iostream>
#include <string>

Background::Background(){

	this->shaderTexture = Shader("template/shaders/FormTexture.vs.glsl", "template/shaders/FormTexture.fs.glsl");
    
    ////////////////////////////
    /*  INITIALIZE POSITIONS  */
    ////////////////////////////

    GLfloat NewVertices[] = {
        // Positions          // Colors           // Texture Coords
         1.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         1.0f, -1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -1.0f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
    };

    for(unsigned int i = 0; i < 32; i++)
	{	
		this->vertices[i] = NewVertices[i];
	}

    GLuint NewIndices[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    for(unsigned int j = 0; j < 6; j++)
	{	
		this->indices[j] = NewIndices[j];
	}
    
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);


    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), this->indices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0); // Unbind VAO


    ////////////////////////////
    /*      ADD TEXTURES      */
    ////////////////////////////


    // Load and create a texture
    glGenTextures(1, &this->TextureBlack);
    glBindTexture(GL_TEXTURE_2D, this->TextureBlack); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //Load texture HUD
    this->HUDtextures["BG_Black"] = loadImage("assets/textures/bg_black.png");
    if (this->HUDtextures["BG_Black"] == NULL) std::cout << "Texture HUD non chargé" << std::endl;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->HUDtextures["BG_Black"]->getWidth(),this->HUDtextures["BG_Black"]->getHeight(), 0, GL_RGBA, GL_FLOAT, this->HUDtextures["BG_Black"]->getPixels());
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.


    // Load and create a texture
    glGenTextures(1, &this->TextureWhite);
    glBindTexture(GL_TEXTURE_2D, this->TextureWhite); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //Load texture HUD
    this->HUDtextures["BG_White"] = loadImage("assets/textures/bg_white.png");
    if (this->HUDtextures["BG_White"] == NULL) std::cout << "Texture HUD non chargé" << std::endl;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->HUDtextures["BG_White"]->getWidth(),this->HUDtextures["BG_White"]->getHeight(), 0, GL_RGBA, GL_FLOAT, this->HUDtextures["BG_White"]->getPixels());
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.


    this->TextureActual = TextureWhite;

}

void Background::draw(float frequence, float multi)
{
    // Bind Texture
    if(frequence > 0.048)
    {
        if( this->TextureActual == this->TextureBlack ) this->TextureActual = this->TextureWhite;
        else this->TextureActual = this->TextureBlack;
    }   

    glBindTexture(GL_TEXTURE_2D, this->TextureActual);
        
    this->shaderTexture.Use();

    GLuint transformLoc = glGetUniformLocation(this->shaderTexture.Program, "transform");
    
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::scale(trans, glm::vec3( 1.05f , 1.05f , 1.05f ));  
    
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    // Draw container
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);


}