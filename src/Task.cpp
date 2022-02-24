#include <iostream>
#include <vector>
#include <string>
#include "../header/Task.h"

using namespace std;

Task::Task(){
    name = "Homework";
    description = "For CS 100";
    priority = 1; // assuming 1 is the highest priority
    classification = "School";
    duration = 7; // number of days
    dueDate = "03/12/22"; // we might have to validate input by user for this
    completed = false;
    inProgress = 5; // on a scale of 1-10, 5 is half progress made?
}
    
Task::Task(string n, string d, int val, int dur, string date, string label, bool check, int progress){
    name = n;
    description = d;
    priority = val;
    duration = dur;
    dueDate = date;
    classification = label;
    completed = check;      
    inProgress = progress;
}

void Task::setName(string n){
    name = n;
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

string Task::getName(){
    return name;
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

string Task::getDueDate(){ // return type could possibly change
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

void Task::print(){
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Due: " << this->getDueDate() << " Priority: " << this->getPriority() << std::endl;
    std::cout << "Classification: " << this-> getClassification() << "Duration: " << this->getDuration() << std::endl;
    std::cout << "Description: " << this-> getDescription() << std::endl;
}
void Task::deleteObj(int index2, vector<Task> &temp) {
    std::string input;
    int index = index2-1; //bc user enters 1 but index is 0
    std::cout << "Would you like to delete this task? Y/N" << std::endl;
    cin >> input;
    if(input == "Y"){
        std::cout << "Task deleted. Undo? Y/N" << std::endl;
        cin >> input;
        if(input == "Y"){
            std::cout << "Task restored" << std::endl;    
        }
        else{
            temp.at(index).erase();
        }
    }
    else{
        std::cout << "Task was not deleted" << std::endl;    
    }
}
