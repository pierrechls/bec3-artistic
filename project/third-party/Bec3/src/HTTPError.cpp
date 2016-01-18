#include "HTTPError.hpp"

void httpError(int code){
	try 
	{
		switch(code) {
			case 400:
				throw "Bad request\n";
				break;
			case 401:
				throw "Not authentificated\n"; 
				break;   
			case 404:
				throw "This object doesn't exist\n";
				break;  
		}
	} 
	catch ( const char * Msg ) 
	{ 
		std::cerr << Msg; 
	}
}
