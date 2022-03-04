#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "../header/TaskList.h"
#include "../header/Goal.h"
using namespace std;
class Task: public Goal{
    private:
        std::string name;
        std::string description;
        int priority; // assuming 1 is the highest priority
        std::string classification;
        int duration; // number of days
        std::string dueDate; // we might have to validate input by user for this
        bool completed;
        int inProgress; // on a scale of 1-10, 5 is half progress made?
        bool deleted; // lets main know that task has been deleted 
    public:
    ~Task(){}
        Task():Goal(){
            name = "Homework";
            description = "For CS 100";
            priority = 1;
            classification = "School";
            duration = 7;
            dueDate = "03/12/22";
            completed = false;
            inProgress = 5;
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
        void setDeleted(bool input){
            deleted = input;
        }


        std::string getName();
        std::string getDescription();
        int getPriority();
        int getDuration();
        std::string getDueDate(); 
        std::string getClassification();
        bool getCompletion();
        int getProgress();   
        bool getDeleted(){
            return deleted;
        } 


        virtual void print(std::ostream &out); //had this as an argument originally std::ostream &out
        virtual void edit(std::ostream &out,int choice,std::string update);  // specifications not complete
        void deleteObj(std::ostream &out);
        Goal* userInput(){
            bool bool1 = false;
            std::string string1, string2, string3, string4;
            int int1, int2, int3;
            cin.ignore();
            std::cout << "Create a name: "; getline(std::cin, string1);
            std::cout << std::endl << "Write a short description: "; getline(std::cin, string2);
            std::cout << std::endl << "Set the priority level (1-10): "; std::cin >> int1;
            std::cout << std::endl << "Classify your task: "; cin.ignore(); getline(std::cin, string3);
            std::cout << std::endl << "How many days will this task last? "; std::cin >> int2;
            std::cout << std::endl << "Create a due date in the form XX/YY/ZZ: "; cin.ignore(); getline(cin, string4);
            std::cout << std::endl << "Enter a progress level (1-10): "; cin >> int3; std::cout << std::endl;
            Goal *returnVal = new Task(string1, string2, int1, int2, string4, string3, bool1, int3);
            return returnVal;
        }

};

#endif
