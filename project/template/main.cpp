#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <curl/curl.h>

#include "Engine.hpp"

using namespace std;
using namespace glimac;

#include <string>

#include "curl_easy.h"
#include "curl_pair.h"
#include "curl_form.h"
#include "curl_exception.h"

#include "restclient-cpp/restclient.h"

using std::string;

using curl::curl_form;
using curl::curl_easy;
using curl::curl_pair;
using curl::curl_header;
using curl::curl_easy_exception;
using curl::curlcpp_traceback;

int main(int argc, const char **argv) {
	RestClient::headermap headers;
	headers["Content-Type"] = "application/json";
	RestClient::response connect = RestClient::post("http://localhost:9000/login", "text/json", "{\"username\":\"corentin.limoge\",\"password\":\"coucou\",\"service\":\"im.bec3.com\",\"resource\":\"REST\"}", headers);
	cout << connect.code << endl;
	RestClient::response r = RestClient::get("http://localhost:9000/feature/LIGHT", connect.headers);
	cout << r.code << endl;
	cout << r.body << endl;
	/*RestClient::response r = RestClient::post("http://url.com/post", "text/json", "{\"foo\": \"bla\"}");
	RestClient::response r = RestClient::put("http://url.com/put", "text/json", "{\"foo\": \"bla\"}");
	RestClient::response r = RestClient::del("http://url.com/delete");

	// add some headers

	RestClient::headermap headers;
	headers["Accept"] = "application/json";

	RestClient::response r = RestClient::get("http://url.com", headers);
	RestClient::response r = RestClient::post("http://url.com/post", "text/json", "{\"foo\": \"bla\"}", headers);
	RestClient::response r = RestClient::put("http://url.com/put", "text/json", "{\"foo\": \"bla\"}", headers);
	RestClient::response r = RestClient::del("http://url.com/delete", headers);

	RestClient::setAuth("WarMachine68", "WARMACHINEROX");
	curl_pair<CURLformoption,string> name_cont(CURLFORM_COPYCONTENTS,"{\"username\":\"corentin.limoge\",\"password\":\"coucou\",\"service\":\"im.bec3.com\",\"resource\":\"REST\"}");*/
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


