#ifndef __SC_CONFIGUARTION_H__
#define __SC_CONFIGUARTION_H__

#include <string>
#include <map>

namespace sc
{

class Configuartion
{
public:
	Configuartion(const std::string & filePath);
	std::map<std::string, std::string> & getConfigMap();
private:
	std::string m_filePath;
	std::map<std::string, std::string> m_configMap;
};

}//end of namespace sc

#endif
