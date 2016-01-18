cmake_minimum_required(VERSION 2.8)

project(BeC3)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-reorder -g")

set(CMAKE_PREFIX_PATH /etc/lib)

find_package(SDL2)
if(SDL2_FOUND)
	MESSAGE('SDL2 Found, continue...\n')
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(FMOD REQUIRED)
	find_package(CURL REQUIRED)
	include_directories(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${FMOD_INCLUDE_DIR} ${CURLCPP_SOURCE_DIR}/include third-party/glimac/include/ third-party/glm/ third-party/restclient/include/ third-party/Bec3/include/)
	set(ALL_LIBRARIES glimac restclient Bec3 ${SDL2_LIBRARY} ${SDLMIXER_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${FMOD_LIBRARY} ${CURL_LIBRARY})
else()
	find_package(SDL)
	MESSAGE('SDL2 NOT FOUND ; LOADING SDL1.2')
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(FMOD REQUIRED)
	find_package(CURL REQUIRED)
	include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${FMOD_INCLUDE_DIR} ${CURLCPP_SOURCE_DIR}/include third-party/glimac/include/ third-party/glm/ third-party/restclient/include/ third-party/Bec3/include/)
	set(ALL_LIBRARIES glimac restclient Bec3 ${SDL_LIBRARY} ${SDLMIXER_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${FMOD_LIBRARY} ${CURL_LIBRARY})
endif()

# Pour gérer un bug a la fac, a supprimer sur machine perso:
#set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

add_subdirectory(third-party)
add_subdirectory(template)
add_subdirectory(third-party/rapidjson)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
