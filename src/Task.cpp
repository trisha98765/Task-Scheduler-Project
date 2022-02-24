#include <iostream>
#include <vector>
#include <string>
#include "../header/Task.h"

using namespace std;

Task::Task(){
    name = "Homework";
    description = " ";
    priority = 1; // assuming 1 is the highest priority
    classification = "School";
    duration = 7; // number of days
    dueDate = "03/12/22"; // we might have to validate input by user for this
    completed = false;
    inProgress = 5; // on a scale of 1-10, 5 is half progress made?
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

void Task::setClassification(int label){
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

