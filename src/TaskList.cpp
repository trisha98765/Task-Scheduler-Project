#include <iostream>
#include <vector>
#include "../header/TaskList.h"
#include "../header/Task.h"

using namespace std;

void TaskList::print(std::ostream &out){ // i think this argument should be a Goal object so it can print a task or taskList object
  // this does not compile because 'this' is not pointing at the vector
    /* int size = this.size();
    for(int i = 0; i < size; i++){
       // this.at(i)->print(); //don't know if this is correct or not   
    }
   */
}

void TaskList::edit(){
    // TODO
}
/*
void TaskList::deleteObj() {
    // TODO
    // to delete a task list that should happen in the task list class
}
*/
Task TaskList::findTask(){
    

}

/* to delete an individual task, to work with the composite pattern it needs to be a part of the task class because deleteObj is a pure virtual function to be redefined in both child classes, we can pass the vector of tasks as an argument to get access to the list*/
void TaskList::deleteObj(int index2) {
    std::string input;
    int index = index2-1; //bc user enters 1 but index is 0
    std::cout << "Would you like to delete this task? Y/N" << std::endl;
    cin >> input;
    if(input == "Y"){
        std::cout << "Task deleted. Undo? Y/N" << std::endl;
        cin >> input;
        if(input == "Y"){
            std::cout << "Task restored" << std::endl;    
        }
        // the else statement doesnt compile because 'this' is not pointing at the vector
       /* else{
            for(int i =index; i < this->size()-1; i++){
                this->at(i) = this->at(i+1);
            }
            this->pop_back();
        }*/ 
    }
    else{
        std::cout << "Task was not deleted" << std::endl;    
    }
}
