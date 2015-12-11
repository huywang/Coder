#include "gtest\gtest.h"
#include "FileParser.h"

class FileParserTester : public testing::Test {

};

TEST_F(FileParserTester, BasicTest) {
  Coder::FileParser file_parser(L"data.txt");
  EXPECT_EQ(file_parser.Parse(), true);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}