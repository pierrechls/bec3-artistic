#ifndef BEC3_HPP
#define BEC3_HPP

#include <map>
#include <string>
#include <memory>

class VirtualObject;
struct State;

class Bec3 {
	private :
		std::map<std::string, std::shared_ptr<VirtualObject>> Objects;
		void connect(std::string username, std::string password);
		void disconnect();

	public :
		Bec3(std::string username, std::string password);
		~Bec3();
		void updateObjects();
		State &getObjectState(std::string id);
		void addObject(std::string id, std::string type);
};

#endif

