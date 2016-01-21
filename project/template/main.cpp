#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include "Engine.hpp"
#include "debug.hpp"
#include "rapidjson/document.h"

using namespace std;
using namespace glimac;
using namespace rapidjson;

#include <Bec3/Bec3.hpp>

int main(int argc, const char **argv) {	
	
    string path = "assets/conf/Bec3.json";
    ifstream conf(path);

    if (!conf.is_open())
    {
        cout << "\033[31m[ERROR]\033[00m Could'nt load configuration file." << endl;
        exit(EXIT_FAILURE);
    }

    stringstream buffer;
    buffer << conf.rdbuf();

    Document document;
    document.Parse(buffer.str().c_str());

    const Value &user    = document["user"];
    const Value &objects = document["objects"];

    //LOG TO BEC3 WITH USER CONFIGURATION
    const Value &user_name  = user["name"];
    const Value &user_login = user["login"];
    const Value &user_mdp   = user["mdp"];
    cout << "Hello " << user_name.GetString() << ", you are : ";
    Bec3 mySession = Bec3(string( user_login.GetString() ), string( user_mdp.GetString() ));

    //ADD ALL OBJECTS
    for (SizeType i = 0; i < objects.Size(); ++i) {
        const Value &id   = objects[i]["id"];
        const Value &type = objects[i]["type"];
        mySession.addObject( id.GetString() , type.GetString() );
        cout << "The " << type.GetString() << " '" << id.GetString() << "' was added." << endl;
    }
	
	//Test d'affichage des objects sur la platerforme Bec3
	/*for(int i = 0; i < 1000000; ++i){
		cout << i << endl;
	}*/

    // Initialize SDL and open a window
    GLuint screenWidth = 800, screenHeight = 600;
    SDLWindowManager windowManager(screenWidth, screenHeight, "Bec3 Artistic");

    // Initialize glew for OpenGL3+ support
    glewExperimental = GL_TRUE;
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //Define the viewport dimensions
    glViewport(0, 0, screenWidth, screenHeight);

    // Setup some OpenGL options
    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl << std::endl;


    Engine Artistic;


    //Application loop:
    bool done = false;

    while(!done) {
        Artistic.run(&windowManager, screenWidth, screenHeight, &done);
    }

    Artistic.stop();

    return 0;
}


/*int main(int argc, char *argv[])
{
    
    // Initialize SDL and open a window
    GLuint screenWidth = 800, screenHeight = 600;
    SDLWindowManager windowManager(screenWidth, screenHeight, "Bec3 Artistic");

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

    Artistic.stop();

    return 0;
}*/


