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
    std::string string1, string2, string3, string4;
    int int1, int2, int3;
    bool bool1;

    int input3 = 0;
    out << "What would you like to edit?" << std::endl;
    out << "1. Name" << std::endl << "2. Description" << std::endl << "3. Priority" << std::endl << "4. Classification"
    << std::endl << "5. Duration" << std::endl << "6. Due Date" << std::endl << "7. Completion" << std::endl << "8. Progress" << std::endl;
    cin >> input3;
    cin.ignore();
    if(input3 == 1){
        out << "Enter your new value: "; getline(std::cin, string1); out << endl;
        this->Goal::setName(string1);
    }
    else if(input3 == 2){
        out << "Enter your new value: "; getline(std::cin, string2); out << endl;
        this->setDescription(string2);
    }
    else if(input3 == 3){
        out << "Enter your new value: "; cin >> int1; out << endl;
        this->setPriority(int1);
    }
    else if(input3 == 4){
        out << "Enter your new value: "; getline(cin, string3); out << endl;
        this->setClassification(string3);
    }
    else if(input3 == 5){
        out << "Enter your new value: "; cin >> int2; out << endl;
        this->setDuration(int2);
    }
    else if(input3 == 6){
        out << "Enter your new value: "; getline(cin, string4); out << endl;
        this->setDueDate(string4);
    }
    else if(input3 == 7){
        std::string answer;
        out << "Enter yes or no: "; getline(cin, answer); out << endl;
        if(answer == "yes"){
            bool1 = true;
        }
        else{
            bool1 = false;
        }
        this->setCompletion(bool1);
    }
    else if(input3 == 8){
        out << "Enter your new value: "; cin >> int3; out << endl;
        this->setProgress(int3);
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
