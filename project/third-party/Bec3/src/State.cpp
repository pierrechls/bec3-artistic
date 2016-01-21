#include "Bec3/State.hpp"
#include "Bec3/HTTPError.hpp"
#include "rapidjson/document.h"

#include <restclient-cpp/restclient.h>

using namespace rapidjson;
using namespace std;

RestClient::headermap headers;

State::State(){};

State::State(std::string id){
	update(id);
}

void State::update(std::string id){
	RestClient::response object = RestClient::get("http://localhost:9000/feature/" + id, headers, 1);
	if(object.code != -1){
		httpError(object.code);
		Document document; //creation de document pour parseur
		document.Parse(object.body.c_str());
		id = document["state"]["id"].GetInt();
		
		if( document["state"]["value"].IsString() )
			stringValue = document["state"]["value"].GetString();
		else if( document["state"]["value"].IsInt() )
			intValue = document["state"]["value"].GetInt();
		else if( document["state"]["value"].IsBool() )
			boolValue = document["state"]["value"].GetBool();
	}
}

std::string State::getId(){
	return id;
}

std::string State::getString(){
	return stringValue;
}

int State::getInt(){
	return intValue;
}

bool State::getBool(){
	return boolValue;
}
