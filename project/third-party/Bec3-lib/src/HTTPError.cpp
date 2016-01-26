#include "Bec3-lib/HTTPError.hpp"
#include <stdexcept>

void httpError(int code){
	try 
	{
		switch(code) {
			case 28:
				throw std::runtime_error("\033[31m[Request timedout]\033[00m\n");
				break;
			case 400:
				throw "\033[31m[Bad request]\033[00m\n";
				break;
			case 401:
				throw std::runtime_error("\033[31m[Not authentificated]\033[00m\n");
				break;   
			case 404:
				throw "\033[31m[This object doesn't exist]\033[00m\n";
				break;
			case 418:
				throw std::runtime_error("\033[31m[This type doesn't exist (IATP)]\033[00m\n");
				break;
			case 500:
				throw std::runtime_error("\033[31m[Internal server error]\033[00m\n");
				break;
		}
	} 
	catch ( const char * Msg ) 
	{ 
		std::cerr << Msg;
	}
}
