#include "../header/TaskList.h"
#include "../header/Task.h"
#include "../header/Goal.h"
#include "../header/Menu.h"
//#include "../header/Filter.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    TaskList unsorted = TaskList("Unsorted");
    vector<TaskList> allLists;
    int input = 0;
    // start
    std::cout << "What would you like to do?" << std::endl << "1. Create new list/edit existing list" << std::endl
    << "2. Create new task/edit existing task" << std::endl << "3. Print list" << std::endl <<  "4. Filter"
        << std::endl << "5. Quit" << std::endl;
    cin >> input;
    while (!cin.good()) {
            std::cout << "Please enter an integer" << std::endl;
            cin.clear();
            cin.ignore(256, '\n');
    }
    while(input != 5){
        menu(input,unsorted,allLists);
        std::cout << "What would you like to do?" << std::endl << "1. Create new list/edit existing list" << std::endl 
        << "2. Create new task/edit existing task" << std::endl << "3. Print list" << std::endl <<  "4. Filter" 
        << std::endl << "5. Quit" << std::endl;
        cin >> input;
        while (!cin.good()) {
            std::cout << "Please enter an integer" << std::endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    return 0;
}
