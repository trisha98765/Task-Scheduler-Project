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

void TaskList::deleteTaskList() {
    // TODO
}
