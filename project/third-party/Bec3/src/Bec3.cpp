#include "Bec3/Bec3.hpp"
#include <restclient-cpp/restclient.h>
#include "Bec3/HTTPError.hpp"

extern RestClient::headermap headers;

using namespace std;

using std::string;

Bec3::Bec3(string username, string password){
	connect(username, password);
}

Bec3::~Bec3(){
	Objects.clear();
	disconnect();
}

void Bec3::connect(string username, string password){
	RestClient::response connect = RestClient::post("http://localhost:9000/login", "text/json", "{\"username\":\"" + username + "\",\"password\":\"" + password + "\",\"service\":\"im.bec3.com\",\"resource\":\"REST\"}");
	httpError(connect.code);
	cout << "Hello " + username + " you are : " << "\033[32m[connected]\033[00m" << endl;
	
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
	for(auto it=Objects.begin(); it!=Objects.end(); ++it)
		it->second->updateState();
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
