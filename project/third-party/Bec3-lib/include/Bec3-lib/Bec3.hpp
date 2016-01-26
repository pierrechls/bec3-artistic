#ifndef BEC3_HPP
#define BEC3_HPP

#include <map>
#include <string>
#include <memory>
#include "Bec3-lib/VirtualObject.hpp"
#include <ctime>

class Bec3 {
	private :
		std::clock_t timer;
		std::map<std::string, std::shared_ptr<VirtualObject>> Objects;
		void connect(std::string username, std::string password);
		void disconnect();
		bool requestTime();

	public :
		Bec3();
		Bec3(std::string path);
		Bec3(std::string username, std::string password);
		void initFromFile(std::string path);
		~Bec3();
		void updateObjects();
		State &getObjectState(std::string id);
		void addObject(std::string id, std::string type);
};

#endif
