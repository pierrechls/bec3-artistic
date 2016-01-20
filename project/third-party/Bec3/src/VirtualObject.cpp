#include "Bec3/VirtualObject.hpp"
#include "Bec3/HTTPError.hpp"
#include <restclient-cpp/restclient.h>
#include "rapidjson/document.h"
#include "rapidjson/error/error.h"
#include "rapidjson/error/en.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf

#include <fstream>

RestClient::headermap headers;

using namespace std;
using namespace rapidjson;

VirtualObject::VirtualObject(string id, string type) : id(id){
	RestClient::response object = RestClient::post("http://localhost:9000/feature", "application/json", "{\"id\":\""+ id + "\",\"type\":\"" + type + "\"}", headers, 1);
	//cout << "Création objet " << id << " " << type << " header : " << headers["Cookie"] << " json : " << "{\"id\":\""+ id + "\",\"type\":\"" + type + "\"}" << endl << endl;
	httpError(object.code);
}

VirtualObject::~VirtualObject(){
	RestClient::response object = RestClient::del("http://localhost:9000/feature/" + id, headers, 1);
	cout << "\033[31m[Destruction de :]\033[39m " << id << endl;
	httpError(object.code);
}

State &VirtualObject::getState(){
	return state;
}

void VirtualObject::updateState(){
	RestClient::response object = RestClient::get("http://localhost:9000/feature/" + id, headers, 1);
	if(object.code != -1){
	httpError(object.code);
	Document document; //creation de document pour parseur
	//	const char* json = (char)object.body;
	cout << object.body.c_str() << " " << object.code << endl;
	ParseResult result = document.Parse(object.body.c_str());
	if (!result) {
		std::cerr << "JSON parse error: %s (%u)", GetParseError_En(result.Code()), result.Offset();

	}
	//state.id = assert(document["hello"].IsString());
	//cout << state.id << endl;

	cout << "lololol" << document["state"]["id"].GetInt() << endl;
	}
}
