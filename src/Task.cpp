#include <iostream>
#include <vector>
#include <string>
#include "Task.h"

using namespace std;

void Task::print(){
    cout << "Name: " << this->getName() << endl;
    cout << "Due: " << this->getDueDate() << " Priority: " << this->getPriority() << endl;
    cout << "Classification: " << this-> getClassification() << "Duration: " << this->getDuration() << endl;
    cout << "Description: " << this-> getDescription() << endl;
}

void Task::delete() {
    // TODO
}
