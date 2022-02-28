#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <vector>
#include <string>
#include "../headher/TaskList.h"
#include "../header/Task.h"

using namespace std;

class Goal{
    private:
        string name;
    public:
        ~Goal(){}
        Goal(){
            name = "";
        }
        Goal(string s){
            name = s;
        }
        void setName(string s){
            name = s;
        }
        string getName(){
            return name;
        }
        virtual void print() = 0; //had this as an argument: std::ostream &out
        virtual void edit() = 0;      // does this take arguments?
};

#endif
