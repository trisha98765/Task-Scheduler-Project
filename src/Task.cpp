#include <iostream>
#include <vector>
#include <string>
#include "Task.h" //change back to ../header/
#include "TaskList.h"
#include "Goal.h"

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

void Task::print(){ // had this as an argument originally std::ostream &out
    std::cout << "Name: " << this->Goal::getName() << std::endl;
    std::cout << "Due: " << this->getDueDate() << std::endl << "Priority: " << this->getPriority() << std::endl;
    std::cout << "Classification: " << this->getClassification() << std::endl << "Duration: " << this->getDuration() << std::endl;
    std::cout << "Description: " << this->getDescription() << std::endl;
    std::cout << "Completed? "; 
    bool complete = this->getCompletion();
    if(complete){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
    std::cout << "Progress status: " << this->getProgress() << std::endl << std::endl;
}

void Task::edit(){
    std::string string1, string2, string3, string4;
    int int1, int2, int3;
    bool bool1;

    int input3 = 0;
    std::cout << "What would you like to edit?" << std::endl;
    std::cout << "1. Name" << std::endl << "2. Description" << std::endl << "3. Priority" << std::endl << "4. Classification"
    << std::endl << "5. Duration" << std::endl << "6. Due Date" << std::endl << "7. Completion" << std::endl << "8. Progress" 
    << std::cout << std::endl;
    cin >> input3;
    if(input3 == 1){
        std::cout << "Enter your new value: "; cin >> string1; std::cout << endl;
        this->Goal::setName(string1);
    }
    else if(input3 == 2){
        std::cout << "Enter your new value: "; cin >> string2; std::cout << endl;
        this->setDescription(string2);
    }
    else if(input3 == 3){
        std::cout << "Enter your new value: "; cin >> int1; std::cout << endl;
        this->setPriority(int1);
    }
    else if(input3 == 4){
        std::cout << "Enter your new value: "; cin >> string3; std::cout << endl;
        this->setClassification(string3);
    }
    else if(input3 == 5){
        std::cout << "Enter your new value: "; cin >> int2; std::cout << endl;
        this->setDuration(int2);
    }
    else if(input3 == 6){
        std::cout << "Enter your new value: "; cin >> string4; std::cout << endl;
        this->setDueDate(string4);
    }
    else if(input3 == 7){
        std::cout << "Enter your new value: "; cin >> bool1; std::cout << endl;
        this->setCompletion(bool1);
    }
    else if(input3 == 8){
        std::cout << "Enter your new value: "; cin >> int3; std::cout << endl;
        this->setProgress(int3);
    }
}
// void Task::deleteObj(int index2, TaskList &temp){
//     std::string input;
//     int index = index2-1; //bc user enters 1 but index is 0
//     std::cout << "Would you like to delete this task? Y/N" << std::endl;
//     cin >> input;
//     //TaskList tempList = *temp;
//     //*tempList = temp;

//     if(input == "Y"){
//         std::cout << "Task deleted. Undo? Y/N" << std::endl;
//         cin >> input;
//         if(input == "Y"){
//             std::cout << "Task restored" << std::endl;    
//         }
//         else{
//             //will this acutally edit the taskList?

//             for(int i = index; i < temp.getList().size()-1; i++){
//                 Goal *tempTask;
//                 tempTask = temp.getList().at(i+1);
//                 temp.getList().at(i+1) = temp.getList().at(i);
//                 temp.getList().at(i) = tempTask;
//             }
//             temp.getList().pop_back();
//         }
//     }
//     else{
//         std::cout << "Task was not deleted" << std::endl;    
//     }
// }
