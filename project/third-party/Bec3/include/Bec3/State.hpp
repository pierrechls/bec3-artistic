#ifndef STATE_HPP
#define STATE_HPP

#include <string>

class State {
	private :
		std::string id;
		std::string stringValue;
		bool boolValue;
		int intValue;
	
	public:
		State();
		State(std::string id);
		void update(std::string id);
		std::string getId();
		std::string getString();
		int getInt();
		bool getBool();
};

#endif
