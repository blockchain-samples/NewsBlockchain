#include "Search.h"
#include <vector>

std::vector<ByteBuffer> Search::search(std::vector<std::string>keyWords) const {
	
	auto temp = BlockChain::getGlobalChain();//����������������
	for (auto& blockRef : temp) 
	{
		auto realBlock = blockRef.get();
		std::vector<ByteBuffer> ret= realBlock.getAllDecomposedDataBlock();//�õ��������ݿ�Ľ�ѹ����
		//ret.
		


	}
	ChainBlock::getHeader();
	Blockchain::GLOBAL_CHAIN;
}