#include <gtest/gtest.h>

#include <huffman/Huffman.h>

TEST(TestHuffman, testRun) {
    ByteBuffer buffer;
    std::vector<ByteBuffer> buffer_vector;
    std::string str = "Anti Tracks is a complete solution \
to protect your privacy and enhance your PC performance. \
With a simple click Anti Tracks securely erase your internet \
tracks, computer activities and programs history information \
stored in many hidden files on your computer.Anti Tracks support \
Internet Explorer, AOL, Netscape/Mozilla and Opera browsers. \
It also include more than 85 free plug-ins to extend erasing \
features to support popular programs such as ACDSee, Acrobat \
Reader, KaZaA, PowerDVD, WinZip, iMesh, Winamp and much more. \
Also you can easily schedule erasing tasks at specific time intervals \
or at Windows stat-up/ shutdown.To ensure maximum privacy protection \
Anti Tracks implements the US Department of Defense DOD 5220.22-M, \
Gutmann and NSA secure erasing methods, making any erased files \
unrecoverable even when using advanced recovery tools.";
    //std::string str = "Anti Tracks is a complete solution";
    buffer = ByteBuffer::str(str);
    buffer_vector.push_back(buffer);
    auto result = Huffman::compress(buffer_vector);
    ByteBuffer ans = Huffman::decompress(result.dictionary, result.data.at(0));
    std::string str2;
    for (size_t i = 0; i < buffer.size(); i++) {
        str2.push_back(ans[i]);
    }
    // 压缩应该缩小体积
    ASSERT_GE(buffer.size(), result.data[0].size());
    // 加密解密后得到的字符串相等
    ASSERT_EQ((UInt) str.compare(str2), (UInt) 0);
    // 多次压缩结果应该一致
    buffer = ByteBuffer::str(str);
    auto result2 = Huffman::compress(buffer_vector);
    ASSERT_EQ(result.dictionary, result2.dictionary);
    ASSERT_EQ(result.data, result2.data);
    // 根据已有字典解压后的结果应该一致
    auto buffer_vector2 = Huffman::compress(result.dictionary, buffer_vector);
    ASSERT_EQ(result.data, buffer_vector2);
}

TEST(TestHuffman, testCompress) {
    std::vector<ByteBuffer> vec;
    Huffman::Result result;
    std::vector<ByteBuffer> decomp;
    //
    vec = {
            ByteBuffer::str("what")
    };
    result = Huffman::compress(vec);
    decomp.clear();
    for (auto &sec: result.data)
        decomp.push_back(Huffman::decompress(result.dictionary, sec));
    ASSERT_EQ(vec, decomp);
    //
    vec = {
            ByteBuffer::str("hello~"),
            ByteBuffer::str("233333"),
            ByteBuffer::str("5566666"),
            ByteBuffer::str("what"),
            ByteBuffer::str("how"),
            ByteBuffer::str("why")
    };
    result = Huffman::compress(vec);
    decomp.clear();
    for (auto &sec: result.data)
        decomp.push_back(Huffman::decompress(result.dictionary, sec));
    ASSERT_EQ(vec, decomp);
}