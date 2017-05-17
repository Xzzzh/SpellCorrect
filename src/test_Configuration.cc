#include "Configuartion.h"
#include <iostream>
#include <map>

using namespace sc;
using std::map;
using std::string;
using std::cout;
using std::endl;

int main(void)
{
	Configuartion conf;
	map<string, string> confmap = conf.getConfigMap();
	map<string, string>::iterator it;
	for(it = confmap.begin(); it != confmap.end(); ++it)
	{
		cout << it->first << ", " << it->second << endl;
	}
	return 0;
}
