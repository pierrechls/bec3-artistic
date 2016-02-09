cmake_minimum_required(VERSION 2.8)

project(BeC3)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2 -Wno-reorder -g")

set(CMAKE_PREFIX_PATH /etc/lib)

find_package(SDL2)
if(SDL2_FOUND)
	MESSAGE('SDL2 Found, continue...\n')
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(FMOD REQUIRED)
	find_package(CURL REQUIRED)
	include_directories(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${FMOD_INCLUDE_DIR} ${CURLCPP_SOURCE_DIR}/include third-party/glimac/include/ third-party/glm/ third-party/Bec3-lib/include/ third-party/assimp/)
	set(ALL_LIBRARIES glimac Bec3-lib ${SDL2_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${FMOD_LIBRARY} ${CURL_LIBRARY} assimp)
else()
	find_package(SDL)
	MESSAGE('SDL2 NOT FOUND ; LOADING SDL1.2')
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(FMOD REQUIRED)
	find_package(CURL REQUIRED)
	include_directories(${SDL_INCLUDE_DIR}  ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${FMOD_INCLUDE_DIR} ${CURLCPP_SOURCE_DIR}/include third-party/glimac/include/ third-party/glm/ third-party/Bec3-lib/include/ third-party/assimp/ )
	set(ALL_LIBRARIES glimac Bec3-lib ${SDL2_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${FMOD_LIBRARY} ${CURL_LIBRARY} assimp)
endif()

add_subdirectory(third-party)
add_subdirectory(template)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
