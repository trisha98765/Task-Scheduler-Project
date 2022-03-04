#include "gtest/gtest.h"
#include "../header/Task.h"
#include "../header/TaskList.h"
#include "../header/Goal.h"
#include<vector>
using namespace std;

static TaskList testList = TaskList("Test");
static std::stringstream output;

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
    EXPECT_EQ(output.str(),"Test\nName: Notes\nDue: 03/19/22\nPriority: 2\nClassification: Winter 2022\nDuration: 10\nDescription: For CS 100\nCompleted? No\nProgress status: 5\n\nName: Study Guide\nDue: 03/11/22\nPriority: 1\nClassification: Winter 2022\nDuration: 3\nDescription: For CS 100\nCompleted? No\nProgress status: 0\n\n");
}

TEST(TaskMethodTest, editTask){ // test using user input 
    Goal *task3 = new Task("Lab 3", "For CS 100", 1, 20,"03/01/22", "Winter 2022", false, 5);
    testList.addTask(task3);
    task3->edit(std::cout);
    
    // TO DO based on user input   
    testList.print(output);
    EXPECT_EQ(output.str(),"");
}


int main(int argc, char **argv) {
    Goal *task1 = new Task("Notes", "For CS 100", 2, 10,"03/19/22", "Winter 2022", false, 5);
    testList.addTask(task1);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
