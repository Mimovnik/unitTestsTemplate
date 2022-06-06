#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <string>

#include "../src/main.h"

using namespace std;

void MyTest(string number);

TEST(CompareStrings, StringEqual) {
    char charArr1[] = "thesamestring", charArr2[] = "thesamestring";
    bool t = equals(charArr1, charArr2);
    ASSERT_TRUE(t);
}

TEST(CompareStrings, StringNotEqual) {
    char charArr1[] = "kebabisto", charArr2[] = "zonker";
    bool f = equals(charArr1, charArr2);
    ASSERT_FALSE(f);
}
TEST(ManualTest, Test1) { MyTest("manual"); }

TEST(Tests, Test0) { MyTest("0"); }
TEST(Tests, Test1) { MyTest("1"); }
TEST(Tests, Test2) { MyTest("2"); }

void checkLineEquality(fstream& expected, fstream& actual) {
    string expectedLine, actualLine;
    int line = 0;
    do {
        line++;
        getline(expected, expectedLine);
        getline(actual, actualLine);
        ASSERT_EQ(expectedLine, actualLine) << "Output line " << line << "\n";
    } while (!expected.eof() && !actual.eof());
    if (!actual.eof()) {
        FAIL() << "Too many lines in actual output, should be: " << line << "\n";
    }
}

char* fullPath(string fileName) {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    int defaultDirectoryLength = strlen(cwd);
    string testFolder = "/tests/";
    int fullPathLength = defaultDirectoryLength + testFolder.length() + fileName.length();
    char* fullPath = new char[fullPathLength];
    std::string directory = cwd + testFolder + fileName;
    strcpy(fullPath, directory.c_str());
    return fullPath;
}

void testPaths(string inputPath, string actualPath, string expectedPath) {
    auto cinBuffer = cin.rdbuf();
    auto testInput = fstream(fullPath(inputPath), fstream::in);
    cin.rdbuf(testInput.rdbuf());

    auto coutBuffer = cout.rdbuf();
    auto testOutput =
        fstream(fullPath(actualPath), fstream::out | fstream::trunc);
    cout.rdbuf(testOutput.rdbuf());

    int program = MYmain();
    ASSERT_EQ(0, program);

    auto expected = fstream(fullPath(expectedPath), fstream::in);
    auto actual = fstream(fullPath(actualPath), fstream::in);
    checkLineEquality(expected, actual);
}

void MyTest(string number) {
    testPaths("input/" + number + ".in", "actual/actual-" + number + ".txt",
              "expected/" + number + ".out");
}