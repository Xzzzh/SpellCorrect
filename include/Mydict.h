#ifndef __SC_MYDICT_H__
#define __SC_MYDICT_H__

#include <vector>
#include <map>
#include <set>
#include <string>

namespace sc
{

class MyDict
{
	//静态成员函数用来初始化单例对象
	static MyDict * createInstance();

	//通过中文和英文词典文件路径初始化词典
	void init (const char * dictEnPath, const char * dictCnPath);

	//获取词典
	std::vector<std::pair<std::string, int> > & getDict();
	//获取索引表
	std::map<std::string, std::set<int> > & getIndexTable();

private:
	MyDict();
	~MyDict();

	std::vector<std::pair<std::string, int> > m_dict;//词典
	std::map<std::string, std::set<int> > m_index_table;//索引表
};

}//end of namespace sc

#endif
