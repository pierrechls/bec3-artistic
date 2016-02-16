#include "Triangle.hpp"

Triangle::Triangle(){

	this->shaderColor   = Shader("template/shaders/Color.vs.glsl", "template/shaders/Color.fs.glsl");

    GLfloat NewVertices[] = {
        // Positions        
         0.5f, -0.5f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  // Bottom Left
         0.0f,  0.5f, 0.0f   // Top 
    };

    for(unsigned int i = 0; i < 9; i++)
	{	
		this->vertices[i] = NewVertices[i];
	}

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0); // Unbind VAO

    float NewRandomPosition[] = {
        0.1f, 0.3f,
        -0.2f, 0.4f,
        -0.4f, 0.3f,
        -0.1f, -0.3f,
        0.1f, 0.1f,
        -0.2f, 0.2f,
        0.4f, -0.2f,
        -0.2f, -0.4f,
    };

    for(unsigned int i = 0; i < 16; i++)
    {   
        this->randomPosition[i] = NewRandomPosition[i];
    }

    this->cptRandom = 0;

}

void Triangle::draw(float frequence)
{
    
    this->shaderColor.Use();

    GLuint transformLoc = glGetUniformLocation(this->shaderColor.Program, "transform");
    
    glm::mat4 trans;

    trans  = glm::translate(trans, glm::vec3( randomPosition[ cptRandom ], randomPosition[ cptRandom + 1 ], 1.0f));
    trans = glm::scale(trans, glm::vec3( 0.05, 0.05, 0.05));  

    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    // Draw container
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    if(cptRandom == 15) cptRandom = 0;
    else cptRandom++;
}