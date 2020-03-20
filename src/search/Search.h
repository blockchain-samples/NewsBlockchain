#ifndef NEWS_BLOCKCHAIN_SEARCH_H
#define NEWS_BLOCKCHAIN_SEARCH_H

#include <util/Types.h>
#include <blockchain/ChainBlock.h>
#include <blockchain/Blockchain.h>
#include <vector>
#include <string>
#include <util/StringUtil.h>
#include <util/Int.h>


#ifdef UNIT_TEST

#include <gtest/gtest.h>

#endif


#define MAXNUM 256
/*
* �ؼ��������ӿ�
*/
class Search {
	
	static  int moveLenth[MAXNUM];
	
public:
	
	struct Max{
		int count;
		UInt32 id;
	};
	/*
	* �ؼ����������������عؼ��ֳ��ִ�����������
	* ����ؼ���
	* �������������壨���ֵ䣩
	*/
	
	static std::vector<ByteBuffer>  search(std::vector<std::string>keyWords);


	/*
	*  Sunday�㷨
	*  ��ĳһ������йؼ��ֲ���
	*  ���ض�ĳһ�ؼ����ڸ�������ƥ��Ĵ���
	*/

	static int Sunday(ByteBuffer &, std::vector<ByteBuffer> &);


	/*
	*�õ�sunday�㷨��ģʽ����ƫ����
	*/

	static void getMovelenth(const ByteBuffer& key);

}










#endif


