#include "glimac/FreeFlyCamera.hpp"
#include <iostream>

FreeFlyCamera::FreeFlyCamera(){
	m_Position = glm::vec3(0.0f);
	m_fPhi = M_PI;
	m_fTheta = 0.0;
	computeDirectionVectors();
}

void FreeFlyCamera::computeDirectionVectors(){
	float radPhi = m_fPhi;
	float radTheta = m_fTheta;
	m_FrontVector = glm::vec3(cos(radTheta)*sin(radPhi), sin(radTheta), cos(radTheta)*cos(radPhi));
	m_LeftVector = glm::vec3(sin(radPhi+(M_PI/2.0)), 0, cos(radPhi+(M_PI/2.0)));
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}

void FreeFlyCamera::moveLeft(float t){
	m_Position += t * m_LeftVector;
	computeDirectionVectors();
}

void FreeFlyCamera::moveFront(float t){
	m_Position += t * m_FrontVector;
	computeDirectionVectors();
}

void FreeFlyCamera::rotateLeft(float degrees){
	m_fPhi += glm::radians(degrees);
	std::cout << m_fPhi << std::endl;
	computeDirectionVectors();
}

void FreeFlyCamera::rotateUp(float degrees){
	m_fTheta += glm::radians(degrees);
	computeDirectionVectors();
}

glm::mat4 FreeFlyCamera::getViewMatrix() const{
	//Point
	glm::vec3 Point = m_Position + m_FrontVector;
	glm::mat4 MV = glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
	return MV;
}