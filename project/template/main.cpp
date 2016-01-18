#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <curl/curl.h>
#include <list>

#include "restclient-cpp/restclient.h"

#include "Engine.hpp"

using namespace std;
using namespace glimac;

#include "Bec3.hpp"
#include <string>

using namespace std;



int main(int argc, const char **argv) {	
	RestClient::headermap lol;
	lol["Cookie"] = "PLAY_SESSION=1348ee1c612518e7097c41ea9e181db834e6123c-UID=corentin.limoge%2540im.bec3.com";
	
	Bec3 mySession = Bec3(string("corentin.limoge"), string("coucou"));

	
	//RestClient::response light = RestClient::get("http://localhost:9000/feature/COUCOU", lol, 1);
	
	/*while(1){
		RestClient::response light = RestClient::get("http://localhost:9000/feature/COUCOU", headers, 1);
		cout << light.code << endl;
		cout << light.body << endl;
	}*/
	/*RestClient::response r = RestClient::post("http://url.com/post", "text/json", "{\"foo\": \"bla\"}");
	RestClient::response r = RestClient::put("http://url.com/put", "text/json", "{\"foo\": \"bla\"}");
	RestClient::response r = RestClient::del("http://url.com/delete");

	// add some headers

	RestClient::headermap headers;
	headers["Accept"] = "application/json";

	RestClient::response r = RestClient::get("http://url.com", headers);
	RestClient::response r = RestClient::post("http://url.com/post", "text/json", "{\"foo\": \"bla\"}", headers);
	RestClient::response r = RestClient::put("http://url.com/put", "text/json", "{\"foo\": \"bla\"}", headers);
	RestClient::response r = RestClient::del("http://url.com/delete", headers);*/

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


