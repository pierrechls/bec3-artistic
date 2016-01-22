#include "Graphics.hpp"
#include <iostream>
#include <string>

Graphics::Graphics()
{
	groupA = false;
	groupB = false;
	groupC = false;
	groupD = false;
	groupE = false;

  this->angle = 0.0f;

  this->_ShaderModel = Shader ("template/shaders/model_loading.vs.glsl", "template/shaders/model_loading.fs.glsl");
  this->_Model = Model("assets/models/Satellite.obj");

  Camera NewCamera;
  this->_Camera = NewCamera;

}


void Graphics::draw(float* frequencies, float screenWidth, float screenHeight)
{
    setfrequenciesChannel(frequencies);

    //Draw background with music (channel 0, groupe A)
    if(groupA) _Background.draw(frequenciesChannel[ 2 ], 900);

    //Draw circle with bass (channel 3, groupe B)
    if(groupB)
    {
      _Circle.draw(frequenciesChannel[2], 1.0);
      _Circle.draw(frequenciesChannel[2], 0.2);
      _Circle.draw(frequenciesChannel[2], 0.5);
    }

    //Draw triangle with sound (channel 5, groupe D)
    if(groupD)
    {
      _Triangle.draw(frequencies[2]);
    }

    //Draw satellite with NASA sound (channel 6, groupe E)
    if(groupE)
    {
      this->_ShaderModel.Use();

      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)screenWidth/(float)screenHeight, 0.1f, 100.0f);
      glm::mat4 view = _Camera.getViewMatrix();
      glUniformMatrix4fv(glGetUniformLocation(_ShaderModel.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
      glUniformMatrix4fv(glGetUniformLocation(_ShaderModel.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));


      glm::mat4 model;
      model = glm::translate(model, glm::vec3(0.03f, 0.0f, 0.5f)); // Translate it down a bit so it's at the center of the scene
      model = glm::rotate(model, glm::radians( this->angle ), glm::vec3(1.0f, 1.0f, 1.0f)); // It's a bit too big for our scene, so scale it down
      model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f)); // It's a bit too big for our scene, so scale it down
      glUniformMatrix4fv(glGetUniformLocation(_ShaderModel.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
      _Model.Draw(_ShaderModel);

      this->angle++;
    }

}

void Graphics::setfrequenciesChannel(float* newFrequenciesChannel)
{
	for(int i = 0; i < NOMBRE_CHANNEL; i++)
	{
		frequenciesChannel[i] = newFrequenciesChannel[i];
	}
}

void Graphics::Event(string touch)
{
  /////////////////////////
  /*   DISPLAY GROUPE    */
  /////////////////////////

  if( touch == "a" ) groupA = !groupA;
  if( touch == "b" ) groupB = !groupB;
  if( touch == "c" ) groupC = !groupC;
  if( touch == "d" ) groupD = !groupD;
  if( touch == "e" ) groupE = !groupE;
}