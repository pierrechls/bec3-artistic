#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <curl/curl.h>
#include <list>

#include "Engine.hpp"

using namespace std;
using namespace glimac;

#include "restclient-cpp/restclient.h"

using std::string;

int main(int argc, const char **argv) {
	RestClient::headermap headers;
	headers["Cookie"] = "PLAY_SESSION=1348ee1c612518e7097c41ea9e181db834e6123c-UID=corentin.limoge%2540im.bec3.com";
	
	RestClient::response connect = RestClient::post("http://localhost:9000/login", "text/json", "{\"username\":\"corentin.limoge\",\"password\":\"coucou\",\"service\":\"im.bec3.com\",\"resource\":\"REST\"}");
	cout << connect.code << endl;
	
	for (auto iter = connect.headers.begin(); iter != connect.headers.end(); iter++)
	{
		cout << "Key: " << iter->first << endl << "Values:" << iter->second<< endl;
	}
	
	/*RestClient::response button = RestClient::post("http://localhost:9000/feature", "text/json", "{\"id\":\"Button\",\"type\":\"button\"}", connect.headers, 1);
	cout << button.code << endl;
	cout << button.body << endl;*/
	while(1){
		RestClient::response light = RestClient::get("http://localhost:9000/feature/COUCOU", headers, 1);
		cout << light.code << endl;
		cout << light.body << endl;
	}
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

    //Artistic.stop();

    return 0;
}*/


