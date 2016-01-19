#include "Bec3/Bec3.hpp"

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
	cout << "\033[32m[connected]\033[30m" << endl;
	//Rajouter la session
}

void Bec3::disconnect(){
	RestClient::response disconnect = RestClient::del("http://localhost:9000/login", headers, 1);
	httpError(disconnect.code);
	headers["Cookie"] = "";
}

void Bec3::updateObjects(){
	for(auto it=Objects.begin(); it!=Objects.end(); ++it)
		it->second.updateState();
}

State &Bec3::getObjectState(string id){
	return Objects.find(id)->second.getState();
}
