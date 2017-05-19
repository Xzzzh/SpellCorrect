#include "Configuration.h"
#include "DictProducer.h"

using namespace sc;

int main(void)
{
	DictProducer dic;
	dic.build_dict();	
	dic.store_dict();
	return 0;
}
