#include <iostream>
#include <vector>
#include <ostream>
#include "../header/TaskList.h"
#include "../header/Task.h"
#include "../header/Goal.h"

using namespace std;

void TaskList::print(std::ostream &out){
    out << this->getName() << std::endl;
    int size = listObj.size();
    for(int i = 0; i < size; i++){
        listObj.at(i)->print(out);
    }
   
}

void TaskList::edit(std::ostream &out, int input, string update){
    if (input = 0){
        out << "What would you like to do?\n";
   	out << "1. Edit list name\n";
  	out << "2. Remove a task\n"; //this prints a 1 before for some reason
        out << "3. Add a task\n";;
  	cin >>input;
    }
    if(input == 1){
        std::string newName;
        out << "Please enter the new name" << std::endl;
        cin.ignore(); getline(cin, newName);
        this->setName(newName);

        this->setLookInMain(false);
    }

    else if(input == 2){
        std::string taskName = "";
        out << "Enter the name of the task you want to remove: "; cin.ignore(); getline(cin, taskName); out << std::endl;
        Goal* tempTask = this->findTask(taskName);
        if(tempTask->getName() == ""){
            out << "Task not present" << std::endl;
        }
        else{
            int tempInt = this->findIndex(taskName);
            for(int i = tempInt; i < this->getList().size()-1; i++){
                Goal *tempTask;
                tempTask = this->getList().at(i+1);
                this->getList().at(i+1) = this->getList().at(i);
                this->getList().at(i) = tempTask;
            }
            this->getList().pop_back();
        }
        this->setLookInMain(false);
    }
    else if(input == 3){
        int input2;
        out << "Do you want to 1. Add an existing task or 2. Add a new task to this list?" << std::endl;
        cin >>input2;
        
        if(input2 == 1){
            this->setLookInMain(true);
        }
        else{
            std::string string1, string2, string3, string4;
            int int1, int2, int3;
            bool bool1 = false; //set to false bc it's a new task
            cin.ignore();
            out << "Create a name: "; getline(std::cin, string1);
            out << std::endl << "Write a short description: "; getline(std::cin, string2);
            out << std::endl << "Set the priority level (1-10): "; cin >> int1;
            out << std::endl << "Classify your task: "; cin.ignore(); getline(cin, string3);
            out << std::endl << "How many days will this task last? "; cin >> int2;
            out << std::endl << "Create a due date in the form XX/YY/ZZ: "; cin.ignore(); getline(cin, string4);
            out << std::endl << "Enter a progress level (1-10): "; cin >> int3; out << std::endl;
            Goal *newTask = new Task(string1, string2, int1, int2, string4, string3, bool1, int3);
            this->addTask(newTask);
            this->setLookInMain(false);
        }
    }
}

void TaskList::addTask(Goal *newOne){
    listObj.push_back(newOne);
}

void TaskList::deleteObj(std::ostream &out) {
    std::string input;
    out << "Would you like to delete this list? Y/N: ";
    std::cin >> input;
    out  << std::endl;
    if(input == "Y"){
        out << "List deleted. Undo? Y/N: ";
        cin >> input;
        out << std::endl;
        if(input == "Y"){
            out << "List restored" << std::endl;
        }
        else{
            this->setBool(true);        
        }
    }
}

vector<Goal*>& TaskList::getList(){
    return listObj;
}

Goal* TaskList::findTask(string tempName){
    vector<Goal*> tempVec = this->getList();
    if(tempVec.size() == 0){
        Task *newTask = new Task();
        Goal *tempGoal = dynamic_cast<Task *>(newTask);
        //delete newTask;
        return tempGoal;
    }
    Goal *tempTask = tempVec.at(0);
    std::string tempName2 = tempTask->Goal::getName();
    int i = 0;
    
    while(tempName2 != tempName){
        i++;
        if(i >= tempVec.size()){
            Task *newTask = new Task();
            Goal *tempGoal = dynamic_cast<Task *>(newTask);
            //delete newTask;
            return tempGoal;
        }

        tempTask = tempVec.at(i);
        tempName2 = tempTask->Goal::getName();
    }

    return tempVec.at(i);
}

int TaskList::findIndex(string tempName){
    vector<Goal*> tempVec = this->getList();
    Goal *tempTask = tempVec.at(0);

    std::string tempName2 = tempTask->Goal::getName();
    int i = 0;

    while(tempName2 != tempName){
        i++;
        if(i >= listObj.size()){
            return -1;
        }
        tempTask = tempVec.at(i);
        tempName2 = tempTask->Goal::getName();
    }
    return i;
}
