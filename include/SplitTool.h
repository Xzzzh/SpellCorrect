#ifndef __SC_SPLITTOOL_H__
#define __SC_SPLITTOOL_H__

#include "Configuartion.h"
#include <string>
#include <vector>

namespace sc
{

class SplitTool
{
public:
	SplitTool();
	virtual ~SplitTool();
	//分词函数，纯虚，提供接口
	virtual std::vector<std::string> cut(const std::string & sentence)=0;
};

class SplitToolNLPIR
{
public:
	SplitToolNLPIR();
	virtual ~SplitToolNLPIR();
	virtual std::vector<std::string> cut(const std::string & sentence)=0;

private:
	Configuration & m_conf;
};

}//end of namespace sc



#endif
