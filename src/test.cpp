#include "gtest/gtest.h"
#include "../header/Task.h"
#include "../header/TaskList.h"
#include "../header/Goal.h"
#include "../header/Menu.h"
#include<vector>
using namespace std;

static TaskList testList = TaskList("Test");
static std::stringstream output;
static vector<TaskList> allLists;
static Goal *staticTask = new Task("Essay", "For HIST 108", 1, 20,"07/01/20", "Summer 2020", false, 2);
TEST(TaskConstructorTest, defaultConstructor){
    Task *test = new Task();
    EXPECT_EQ(test->Goal::getName(), "");
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
    EXPECT_EQ(test->Goal::getName(), "Notes");
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
    testList.print(output);
    EXPECT_EQ(output.str(),"Test\nName: Lecture Videos\nDue: 03/19/22\nPriority: 2\nClassification: Winter 2022\nDuration: 10\nDescription: For CS 100\nCompleted? No\nProgress status: 5\n\nName: Study Guide\nDue: 03/11/22\nPriority: 1\nClassification: Winter 2022\nDuration: 3\nDescription: For CS 100\nCompleted? No\nProgress status: 0\n\n");
}

TEST(TaskMethodTest, editTask){
    Goal *task3 = new Task("Lab 3", "For CS 111", 1, 20,"03/01/22", "Winter 2022", false, 2);
    testList.addTask(task3);
    task3->edit(std::cout,2,"hw for cs 100"); // edit description
    task3->edit(std::cout,6,"12/12/12");      // edit due date
    testList.print(output);
    EXPECT_EQ(output.str(),"Test\nName: Lecture Videos\nDue: 03/19/22\nPriority: 2\nClassification: Winter 2022\nDuration: 10\nDescription: For CS 100\nCompleted? No\nProgress status: 5\n\nName: Study Guide\nDue: 03/11/22\nPriority: 1\nClassification: Winter 2022\nDuration: 3\nDescription: For CS 100\nCompleted? No\nProgress status: 0\n\nTest\nName: Lecture Videos\nDue: 03/19/22\nPriority: 2\nClassification: Winter 2022\nDuration: 10\nDescription: For CS 100\nCompleted? No\nProgress status: 5\n\nName: Study Guide\nDue: 03/11/22\nPriority: 1\nClassification: Winter 2022\nDuration: 3\nDescription: For CS 100\nCompleted? No\nProgress status: 0\n\nName: Lab 3\nDue: 12/12/12\nPriority: 1\nClassification: Winter 2022\nDuration: 20\nDescription: hw for cs 100\nCompleted? No\nProgress status: 2\n\n");
}

TEST(TaskMethodTest, invalidInput){
    std::stringstream testInvalid;
    staticTask->edit(testInvalid,10,"Midterm"); // 10 is not a menu option
    EXPECT_EQ(testInvalid.str(),"\nInvalid choice.");
}

int main(int argc, char **argv) {
    Goal *task1 = new Task("Lecture Videos", "For CS 100", 2, 10,"03/19/22", "Winter 2022", false, 5);
    testList.addTask(task1);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
