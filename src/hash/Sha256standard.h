#ifndef NEWS_BLOCKCHAIN_Sha256standardSTANDARD_H
#define NEWS_BLOCKCHAIN_Sha256standardSTANDARD_H

#include "IHashFunc.h"
#include <stdint.h>
#include <iostream>


class Sha256standard : public IHashFunc {

	/*
	*Ĭ��hash����
	*
	*/
	UInt32 run(const ByteBuffer& buffer) override;

public:



    //! Ĭ�Ϲ��캯��
    Sha256standard() {}

    //! ��������
    virtual ~Sha256standard() {}

    /** ʹ��Sha256standard�㷨����ȡ������Ϣ��ժҪ������ָ�ƣ�
    [in] message: ������Ϣ
    [out] _digest: ժҪ������ָ�ƣ�
    @return: �Ƿ�ɹ�
    */
    bool encrypt(const std::vector<uint8_t>& message,
        std::vector<uint8_t>* _digest);

    /** ��ȡʮ�����Ʊ�ʾ����ϢժҪ������ָ�ƣ�
    [in] message: ������Ϣ
    ʮ�����Ʊ�ʾ����ϢժҪ������ָ�ƣ�
    */
    std::string getHexMessageDigest(const std::string& message);

protected:
    /////// Sha256standard�㷨�ж����6���߼����� ///////
    inline uint32_t ch(uint32_t x, uint32_t y, uint32_t z) const;
    inline uint32_t maj(uint32_t x, uint32_t y, uint32_t z) const;
    inline uint32_t big_sigma0(uint32_t x) const;
    inline uint32_t big_sigma1(uint32_t x) const;
    inline uint32_t small_sigma0(uint32_t x) const;
    inline uint32_t small_sigma1(uint32_t x) const;

    /** �㷨��������Ϣ��Ԥ�������������������ء��͡����ӳ���ֵ��
    ����������: �ڱ���ĩβ������䣬�Ȳ���һ������Ϊ1��Ȼ�󶼲�0��ֱ�����������512ȡģ��������448����Ҫע����ǣ���Ϣ���������䡣
    ���ӳ���ֵ: ��һ��64λ����������ʾԭʼ��Ϣ�����ǰ����Ϣ���ĳ��ȣ������䲹���Ѿ�����������������Ϣ���档
    _message: ���������Ϣ
    @return: �Ƿ�ɹ�
    */
    bool preprocessing(std::vector<uint8_t>* _message) const;

    /** ����Ϣ�ֽ��������64Byte��С�����ݿ�
    [in] message: ������Ϣ������Ϊ64Byte�ı���
    [out] _chunks: ������ݿ�
    @return: �Ƿ�ɹ�
    */
    bool breakTextInto64ByteChunks(const std::vector<uint8_t>& message,
        std::vector<std::vector<uint8_t>>* _chunks) const;

    /**  ��64Byte��С�����ݿ飬�����64��4Byte��С���֡�
    �����㷨��ǰ16����ֱ�������ݿ�ֽ�õ���������������µ�����ʽ�õ���
            W[t] = small_sigma1(W[t-2]) + W[t-7] + small_sigma0(W[t-15]) + W[t-16]
    [in] chunk: �������ݿ飬��СΪ64Byte
    [out] _words: �����
    @return: �Ƿ�ɹ�
    */
    bool structureWords(const std::vector<uint8_t>& chunk,
        std::vector<uint32_t>* _words) const;

    /** ����64��4Byte��С���֣�����64��ѭ������
    [in] words: 64��4Byte��С����
    [in][out] _message_digest: ��ϢժҪ
    @return: �Ƿ�ɹ�
    */
    bool transform(const std::vector<uint32_t>& words,
        std::vector<uint32_t>* _message_digest) const;

    /**  ������յĹ�ϣֵ������ָ�ƣ�
    [in] input: ����Ϊ32bit�Ĺ�ϣֵ
    [out] _output: ����Ϊ8bit�Ĺ�ϣֵ
    @return: �Ƿ�ɹ�
    */
    bool produceFinalHashValue(const std::vector<uint32_t>& input,
        std::vector<uint8_t>* _output) const;


private:
    static std::vector<uint32_t> initial_message_digest_; // ��Sha256standard�㷨�еĳ�ʼ��ϢժҪ����Щ�����Ƕ���Ȼ����ǰ8��������ƽ������С������ȡǰ32bit������
    static std::vector<uint32_t> add_constant_; // ��Sha256standard�㷨�У��õ�64����������Щ�����Ƕ���Ȼ����ǰ64����������������С������ȡǰ32bit������

    int s16toi(char c);
};


///////////////////////////////// ��������&ģ�溯���Ķ��� /////////////////////////////////////////

inline uint32_t Sha256standard::ch(uint32_t x, uint32_t y, uint32_t z) const
{
    return (x & y) ^ ((~x) & z);
}

inline uint32_t Sha256standard::maj(uint32_t x, uint32_t y, uint32_t z) const
{
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint32_t Sha256standard::big_sigma0(uint32_t x) const
{
    return (x >> 2 | x << 30) ^ (x >> 13 | x << 19) ^ (x >> 22 | x << 10);
}

inline uint32_t Sha256standard::big_sigma1(uint32_t x) const
{
    return (x >> 6 | x << 26) ^ (x >> 11 | x << 21) ^ (x >> 25 | x << 7);
}

inline uint32_t Sha256standard::small_sigma0(uint32_t x) const
{
    return (x >> 7 | x << 25) ^ (x >> 18 | x << 14) ^ (x >> 3);
}

inline uint32_t Sha256standard::small_sigma1(uint32_t x) const
{
    return (x >> 17 | x << 15) ^ (x >> 19 | x << 13) ^ (x >> 10);
}




#endif //NEWS_BLOCKCHAIN_Sha256standardSTANDARD_H