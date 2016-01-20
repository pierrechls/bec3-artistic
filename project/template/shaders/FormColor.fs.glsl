#version 330 core

out vec4 color;

void main()
{
    //Form with color
    color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    
    //Form with texture
    //color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);
} 