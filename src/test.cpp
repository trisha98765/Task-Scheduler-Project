#include "gtest/gtest.h"
#include "../header/Task.h"
#include "../header/TaskList.h"

TEST(SetterTest, basic){
    Task *test = new Task();
    test->setName("name");
    EXPECT_EQ(test->getName(), "name");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
