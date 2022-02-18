#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>

#include "Named.h"
#include "Deletable.h"

using namespace std;

class Task : public Named, public Deletable {
    private:
        string name;
        string description;
        int priority;
        string classification;
        int duration;
        string dueDate; // we can change the type to int if thats better
        bool completed;
        int inProgress;
    public:
        Task();
        void setName(string n);
        void setDescription(string d);
        void setPriority(int val);
        void setDuration(int dur);
        void setDueDate(string date);
        void setClassification(int label);
        void setCompletion(bool check); // not sure if we want this one
        void setProgress(int progress); // not sure about this either

        string getName();
        string getDescription();
        int getPriority();
        int getDuration();
        string getDueDate(); // the return val can also be a int ?
        string getClassification();
        bool getCompletion(); // not sure
        int getProgress();    // not sure

        void print();
        void edit(); //specifications not complete
        void deleteTask(); // changed method name because 'delete' is c++ key word
};

#endif
