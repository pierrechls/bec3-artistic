#include "Bec3/VirtualObject.hpp"
#include "Bec3/HTTPError.hpp"

#include <restclient-cpp/restclient.h>
#include <string>       // std::string
#include <iostream>     // std::cout

#include <typeinfo>

extern RestClient::headermap headers;

using namespace std;

VirtualObject::VirtualObject(string id, string type) : id(id){
	RestClient::response object = RestClient::post("http://localhost:9000/feature", "application/json", "{\"id\":\""+ id + "\",\"type\":\"" + type + "\"}", headers, 10);
	httpError(object.code);
	state = State(id);
}

VirtualObject::~VirtualObject(){
	RestClient::response object = RestClient::del("http://localhost:9000/feature/" + id, headers, 1);
	cout << "\033[31m[" + id + " destroyed]\033[39m " << endl;
	httpError(object.code);
}


State &VirtualObject::getState(){
	return state;
}

void VirtualObject::updateState(){
	state.update(id);
}
