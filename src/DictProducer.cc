#include "DictProducer.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>

namespace sc
{

DictProducer::DictProducer(const std::string & dir)
: m_conf(dir)
, m_dir(m_conf.getConfigMap()["source_read_path_en"])
{
//	std::string tmp;
//	tmp = m_conf.getConfigMap()["dict_write_path_en"];
//	m_files.push_back(tmp);
}

void DictProducer::build_dict()
{
	std::ifstream ifs;
	ifs.open(m_dir.c_str());
	if(!ifs.good())
	{
		std::cout << "ifstream open error!" << std::endl;
	}
	std::string line, word;
	while(getline(ifs, line))
	{
		for(std::string::size_type i = 0; i <= line.size(); ++i)
		{
			if(!std::isalpha(line[i]))
				line[i] = ' ';
			std::tolower(line[i]);
		}
		std::istringstream iss(line);
		while(iss >> word)
		{
			iss >> word;
			++m_dict[word];
		}
	}
	ifs.close();
}

void DictProducer::store_dict()
{
	std::ofstream ofs;
	std::string tmp = m_conf.getConfigMap()["dict_write_path_en"];
	ofs.open(tmp.c_str());
	for(const auto & it : m_dict)
		ofs << it.first << it.second << std::endl;
	ofs.close();
}

}//end of namespace sc
