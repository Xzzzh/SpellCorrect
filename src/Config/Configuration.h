#ifndef __SC_CONFIGUARTION_H__
#define __SC_CONFIGUARTION_H__

#include <string>
#include <map>

namespace sc
{

class Configuration
{
public:
	Configuration(const std::string & filePath = "../../conf/my.conf");
	std::map<std::string, std::string> & getConfigMap();
	void map_print();
private:
	void analysis();
private:
	std::string m_filePath;
	std::map<std::string, std::string> m_configMap;
};

}//end of namespace sc

#endif
