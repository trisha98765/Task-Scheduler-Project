#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
#include "Goal.h"

using namespace std;

class TaskList: public Goal{
    private:
        vector<Goal*> listObj;
    public:
        TaskList():Goal(){}
        void print(); // had this as an argument originally std::ostream &out
        void edit();      // does this take arguments?
        void addTask(Goal*);
        vector<Goal*>& getList(); //passed by reference
        //void deleteObj(int index, TaskList &tempList);
        Goal* findTask(string);
        int findIndex(string);
};

#endif
