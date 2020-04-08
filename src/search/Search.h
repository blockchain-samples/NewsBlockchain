#pragma once
#ifndef NEWS_BLOCKCHAIN_SEARCH_H
#define NEWS_BLOCKCHAIN_SEARCH_H


#include <blockchain/ChainBlock.h>
#include <blockchain/Blockchain.h>
#include <algorithm>


/*
#ifdef UNIT_TEST

#include <gtest/gtest.h>

#endif
*/


#define MAXNUM 256

/*
* �ؼ��������ӿ�
*/

class Search {


    static std::vector<int> moveLenth;
public:

    struct Max {
        int count;
        UInt32 id;
    };

    /*
    * �ؼ����������������عؼ��ֳ��ִ�����������
    * ����ؼ���
    * �������������壨���ֵ䣩
    */

    static std::vector<UInt32> search(std::vector<std::string> &keyWords);


    /*
    *  Sunday�㷨
    *  ��ĳһ������йؼ��ֲ���
    *  ���ض�ĳһ�ؼ����ڸ�������ƥ��Ĵ���
    */

    static int Sunday(ByteBuffer &key, std::vector<ByteBuffer> &block);


    /*
    *�õ�sunday�㷨��ģʽ����ƫ����
    */

    static void getMovelenth(ByteBuffer &key);

};

int location(int a, int b, int c, int d);

bool isChar(Byte &b);

#endif // NEWS_BLOCKCHAIN_SEARCH_H


