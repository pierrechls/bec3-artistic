#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <Bec3/Bec3.hpp>

#include "Engine.hpp"
#include "debug.hpp"

using namespace std;
using namespace glimac;

int main(int argc, const char **argv) {

	Bec3 mySession = Bec3( "assets/conf/Bec3.json" );

	//Test d'affichage des objects sur la platerforme Bec3
	for(int i = 0; i < 100; ++i){
		mySession.updateObjects();
	}
	
	cout << "TestLight: " << mySession.getObjectState( "TestLight" ).getBool() << endl;
	cout << "MSG: "       << mySession.getObjectState( "MSG" ).getString()     << endl;

    return 0;
}


/*int main(int argc, char *argv[])
{

    // Initialize SDL and open a window
    GLuint screenWidth = 800, screenHeight = 600;
    SDLWindowManager windowManager(screenWidth, screenHeight, "iSeason");

    // Initialize glew for OpenGL3+ support
    glewExperimental = GL_TRUE;
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorstring(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //Define the viewport dimensions
    glViewport(0, 0, screenWidth, screenHeight);

    // Setup some OpenGL options
    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetstring(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetstring(GLEW_VERSION) << std::endl << std::endl;


    Engine Artistic;


    //Application loop:
    bool done = false;

    while(!done) {
        Artistic.run(&windowManager, screenWidth, screenHeight, &done);
    }

    //Artistic.stop();

    return 0;
}*/
