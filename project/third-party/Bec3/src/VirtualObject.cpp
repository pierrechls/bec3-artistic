#include "Bec3/VirtualObject.hpp"
#include "Bec3/HTTPError.hpp"
#include <restclient-cpp/restclient.h>

RestClient::headermap headers;

using namespace std;

VirtualObject::VirtualObject(string id, string type) : id(id){
	RestClient::response object = RestClient::post("http://localhost:9000/feature", "text/json", "{\"id\":\""+ id + "\",\"type\":\"" + type + "\"}", headers, 1);
	httpError(object.code);
}

VirtualObject::~VirtualObject(){
	RestClient::response object = RestClient::del("http://localhost:9000/feature/" + id, headers, 1);
	httpError(object.code);
}

State &VirtualObject::getState(){
	return state;
}

void VirtualObject::updateState(){
	RestClient::response object = RestClient::get("http://localhost:9000/feature/" + id, headers, 1);
	httpError(object.code);
	
	state.id = object.body;
	state.value = object.body;
}
