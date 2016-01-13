cmake_minimum_required(VERSION 2.8)

project(iSeason)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-reorder -g")

find_package(SDL2)
if(SDL2_FOUND)
	MESSAGE('SDL2 Found, continue...\n')
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(FMOD REQUIRED)
	include_directories(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${FMOD_INCLUDE_DIR} third-party/glimac/include/ third-party/glm/)
	set(ALL_LIBRARIES glimac ${SDL2_LIBRARY} ${SDLMIXER_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${FMOD_LIBRARY})
else()
	find_package(SDL)
	MESSAGE('SDL2 NOT FOUND ; LOADING SDL1.2')
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(FMOD REQUIRED)
	include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${FMOD_INCLUDE_DIR} third-party/glimac/include/ third-party/glm/)
	set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${SDLMIXER_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${FMOD_LIBRARY})
endif()


# Pour gérer un bug a la fac, a supprimer sur machine perso:
#set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

add_subdirectory(third-party)
add_subdirectory(template)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})