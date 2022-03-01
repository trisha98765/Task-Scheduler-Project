#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "../header/TaskList.h"
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
        virtual void print(std::ostream &out) = 0;
        virtual void edit() = 0;      // does this take arguments?
        virtual void deleteObj() = 0;
};

#endif
