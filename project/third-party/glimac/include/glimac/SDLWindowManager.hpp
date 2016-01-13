#pragma once

#include <cstdint>
#include <SDL2/SDL.h>
#include "glm.hpp"

namespace glimac {

class SDLWindowManager {
	SDL_Window* m_pWindow;
	SDL_GLContext m_Context;
    glm::vec2 screenDim;
public:
    SDLWindowManager(uint32_t width, uint32_t height, const char* title);
    ~SDLWindowManager();
    SDLWindowManager();
    bool pollEvent(SDL_Event& e);

    bool isKeyPressed(SDL_Keycode key) const;

    // button can SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT and SDL_BUTTON_MIDDLE
    bool isMouseButtonPressed(uint32_t button) const;

    glm::ivec2 getMousePosition() const;
    glm::vec2  getScreenDimensions() const;
    glm::mat4  getProjectionMatrix() const;

    void swapBuffers();

    // Return the time in seconds
    float getTime() const;
};

}
