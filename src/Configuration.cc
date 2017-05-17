#include "Configuartion.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace sc
{

Configuartion::Configuartion(const std::string & filePath)
: m_filePath(filePath)
{
	analysis();
}

std::map<std::string, std::string> & Configuartion::getConfigMap()
{
	return m_configMap;
}

void Configuartion::analysis()
{
	std::ifstream conf;
	conf.open(m_filePath.c_str());
	if(!conf.good())
	{
		std::cout << "ifstream open error!" << std::endl;
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

}//end of namespace sc
