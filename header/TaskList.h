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
        std::string name;
        bool lookInMain; //lets program know that user wants to add an existing task to the list
        bool deleted; //lets main know that list has been deleted
    public:
        TaskList():Goal(){
            name = "default";
        }
        TaskList(std::string n):Goal(n){
            name = n;
        }
        std::string getName(){
            return name;
        }
        void setDeleted(bool input){
            deleted =  input;
        }
        bool isDeleted(){
            return deleted;
        }
        void setLookInMain(bool answer){
            lookInMain = answer;
        }
        bool getLookInMain(){
            return lookInMain;
        }
        void print(std::ostream &out);
        void edit(std::ostream &out, int val, std::string update);
        void addTask(Goal*);
        std::vector<Goal*>& getList(); //passed by reference
        void deleteObj(std::ostream &out);
        Goal* findTask(std::string);
        int findIndex(std::string);
        void addToList(Goal* newTask);
        void setName(std::string n);
        // Tasks may be shared between multiple lists, so freeing on destruction will cause segfaults for shared tasks
        void free();
};

#endif
