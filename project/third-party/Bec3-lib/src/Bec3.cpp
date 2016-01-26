#include "Bec3-lib/Bec3.hpp"
#include <restclient-cpp/restclient.h>
#include "Bec3-lib/HTTPError.hpp"
#include "rapidjson/document.h"

#include <fstream>
#include <sstream>
#include <iostream>

extern RestClient::headermap headers;

using namespace std;
using namespace rapidjson;

Bec3::Bec3(){}

Bec3::Bec3(string path){
    initFromFile(path);
}

Bec3::Bec3(string username, string password){
    connect(username, password);
    timer = std::clock();
}

void Bec3::initFromFile(string path){

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
    const Value &user_login      = user["login"];
    const Value &user_password   = user["password"];
    connect(user_login.GetString(), user_password.GetString() );

    //ADD ALL OBJECTS
    for (SizeType i = 0; i < objects.Size(); ++i) {
        const Value &id   = objects[i]["id"];
        const Value &type = objects[i]["type"];
        addObject( id.GetString() , type.GetString() );
    }

    timer = std::clock();
}

Bec3::~Bec3(){
	Objects.clear();
	disconnect();
}

void Bec3::connect(string username, string password){
	RestClient::response connect = RestClient::post("http://localhost:9000/login", "text/json", "{\"username\":\"" + username + "\",\"password\":\"" + password + "\",\"service\":\"im.bec3.com\",\"resource\":\"REST\"}");
	httpError(connect.code);

	cout << "Hello " + username + " you are : " << "\033[32m[connected]\033[00m" << endl;
	cout << "ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ" << endl;

	//On récupère le cookie généré et on l'ajoute au headers
	string cookie = connect.headers.find("Set-Cookie")->second;
	cookie = cookie.substr(0, cookie.find(";"));
	headers["Cookie"] = cookie;
}

void Bec3::disconnect(){
	RestClient::response disconnect = RestClient::del("http://localhost:9000/login", headers, 1);
	httpError(disconnect.code);
	headers["Cookie"] = "";
}

void Bec3::updateObjects(){
	if( requestTime() ){
		for(auto it=Objects.begin(); it!=Objects.end(); ++it)
			it->second->updateState();
	}
}

void Bec3::addObject(string id, string type){
	if(type == "gauge" || type == "slider" || type == "light" || type == "msg-receiver"){
		std::shared_ptr<VirtualObject> myObject(new VirtualObject(id, type));
		Objects.insert(std::pair<string,std::shared_ptr<VirtualObject>>(id, myObject));
		cout << "\033[32m[Object " + id + " added]\033[00m" << endl;
	}
	else
		httpError(418);
}

State &Bec3::getObjectState(std::string id){
	return Objects.find(id)->second->getState();
}

bool Bec3::requestTime(){
    if( (clock() - (float)timer)/CLOCKS_PER_SEC > 0.05){
    	timer = clock();
    	return true;
    }
    else return false;
}
