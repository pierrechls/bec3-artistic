#pragma once

#include <cstdint>
#include <SDL/SDL.h>
#include "glm.hpp"

namespace glimac {

class TrackballCamera {

private:
    float m_fDistance; //distance par rapport au centre de la scène
    float m_fAngleX; // l'angle effectuée par la caméra autour de l'axe x de la scène (rotation vers le haut ou vers le bas)
    float m_fAngleY; //l'angle effectuée par la caméra autour de l'axe y de la scène (rotation vers la gauche ou vers la droite)

public:

	TrackballCamera(); //Constructeur
   ~TrackballCamera(); //Destructeur

    void moveFront(float delta); //permettant d'avancer / reculer la caméra. Lorsque delta est positif la caméra doit avancer, sinon elle doit reculer.
    void rotateLeft(float degrees); //permettant de tourner latéralement autour du centre de vision.
    void rotateUp(float degrees); //permettant de tourner verticalement autour du centre de vision.

    glm::mat4 getViewMatrix() const;
};

}
