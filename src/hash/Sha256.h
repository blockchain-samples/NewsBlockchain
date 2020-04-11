#ifndef SHA256_H
#define SHA256_H

#include "IHashFunc.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sha256 : public IHashFunc
{
public:

    Sha256() {}
    ~Sha256() {}

    /*
    *Ĭ��hash����
    *
    */
    UInt32 run(const ByteBuffer& buffer) override;

    //hash�㷨��ں���
    string toHexCode(const string& message);
    //hash�㷨
    int deal(const vector<uint8_t>& message,
        vector<uint8_t>* _digest);

protected:

    //hash���ܵĲ�ͬ�Ӻ������

    //����Ԥ������
    int datapreprocess(vector<uint8_t>* message) const;

    //�ֽ���ϢΪ512bit�����ݿ�
    int devide64(const vector<uint8_t>& message,
        vector<vector<uint8_t>>* heap64) const;

    //����sha256�㷨��ƣ����ݺ�����ʽ����16*32��512bit��չΪ64*32
    //��չ��17��64��32λ��
    int expand48(const vector<uint8_t>& heap64,
        vector<uint32_t>* result) const;

    //64��ѭ������
    int hashtocode64(const vector<uint32_t>& result,
        vector<uint32_t>* code64) const;

    int finalhashvalue(const vector<uint32_t>& input,
        vector<uint8_t>* output) const;

    //SHA256�㷨��Ҫ��6���߼����㺯��
    inline uint32_t ch(uint32_t x, uint32_t y, uint32_t z) const;
    inline uint32_t maj(uint32_t x, uint32_t y, uint32_t z) const;
    inline uint32_t big_sigma0(uint32_t x) const;
    inline uint32_t big_sigma1(uint32_t x) const;
    inline uint32_t small_sigma0(uint32_t x) const;
    inline uint32_t small_sigma1(uint32_t x) const;

private:

    //��Ҫ��sha256�㷨����
    static vector<uint32_t> ori_mes_digest;
    static vector<uint32_t> constvalue;

    int s16toi(char c);
};

//6���߼����㺯������

inline uint32_t Sha256::ch(uint32_t x, uint32_t y, uint32_t z) const
{
    return (x & y) ^ ((~x) & z);
}

inline uint32_t Sha256::maj(uint32_t x, uint32_t y, uint32_t z) const
{
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint32_t Sha256::big_sigma0(uint32_t x) const
{
    return (x >> 2 | x << 30) ^ (x >> 13 | x << 19) ^ (x >> 22 | x << 10);
}

inline uint32_t Sha256::big_sigma1(uint32_t x) const
{
    return (x >> 6 | x << 26) ^ (x >> 11 | x << 21) ^ (x >> 25 | x << 7);
}

inline uint32_t Sha256::small_sigma0(uint32_t x) const
{
    return (x >> 7 | x << 25) ^ (x >> 18 | x << 14) ^ (x >> 3);
}

inline uint32_t Sha256::small_sigma1(uint32_t x) const
{
    return (x >> 17 | x << 15) ^ (x >> 19 | x << 13) ^ (x >> 10);
}



#endif // SHA256_H