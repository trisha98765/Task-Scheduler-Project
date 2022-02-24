#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
#include "Goal.h"

using namespace std;

class TaskList: public Goal {
    private:
        vector<Goal> taskList;
    public:
        void print(std::ostream &out);
        void edit();      // does this take arguments?
        void deleteObj(int index); // name change for virtual method in Goal
        Task findTask();  // does this take arguments?
};

#endif
