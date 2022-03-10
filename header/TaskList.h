#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "../header/Task.h"
#include "../header/Goal.h"

class TaskList: public Goal{
    private:
        std::vector<Goal*> listObj;
        bool lookInMain; //lets program know that user wants to add an existing task to the list
        bool deleted; //lets main know that list has been deleted
    public:
        TaskList();
        TaskList(std::string n);
        void setDeleted(bool input);
        bool isDeleted();
        void setLookInMain(bool answer);
        bool getLookInMain();
        void print(std::ostream &out);
        void edit(std::ostream &out, int val, std::string update);
        void addTask(Goal*);
        std::vector<Goal*>& getList(); //passed by reference
        void deleteObj(std::ostream &out);
        Goal* findTask(std::string);
        int findIndex(std::string);
        void addToList(Goal* newTask);
        // Tasks may be shared between multiple lists, so freeing on destruction will cause segfaults for shared tasks
        void free();
};

#endif
