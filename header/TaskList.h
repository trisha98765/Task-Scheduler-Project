#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <vector>
#include <string>
#include "../header/Task.h"
#include "..header/Goal.h"

using namespace std;

class TaskList: public Goal{
    private:
        vector<Goal*> listObj;
        std::string name;
        bool lookInMain; //lets program know that user wants to add an existing task to the list
    public:
        ~TaskList(){}
        TaskList():Goal(){
            name = "default";
        }
        TaskList(string n):Goal(n){
            name = n;
        }
        std::string getName(){
            return name;
        }
        void setLookInMain(bool answer){
            lookInMain = answer;
        }
        bool getLookInMain(){
            return lookInMain;
        }
        void print(); // had this as an argument originally std::ostream &out
        void edit();      // does this take arguments?
        void addTask(Goal*);
        vector<Goal*>& getList(); //passed by reference
        //void deleteObj(int index, TaskList &tempList);
        Goal* findTask(string);
        int findIndex(string);
};

#endif
