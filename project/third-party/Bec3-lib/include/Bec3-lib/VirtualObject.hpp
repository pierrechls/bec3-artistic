#ifndef VIRTUALOBJECT_HPP
#define VIRTUALOBJECT_HPP

#include "Bec3-lib/State.hpp"

class VirtualObject {
	private :
		std::string id;
		State state;

	public :
		VirtualObject(std::string id, std::string type);
		~VirtualObject();
		State &getState();
		void updateState();
};
#endif
