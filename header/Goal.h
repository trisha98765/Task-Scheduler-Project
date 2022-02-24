#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Goal {
    private:
        string name;
    public:
        void setName(string s){
            name = s;
        }
        string getName(){
            return name;
        }
        virtual void print(std::ostream &out) = 0;
        virtual void edit() = 0;      // does this take arguments?
        virtual void deleteObj(int index) = 0;
};

#endif
