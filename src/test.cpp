#include "gtest/gtest.h"
#include "../header/Task.h"
#include "../header/TaskList.h"
#include "../header/Goal.h"
#include<vector>
using namespace std;

static TaskList testList = TaskList("Test");

TEST(TaskConstructorTest, defaultConstructor){
    Task *test = new Task();
   // EXPECT_EQ(test->getName(), "Homework");
    EXPECT_EQ(test->getDescription(), "For CS 100");
    EXPECT_EQ(test->getPriority(), 1);
    EXPECT_EQ(test->getClassification(), "School");
    EXPECT_EQ(test->getDuration(), 7);
    EXPECT_EQ(test->getDueDate(), "03/12/22");
    EXPECT_EQ(test->getCompletion(), false);
    EXPECT_EQ(test->getProgress(), 5);
}

TEST(TaskConstructorTest, overloadedConstructor){
    Task *test = new Task("Notes","For CS 100",3,3,"02/22/22","School",false,0);
    // EXPECT_EQ(test->getName(), "Notes");
    EXPECT_EQ(test->getDescription(), "For CS 100");
    EXPECT_EQ(test->getPriority(), 3);
    EXPECT_EQ(test->getClassification(), "School");
    EXPECT_EQ(test->getDuration(), 3);
    EXPECT_EQ(test->getDueDate(), "02/22/22");
    EXPECT_EQ(test->getCompletion(), false);
    EXPECT_EQ(test->getProgress(), 0);
}

TEST(TaskMethodTest, addTask){
    Goal *task2 = new Task("Study Guide", "For CS 100", 1, 3,"03/11/22", "Winter 2022", false, 0);
    testList.addTask(task2);
    testList.print(std::cout);
}

int main(int argc, char **argv) {
    Goal *task1 = new Task("Notes", "For CS 100", 2, 10,"03/19/22", "Winter 2022", false, 5);
    testList.addTask(task1);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
