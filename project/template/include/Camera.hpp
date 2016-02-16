#pragma once
#include "glimac/glm.hpp"

class Camera{

public:
	Camera();
	void computeDirectionVectors();
	void moveLeft(float t);
	void moveFront(float t);
	void rotateLeft(float degrees);
	void rotateUp(float degrees);
	void changePosition( glm::vec3 position);

	glm::mat4 getViewMatrix() const;

	glm::vec3 getPosition() const;
	glm::vec3 getDirection() const;

private:
	glm::vec3 m_Position;
	float m_fPhi;
	float m_fTheta;

	glm::vec3 m_FrontVector;
	glm::vec3 m_LeftVector;
	glm::vec3 m_UpVector;

};