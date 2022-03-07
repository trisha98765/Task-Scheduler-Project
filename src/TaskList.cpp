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

void TaskList::setName(std::string n){
	name = n;
}

void TaskList::edit(std::ostream &out, int input, string update){
    if(input == 0){
        out << "What would you like to do?\n";
   	cout << "1. Edit list name\n";
  	cout << "2. Remove a task\n";
        cout << "3. Add an existing task\n";
        cout << "4. Add a new task\n";
  	cin >> input;
    }
    if(input == 1){
        if(update == ""){
            std::string newName;
            out << "Please enter the new name" << std::endl;
            cin.ignore(); getline(cin, newName);
            update = newName;
	    this->setName(newName);
        }
	else{
	    this->Goal::setName(update);
	}
        //this->Goal::setName(update);
        this->setLookInMain(false);
    }

    if(input == 2){
        if(update == ""){
            std::string taskName = "";
            out << "Enter the name of the task you want to remove: "; 
            cin.ignore(); getline(cin, taskName); out << std::endl;
            update = taskName;
        }
        Goal* tempTask = this->findTask(update);
        if(tempTask->getName() == ""){
            out << "Task not present" << std::endl;
        }
        else{
            int tempInt = this->findIndex(update);
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
    if(input == 3){
            this->setLookInMain(true);
    }
    if (input == 4){
        Task temp;
        Goal *newTask = temp.userInput();
        this->addToList(newTask);
        /*this->addTask(newTask);
        this->setLookInMain(false);*/
    }
}

void TaskList::addToList(Goal* newTask){
    this->addTask(newTask);
    this->setLookInMain(false);
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
