#ifndef __SC_DICTPRODUCER_H__
#define __SC_DICTPRODUCER_H__

//#include "SplitTool"

#include "Configuration.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>


namespace sc
{

class DictProducer
{
public:
	//构造函数
	DictProducer(const std::string & dir);
	//处理中文的构造函数
//	DictProducer(const std::string & dir, SplitTool * splitTool);

	//创建英文字典
	void build_dict();
	//创建中文字典
//	void build_cn_dict();

	//将词典写入文件
	void store_dict(const char * filepath);

	//查看文件路径，测试用
	void show_files() const;
	//查看词典，测试用
	void show_dict() const;

	//获取文件的绝对路径
	void get_files();

	// 存储某个单词
	void push_dict(const std::string & word);

private:
	Configuration m_conf;
	std::string m_dir;					//语料库文件存放绝对路径
	std::vector<std::string> m_files;	//语料库文件的绝对路径集合
	std::map<std::string, int> m_dict;	//词典数据

//	SplitTool * m_splitTool;			//分词工具
};

}//end of namespace sc

#endif
