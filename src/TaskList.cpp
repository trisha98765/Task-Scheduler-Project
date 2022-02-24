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
	    temp.at(index).erase();
	}
    }
}

Task TaskList::findTask(){
   Task temp = new Task();
    return temp; //just temporary for testing
}