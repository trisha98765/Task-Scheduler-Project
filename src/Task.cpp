#include <iostream>
#include <vector>
#include <string>
#include "Task.h"

using namespace std;

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
    cout << "Name: " << this->getName() << endl;
    cout << "Due: " << this->getDueDate() << " Priority: " << this->getPriority() << endl;
    cout << "Classification: " << this-> getClassification() << "Duration: " << this->getDuration() << endl;
    cout << "Description: " << this-> getDescription() << endl;
}

void Task::deleteTask() {
    // TODO
}
