#ifndef __SC_SPELLCORRECTSERVER_H__
#define __SC_SPELLCORRECTSERVER_H__

#include "MyConf.h" 
#include "tcpServer.h" 
#include "Threadpool.h" 
#include "TimerThread.h" 

#include <string>

namespace sc
{

class SpellcorrectServer 
{
public:
	SpellcorrectServer(const std::string & cfgFileName);
	void start();
	void onConnection(TcpConnectionPtr conn);
	void onMessage(TcpConnectionPtr conn);
	void onClose(TcpConnectionPtr conn);

private:
	MyConf m_conf;
	TcpServer m_tcpServer;
	Threadpool m_threadpool;
	TimerThread m_timer;
};

}//end of namespace sc

#endif
