#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>
#include "Goal.h"

using namespace std;

class Task: public Goal {
    private:
        string name;
        string description;
        int priority;
        string classification;
        int duration;
        string dueDate;
        bool completed;
        int inProgress;
    public:
        Task();
        Task(string n, string d, int val, int dur, string date, string label, bool check, int progress);
        void setName(string n);
        void setDescription(string d);
        void setPriority(int val);
        void setDuration(int dur);
        void setDueDate(string date);
        void setClassification(string label);
        void setCompletion(bool check);
        void setProgress(int progress);


        string getName();
        string getDescription();
        int getPriority();
        int getDuration();
        string getDueDate(); 
        string getClassification();
        bool getCompletion();
        int getProgress();   


        void print(std::ostream &out);
        void edit();  // specifications not complete
        void deleteObj(int index, vector<Task> &temp); // changed method name because 'delete' is c++ key word
};

#endif
