#ifndef __SC_CACHE_H__
#define __SC_CACHE_H__

#include <map>

namespace sc
{

class Cache
{
public:
	Cache(int num = 10);
	Cache(const Cache & cache);
	void addElement(const std::string & key, const std::string & value);
	void readFromFile(const std::string & filename);
	void writeToFile(const std::string & filename);
	void update(const Cache & rhs);
private:
	std::unorderd_map<std::string, std::string> m_hashMap;//互斥变量


};

}//end of namespace sc

#endif
