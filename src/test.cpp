#include "gtest/gtest.h"
#include "../header/Task.h"
#include "../header/TaskList.h"

TEST(TaskConstructorTest, defaultConstructor){
    Task *test = new Task();
    EXPECT_EQ(test->getName(), "Homework");
    EXPECT_EQ(test->getDescription(), "For CS 100");
    EXPECT_EQ(test->getPriority(), 1);
    EXPECT_EQ(test->getClassification(), "School");
    EXPECT_EQ(test->getDuration(), 7);
    EXPECT_EQ(test->getDueDate(), "03/12/22");
    EXPECT_EQ(test->getCompletion(), false);
    EXPECT_EQ(test->getProgress(), 5);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
