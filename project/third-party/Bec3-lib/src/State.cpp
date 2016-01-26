#include "Bec3-lib/State.hpp"
#include "Bec3-lib/HTTPError.hpp"
#include "rapidjson/document.h"

#include <restclient-cpp/restclient.h>

using namespace rapidjson;
using namespace std;

RestClient::headermap headers;

State::State(){};

State::State(std::string id){

	stringValue = "";
	boolValue   = false;
	intValue    = 0;

	update(id);
}

void State::update(std::string id){
	RestClient::response object = RestClient::get("http://localhost:9000/feature/" + id, headers, 1);
	if(object.code != -1){
		httpError(object.code);
		Document document; //creation de document pour parseur
		document.Parse(object.body.c_str());
		id = document["state"]["id"].GetInt();
		
		if( document["state"]["value"].IsString() ){
			stringValue = document["state"]["value"].GetString();
			if(stringValue != ""){
				intValue  = 1;
				boolValue = true;
			}
			else{
				intValue  = 0;
				boolValue = false;
			}
		}
		else if( document["state"]["value"].IsInt() ){
			intValue    = document["state"]["value"].GetInt();
			stringValue = to_string(intValue);
			boolValue   = (bool)intValue;
		}
		else if( document["state"]["value"].IsBool() ){
			boolValue   = document["state"]["value"].GetBool();
			intValue    = (int)boolValue;
			stringValue = to_string(boolValue);
		}
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
