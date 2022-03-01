#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <vector>
#include <string>
#include "../header/Task.h"
#include "..header/Goal.h"

class TaskList: public Goal{
    private:
        std::vector<Goal*> listObj;
        std::string name;
        bool lookInMain; //lets program know that user wants to add an existing task to the list
        bool deleted; //lets main know that list has been deleted
    public:
        ~TaskList(){}
        TaskList():Goal(){
            name = "default";
        }
        TaskList(std::string n):Goal(n){
            name = n;
        }
        std::string getName(){
            return name;
        }
        void setBool(bool input){
            deleted =  input;
        }
        bool getBool(){
            return deleted;
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
        std::vector<Goal*>& getList(); //passed by reference
        void deleteObj();
        Goal* findTask(std::string);
        int findIndex(std::string);
};

#endif
