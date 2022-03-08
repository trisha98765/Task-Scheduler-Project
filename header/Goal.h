#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

class Goal{
    private:
        std::string name;
    public:
        Goal();
        Goal(std::string s);
        void setName(std::string s);
        std::string getName();
        virtual void print(std::ostream &out) = 0;
        virtual void edit(std::ostream &out,int val,std::string update) = 0;      // does this take arguments?
        virtual void deleteObj(std::ostream &out) = 0;
};

#endif
