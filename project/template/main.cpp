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
	for(int i = 0; i < 1000; ++i){
		mySession.updateObjects();
	}
	
	cout << "TestLight: " << mySession.getObjectState( "TestLight" ).getBool() << endl;
	cout << "MSG: "       << mySession.getObjectState( "MSG" ).getString()     << endl;

    return 0;
}