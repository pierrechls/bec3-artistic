#include <restclient-cpp/restclient.h>

extern RestClient::headermap headers;

void debug(){
	RestClient::get("", headers, 1);
}
