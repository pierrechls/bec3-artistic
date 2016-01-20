#include "Camera.hpp"
#include <iostream>

Camera::Camera(){
	m_Position = glm::vec3(0.0f);;
	m_fPhi = glm::radians(M_PI);
	m_fTheta = glm::radians(0.0);
	computeDirectionVectors();
}

void Camera::computeDirectionVectors(){
	float radPhi = m_fPhi;
	float radTheta = m_fTheta;
	m_FrontVector = glm::vec3(cos(radTheta)*sin(radPhi), sin(radTheta), cos(radTheta)*cos(radPhi));
	m_LeftVector = glm::vec3(sin(radPhi+(M_PI/2.0)), 0, cos(radPhi+(M_PI/2.0)));
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}

void Camera::moveLeft(float t){
	m_Position += t * m_LeftVector;
	computeDirectionVectors();
}

void Camera::moveFront(float t){
	m_Position += t * m_FrontVector;
	computeDirectionVectors();
}

void Camera::rotateLeft(float degrees){
	m_fPhi += glm::radians(degrees);
	computeDirectionVectors();
}

void Camera::rotateUp(float degrees){
	m_fTheta += glm::radians(degrees);
	computeDirectionVectors();
}

void Camera::changePosition( glm::vec3 position){
	m_Position = position;
	computeDirectionVectors();
}

glm::mat4 Camera::getViewMatrix() const{
	//Point
	glm::vec3 Point = m_Position + m_FrontVector;
	glm::mat4 MV = glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
	return MV;
}

glm::vec3 Camera::getPosition() const {
	return m_Position;
}
glm::vec3 Camera::getDirection() const{
	return (m_Position + m_FrontVector);
}
