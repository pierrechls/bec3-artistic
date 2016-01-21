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
	State state;
	Bec3 mySession = Bec3(string("corentin.limoge"), string("coucou"));
	cout << "Coucoutest" << endl;
	mySession.addObject("TestLight", "light");
	cout << "Testlight créée" << endl;
	mySession.addObject("MSG", "msg-receiver");
	cout << "Objets créés" << endl;

	//Test d'affichage des objects sur la platerforme Bec3
	for(int i = 0; i < 100; ++i){
		//cout << i << endl;
		mySession.updateObjects();
	}
	
	//cout << "TestLight: " << mySession.object(string("TestLight"))->value << endl;
	//cout << "MSG: " << mySession.object(string("MSG"))->value << endl;
	
	/*shared_ptr<State> coucou = mySession.getObjectState(string("TestLight"));
	cout << "Coucou " << coucou->value << endl;
	
	cout << "State " << mySession.getObjectState(string("TestLight"))->value << endl;
	while(0){
		mySession.updateObjects();
		cout << "Coucou" << mySession.getObjectState(string("TestLight"))->value << endl;
	}*/

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
