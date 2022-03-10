#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "../header/Task.h"
#include "../header/TaskList.h"
#include "../header/Goal.h"

using namespace std;

Task::Task():Goal(){
    name = "Homework";
    description = "For CS 100";
    priority = 1;
    classification = "School";
    duration = 7;
    dueDate = "03/12/22";
    completed = false;
    inProgress = 5;
}
Task::Task(std::string n, std::string d, int val, int dur, std::string date, std::string label, bool check, int progress):Goal(n){
    name = n;
    description = d;
    priority = val;
    duration = dur;
    dueDate = date;
    classification = label;
    completed = check;
    inProgress = progress;
}


void Task::setDescription(string d){
    description = d;
}

void Task::setPriority(int val){
    priority = val;
}

void Task::setDuration(int dur){
    duration = dur;
}

void Task::setDueDate(string date){
    dueDate = date;
}

void Task::setClassification(string label){
    classification = label;
}

void Task::setCompletion(bool check){
    completed = check;
}

void Task::setProgress(int progress){
    inProgress = progress;
}

void Task::setDeleted(bool input){
    deleted = input;
}


string Task::getDescription(){
    return description;
}

int Task::getPriority(){
    return priority;
}

int Task::getDuration(){
    return duration;
}

string Task::getDueDate(){
    return dueDate;
}

string Task::getClassification(){
    return classification;
}

bool Task::getCompletion(){
    return completed;
}

int Task::getProgress(){
    return inProgress;
}

bool Task::getDeleted(){
    return deleted;
};

Goal* taskFromInput() {
    bool completed = false;
    std::string name, description, label, date;
    int priority, duration, progress;
    cin.ignore();
    std::cout << "Create a name: "; getline(std::cin, name);
    std::cout << std::endl << "Write a short description: "; getline(std::cin, description);
    std::cout << std::endl << "Set the priority level (1-10): "; std::cin >> priority;
    std::cout << std::endl << "Classify your task: "; cin.ignore(); getline(std::cin, label);
    std::cout << std::endl << "How many days will this task last? "; std::cin >> duration;
    std::cout << std::endl << "Create a due date in the form MM/DD/YY: "; cin.ignore(); getline(cin, date);
    std::cout << std::endl << "Enter a progress level (1-10): "; cin >> progress; std::cout << std::endl;
    Goal *returnVal = new Task(name, description, priority, duration, date, label, completed, progress);
    return returnVal;
}

void Task::print(std::ostream &out){
    out << "Name: " << this->Goal::getName() << std::endl;
    out << "Due: " << this->getDueDate() << std::endl << "Priority: " << this->getPriority() << std::endl;
    out << "Classification: " << this->getClassification() << std::endl << "Duration: " << this->getDuration() << std::endl;
    out << "Description: " << this->getDescription() << std::endl;
    out << "Completed? "; 
    bool complete = this->getCompletion();
    if(complete){
        out << "Yes" << std::endl;
    }
    else{
        out << "No" << std::endl;
    }
    out << "Progress status: " << this->getProgress() << std::endl << std::endl;
}

// format is now: ostream object, menu choice, updated value
void Task::edit(std::ostream &out,int editChoice, string updateTask){
    bool taskCompletion = false;
    if(editChoice == 0){
        out << "What would you like to edit?" << endl;
        out << "1. Name" << endl << "2. Description" << endl << "3. Priority" << endl << "4. Classification" << endl << "5. Duration" << endl << "6. Due Date" << endl << "7. Completion" << endl << "8. Progress" << endl;
        cin >> editChoice;
        cin.ignore();
    }
       
    out << endl;
 
    switch(editChoice) {

        case 1: {
            if(updateTask == ""){ 
                out << "Enter the new name for the task: ";
                getline(cin, updateTask);
            }
            this->Goal::setName(updateTask);
            out << endl;
            break;
        };

        case 2: {
            if(updateTask == ""){
                out << "Enter the new description of the task: ";
                getline(cin, updateTask); 
            }
            this->setDescription(updateTask);
            break;
        };

        case 3: {
            if(updateTask == ""){
                out << "Enter the new priority value: ";
                cin >> updateTask;
            }
            this->setPriority(stoi(updateTask));
            break;
        };

        case 4: {
            if(updateTask == ""){
                out << "Enter the new classification of the task: ";
                getline(cin, updateTask);
            }
            this->setClassification(updateTask);
            break;
        };

        case 5: {
            if(updateTask == ""){
                out << "Enter the new duration of the task: ";
                cin >> updateTask;
            }
            this->setDuration(stoi(updateTask));
            break;
        };

        case 6: {
            if(updateTask == ""){
                out << "Enter the new due date of the task: ";
                getline(cin, updateTask);
            }
            this->setDueDate(updateTask);
            break;
        };

        case 7: {
            if(updateTask == ""){
                out << "(Enter 1 for yes or 0 for no)" << endl;
                out << "Task completed: ";
                getline(cin, updateTask);
            }
                
            if (updateTask == "1")
                taskCompletion = true;
            this->setCompletion(taskCompletion);
            break;
        };

        case 8: {
            if(updateTask == ""){
                out << "Enter the progress value: ";
                cin >> updateTask;
            }
            this->setProgress(stoi(updateTask));
            break;
        }

        default: { 
            out << "Invalid choice.";
        }
    }
}

void Task::deleteObj(std::ostream &out){
    std::string input;
    
    out << "Would you like to delete this task? Y/N: ";
    cin.ignore();
    cin >> input;
    out << std::endl;

    if(input == "Y" || input == "y"){
        out << "Task deleted. Undo? Y/N: ";
        cin >> input;
        out << std::endl;
        if(input == "Y" || input == "y"){
            out << "Task restored." << std::endl;    
        }
        else{
            this->setDeleted(true);
        }
    }
    else{
        out << "Task was not deleted." << std::endl;    
    }
}

