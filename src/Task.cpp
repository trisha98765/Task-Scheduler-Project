#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "../header/Task.h"
#include "../header/TaskList.h"
#include "../header/Goal.h"

using namespace std;

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

void Task::print(std::ostream &out){ // had this as an argument originally std::ostream &out
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

void Task::edit(std::ostream &out){
    string updateTask = "";
    int editChoice = 0;
    bool taskCompletion = false, choiceValidity = false;

    out << "What would you like to edit?" << endl;
    out << "1. Name" << endl << "2. Description" << endl << "3. Priority" << endl << "4. Classification" << endl << "5. Duration" << endl << "6. Due Date" << endl << "7. Completion" << endl << "8. Progress" << endl << "9. Done editing" << endl;
    
    while(choiceValidity == false) {
       
        cin >> editChoice;
        cin.ignore();
        out << endl;
 
        switch(editChoice) {

            case 1: {
                out << "Enter the new name for the task: ";
                getline(cin, updateTask);
                this->Goal::setName(updateTask);
                out << endl;
                choiceValidity = true;
                break;
            };

            case 2: {
                out << "Enter the new description of the task: ";
                getline(cin, updateTask); 
                this->setDescription(updateTask);
                choiceValidity = true;
                break;
            };

            case 3: {
                out << "Enter the new priority value: ";
                int prioVal = 0;
                cin >> prioVal;
                this->setPriority(prioVal);
                choiceValidity = true;
                break;
            };

            case 4: {
                out << "Enter the new classification of the task: ";
                getline(cin, updateTask);
                this->setClassification(updateTask);
                choiceValidity = true;
                break;
            };

            case 5: {
                out << "Enter the new duration of the task: ";
                int taskDuration;
                cin >> taskDuration;
                this->setDuration(taskDuration);
                choiceValidity = true;
                break;
            };

            case 6: {
                out << "Enter the new due date of the task: ";
                getline(cin, updateTask);
                this->setDueDate(updateTask);
                choiceValidity = true;
                break;
            };

            case 7: {
                out << "(Enter yes or no)" << endl;
                out << "Task completed: ";
                getline(cin, updateTask);
                if (updateTask == "yes")
                     taskCompletion = true;
                this->setCompletion(taskCompletion);
                choiceValidity = true;
                break;
            };

            case 8: {
                out << "Enter the progress value: ";
                int progVal = 0;
                cin >> progVal;
                this->setProgress(progVal);
                choiceValidity = true;
                break;
            }

            case 9: {
                out << "Editing complete" << endl;
                choiceValidity = true;
                break;
            } 

            default: {
                out << "Invalid choice. Try again: ";
            }
        }
    }
}
void Task::deleteObj(std::ostream &out){
    std::string input;
    
    out << "Would you like to delete this task? Y/N: ";
    cin.ignore();
    cin >> input;
    out << std::endl;

    if(input == "Y"){
        out << "Task deleted. Undo? Y/N: ";
        cin >> input;
        out << std::endl;
        if(input == "Y"){
            out << "Task restored" << std::endl;    
        }
        else{
            this->setDeleted(true);
        }
    }
    else{
        out << "Task was not deleted" << std::endl;    
    }
}
