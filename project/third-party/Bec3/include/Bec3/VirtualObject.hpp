#ifndef VIRTUALOBJECT_HPP
#define VIRTUALOBJECT_HPP

#include <string>
#include <restclient-cpp/restclient.h>
#include "Bec3/HTTPError.hpp"

struct State {
	std::string id;
};

struct StateInt:public State{
	int value;
};

struct StateBool:public State{
	bool value;
};

struct StateString:public State{
	std::string value;
};

class VirtualObject {
	private :
		std::string id;
		StateString state;

	public :
		VirtualObject(std::string id, std::string type);
		~VirtualObject();
		State &getState();
		void updateState();
};
#endif
