#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>
#include "TaskList.h"
#include "Goal.h"

class Task: public Goal{
    private:
        std::string name;
        std::string description;
        int priority;
        std::string classification;
        int duration;
        std::string dueDate;
        bool completed;
        int inProgress;
    public:
    ~Task(){}
        Task():Goal(){
            name = "Homework";
            description = "For CS 100";
            priority = 1; // assuming 1 is the highest priority
            classification = "School";
            duration = 7; // number of days
            dueDate = "03/12/22"; // we might have to validate input by user for this
            completed = false;
            inProgress = 5; // on a scale of 1-10, 5 is half progress made?
        }
        Task(std::string n, std::string d, int val, int dur, std::string date, std::string label, bool check, int progress):Goal(n){
            name = n;
            description = d;
            priority = val;
            duration = dur;
            dueDate = date;
            classification = label;
            completed = check;      
            inProgress = progress;
        }
        void setName(std::string n);
        void setDescription(std::string d);
        void setPriority(int val);
        void setDuration(int dur);
        void setDueDate(std::string date);
        void setClassification(std::string label);
        void setCompletion(bool check);
        void setProgress(int progress);


        std::string getName();
        std::string getDescription();
        int getPriority();
        int getDuration();
        std::string getDueDate(); 
        std::string getClassification();
        bool getCompletion();
        int getProgress();   


        virtual void print(); //had this as an argument originally std::ostream &out
        virtual void edit();  // specifications not complete
        //void deleteObj(int index2, TaskList &temp);

};

#endif
