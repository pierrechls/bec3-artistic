#include "Bec3/Bec3.hpp"
#include <restclient-cpp/restclient.h>
#include "Bec3/HTTPError.hpp"

extern RestClient::headermap headers;

using namespace std;

using std::string;

Bec3::Bec3(string username, string password){
	connect(username, password);
	headers["Cookie"] = "PLAY_SESSION=1348ee1c612518e7097c41ea9e181db834e6123c-UID=corentin.limoge%2540im.bec3.com";
}

Bec3::~Bec3(){
	Objects.clear();
	disconnect();
}

void Bec3::connect(string username, string password){
	RestClient::response connect = RestClient::post("http://localhost:9000/login", "text/json", "{\"username\":\"" + username + "\",\"password\":\"" + password + "\",\"service\":\"im.bec3.com\",\"resource\":\"REST\"}");
	httpError(connect.code);
	cout << "\033[32m[connected]\033[00m" << endl;
	//Rajouter la session
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
		cout << "Objets à insérer" << endl;
		std::shared_ptr<VirtualObject> myObject(new VirtualObject(id, type));
		cout << "Pointeur créé" << endl;
		Objects.insert(std::pair<string,std::shared_ptr<VirtualObject>>(id, myObject));
		cout << "Objets inséré" << endl;
	}
	else
		httpError(418);
}

shared_ptr<VirtualObject> &Bec3::object(string id){
	//cout << "Type returned : " << typeid(Objects.find(id)->second).name() << endl;
	//cout << "Type of value : " << typeid(Objects.find(id)->second->value).name() << endl;
	//cout << "Object valu " << Objects.find(id)->second->value << endl;
	
	//std::shared_ptr<State> myPtr(new State(Objects.find(id)->second->getState()));
	//return Objects.find(id)->second->getState();
	return Objects.find(id)->second;
}
