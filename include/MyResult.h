#ifndef __SC_MYRESULT_H__
#define __SC_MYRESULT_H__

#include <string>

namespace sc
{

struct MyResult
{
public:
	std::string m_word;//候选词
	int m_iFreq;//词频
	int m_iDist;//与查询词的最小编辑距离
};

}//end of namespace sc

#endif
