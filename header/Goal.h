#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <vector>
#include <string>
#include "../headher/TaskList.h"
#include "../header/Task.h"

class Goal{
    private:
        std::string name;
    public:
        ~Goal(){}
        Goal(){
            name = "";
        }
        Goal(std::string s){
            name = s;
        }
        void setName(std::string s){
            name = s;
        }
        std::string getName(){
            return name;
        }
        virtual void print() = 0; //had this as an argument: std::ostream &out
        virtual void edit() = 0;      // does this take arguments?
        virtual void deleteObj() = 0;
};

#endif
