#include "BASE64.h"
#include "gtest/gtest.h"
#include <string>
using namespace std;

TEST(tested, test1)
{
    string line = "A pochemu tak skuchno?";
    string result = Encoding(line);
    ASSERT_EQ(result, "QSBwb2NoZW11IHRhayBza3VjaG5vPw==");
}

TEST(tested, test2)
{
    string line = "Ya hochu spat' = (;-;)";
    string result = Encoding(line);
    ASSERT_EQ(result, "WWEgaG9jaHUgc3BhdCcgPSAoOy07KQ==");
}

TEST(tested, test3)
{
    string line = "......Y menya bolshe net idei";
    string result = Encoding(line);
    ASSERT_EQ(result, "Li4uLi4uWSBtZW55YSBib2xzaGUgbmV0IGlkZWk=");
}

TEST(tested, test4)
{
    string line = "QSBwb2NoZW11IHRhayBza3VjaG5vPw==";
    string result = Decoding(line);
    ASSERT_EQ(result, "A pochemu tak skuchno?");
}

TEST(tested, test5)
{
    string line = "WWEgaG9jaHUgc3BhdCcgPSAoOy07KQ";
    string result = Decoding(line);
    ASSERT_EQ(result, "Ya hochu spat' = (;-;)");
}

TEST(tested, test6)
{
    string line = "Li4uLi4uWSBtZW55YSBib2xzaGUgbmV0IGlkZWk=";
    string result = Decoding(line);
    ASSERT_EQ(result, "......Y menya bolshe net idei");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

