#include <gtest/gtest.h>

#include <hash/CrcHash.h>

TEST(TestCrcHash, testRun) {
    ByteBuffer buffer({ 'I', 'L', 'O', 'V', 'J', 'L', 'U' });
    std::string str = "ILOVJLU";

    // ����run�Ľ��Ӧ��ͬ
    ASSERT_EQ((UInt)Hash::run(buffer), (UInt)Hash::run(str));

    // ��μ���Ľ��Ӧ����ͬ
    ASSERT_EQ((UInt)Hash::run(buffer), (UInt)Hash::run(buffer));

    // ��ϣֵӦ�ú��������
    ASSERT_NE((UInt)Hash::run("ILOVJLU!"), (UInt)Hash::run(str));

    // �򵥱仯��Ľ��Ӧ�ò�ͬ
    ASSERT_NE((UInt)Hash::run("ILovJLU"), (UInt)Hash::run(str));
    ASSERT_NE((UInt)Hash::run("ILOVjlu"), (UInt)Hash::run(str));
    ASSERT_NE((UInt)Hash::run("I LOVJLU"), (UInt)Hash::run(str));
}