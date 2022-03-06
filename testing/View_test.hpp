#include <fstream>
#include <sstream>
#include <string>

#ifndef VIEW_TEST_HPP
#define VIEW_TEST_HPP

#include "../header/View.h"

TEST(MainViewTest, EmptyMainTest) {
    // Load expected
    std::string expected;
    {
        std::ifstream expectedFile("testing/MainViewTest_EmptyMainTest.txt");
        std::string line;
        while (getline(expectedFile, line)) {
            expected += line;
            expected += '\n';
        }
        expectedFile.close();
    }
    
    // Load actual
    std::stringstream testOut;
    TaskList unsorted = TaskList("Unsorted");
    vector<TaskList> allLists;
    printMain(testOut, allLists, unsorted);
    
    // Compare
    EXPECT_EQ(testOut.str(), expected);
}


#endif // VIEW_TEST_HPP
