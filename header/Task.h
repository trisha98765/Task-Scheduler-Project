#include <iostream>
#include <vector>

#include "Named.h"
#include "Deletable.h"

#ifndef TASK_H
#define TASK_H

using namespace std;

class Task : public Named, public Deletable {
    private:
        string name;
        string description;
        int priority;
        string classification;
        int duration;
        bool completed;
        int inProgress;
    public:
        void setName();
        void setDescription();
        void setPriority();
        void setDuration();
        void setDueDate();
        void setClassification();
        string getName();
        string getDescription();
        int getPriority();
        string getClassification();
        int getDuration();
        void print();
        void edit(); //specifications not complete
        void delete();
};

#endif
