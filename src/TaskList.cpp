#include <iostream>
#include <vector>
#include "TaskList.h" //change these back to ../header/
#include "Task.h"
#include "Goal.h"

using namespace std;

TaskList::TaskList(){

}

void TaskList::print(){ // i think this argument should be a Goal object so it can print a task or TaskList object
  // this does not compile because 'this' is not pointing at the vector
    int size = listObj.size();
    for(int i = 0; i < size; i++){
       listObj.at(i)->print(); //don't know if this is correct or not   
    }
   
}


void TaskList::edit(){
    // TODO
}
void TaskList::addTask(Goal *newOne){
    listObj.push_back(newOne);
}
// void TaskList::deleteObj(int index, TaskList &tempList) {
//     std::string input;
//     std::cout << "Would you like to delete this list? Y?N" << std::endl;
//     std::cin >> input;
//     if(input == "Y"){
//         std::cout << "List deleted. Undo? Y?N" << std::endl;
//         if(input == "Y"){
//             std::cout << "List restored" << std::endl;
//         }
//         else{
//             //temp.at(index).erase();
//         }
//     }
// }

vector<Goal*>& TaskList::getList(){
    return listObj;
}

Goal* TaskList::findTask(string tempName){ //what if you didn't find anything?
    vector<Goal*> tempVec = this->getList();
    Goal *tempTask = tempVec.at(0);

    std::string tempName2 = tempTask->getName();
    int i = 0;

    while(tempName2 != tempName){
        i++;
        tempTask = tempVec.at(i);
        tempName2 = tempTask->getName();
    }
    
    return tempVec.at(i);
}

int TaskList::findIndex(string tempName){
    vector<Goal*> tempVec = this->getList();
    Goal *tempTask = tempVec.at(0);

    std::string tempName2 = tempTask->getName();
    int i = 0;

    while(tempName2 != tempName){
        i++;
        tempTask = tempVec.at(i);
        tempName2 = tempTask->getName();
    }
    return i;
}
