#include <iostream>
#include <vector>
#include "TaskList.h"
#include "Task.h"

using namespace std;

void TaskList::print(){
    int size = this->size();
    for(int i = 0; i < size; i++){
        this.at(i)->print(); //don't know if this is correct or not   
    }
}

void TaskList::deleteObj(int index, vector<TaskList> &temp ) {
    std::string input;
    std::cout << "Would you like to delete this list? Y?N" << std::endl;
    std::cin >> input;
    if(input == "Y"){
	std::cout << "List deleted. Undo? Y?N" << std::endl;
	if(input == "Y"){
	    std::cout << "List restored" << std::endl;
	}
	else{
	    temp.clear();
	}
    }
}
void TaskList::deleteTask(int index2;) {
    std::string input;
    int index = index2-1; //bc user enters 1 but index is 0
    std::cout << "Would you like to delete this task? Y/N" << std::endl;
    cin >> input;
    if(input == 'Y'){
        std::cout << "Task deleted. Undo? Y/N" << std::endl;
        cin >> input;
        if(input == 'Y'){
            std::cout << "Task restored" << std::endl;    
        }
        else{
            for(int i =index; i < this->size()-1; i++){
                this->at(i) = this->at(i+1);
            }
            this->pop_back();
        }
    }
    else{
        std::cout << "Task was not deleted" << std::endl;    
    }
}
