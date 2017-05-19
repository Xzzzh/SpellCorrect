#include "Configuration.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::endl;
using std::cout;

namespace sc
{

Configuration::Configuration(const std::string & filePath)
: m_filePath(filePath)
{
	analysis();
}

std::map<std::string, std::string> & Configuration::getConfigMap()
{
	return m_configMap;
}

void Configuration::analysis()
{
	std::ifstream conf;
	conf.open(m_filePath.c_str());
	std::cout << m_filePath.c_str() << std::endl;
	if(!conf.good())
	{
		std::cout << "ifstream of Configuration open error!" << std::endl;
	}
	std::string line, key, value;
	while(getline(conf, line))
	{
		std::istringstream iss(line);
		iss >> key >> value;
		m_configMap[key] = value;	
	}
	conf.close();
}
void Configuration::map_print()
{
	auto iter = m_configMap.begin();
	for(; iter != m_configMap.end(); ++iter)
		cout << iter->first << " " << iter->second << endl;
}

}//end of namespace sc
