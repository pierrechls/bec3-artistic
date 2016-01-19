#ifndef BEC3_HPP
#define BEC3_HPP

#include <map>
#include <string>

class VirtualObject;
struct State;

class Bec3 {
	private :
		std::map<std::string, VirtualObject> Objects;
		void connect(std::string username, std::string password);
		void disconnect();

	public :
		Bec3(std::string username, std::string password);
		~Bec3();
		void updateObjects();
		State &getObjectState(std::string id);
};

#endif

