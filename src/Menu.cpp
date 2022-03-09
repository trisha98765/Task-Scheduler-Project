#include "../header/TaskList.h"
#include "../header/Task.h"
#include "../header/Filter.h"
#include "../header/Goal.h"
#include "../header/Menu.h"
#include "../header/InputHelper.h"

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

TaskList* findTaskList(string inputName, vector<TaskList>& listToSearch){
    for(int i = 0; i < listToSearch.size(); i++){
        if(inputName == listToSearch.at(i).getName()){
            return &listToSearch.at(i);
        }
    }
    
    return nullptr;
}
int findTaskListIndex(string inputName, vector<TaskList> tempList){
    for(int i = 0; i < tempList.size(); i++){
        if(inputName == tempList.at(i).getName()){
            return i;
        }
    }   
    return -1;
}
void deleteTask(TaskList &unsorted, int tempInt, std::ostream &out){ 
    if(tempInt != -1){
        for(int i = tempInt; i < unsorted.getList().size()-1; i++){
            Goal *tempTask;
            tempTask = unsorted.getList().at(i+1);
            unsorted.getList().at(i+1) = unsorted.getList().at(i);
            unsorted.getList().at(i) = tempTask;
        }
        unsorted.getList().pop_back();
    }
    else{
        out << "Task not found.";
    }
}

void menu(int input,TaskList &unsorted, vector<TaskList> &allLists){
        // Create new task/edit existing task
        if(input == 2){
            int submenuInput = 0;

            std::cout << "1. Create new task" << std::endl << "2. Edit existing task" << std::endl << "3. Delete task" << std::endl << "4. Go back" << std::endl << std::endl;
            submenuInput = readInt(cin, cout);

            // Create new task
            if(submenuInput == 1){
                unsorted.addTask(taskFromInput());
            }
            // Edit existing task
            else if(submenuInput == 2){ //maybe we could print the tasks out in case user doesn't remember name?
                std::string taskName = "";
                std::cout << "Enter the name of the task you want to edit: "; cin.ignore(); getline(cin, taskName); std::cout << std::endl;
                Goal* tempTask = unsorted.findTask(taskName);
                if(tempTask->getName() == ""){
                    std::cout << "Task not present" << std::endl << std::endl;
                }
                else{
                    tempTask->edit(std::cout,0,"");
                }
            }
            // Delete task
            else if(submenuInput == 3){
                std::string taskName = "";
                std::cout << "Enter the name of the task you want to delete: "; cin >> taskName; std::cout << std::endl;
                Goal *tempGoal = unsorted.findTask(taskName);
                if(tempGoal->getName() == ""){
                    std::cout << "Task not present" << std::endl;
                }
                else{
                    Task *tempTask = dynamic_cast<Task *>(tempGoal);

                    int tempInt = unsorted.findIndex(taskName);
                    tempTask->deleteObj(std::cout);

                    if(tempTask->getDeleted()){
                        deleteTask(unsorted,tempInt,std::cout);
                        std::cout << "Task deleted" << std::endl;
                    }
                }
            }
            else if(submenuInput == 4) {
                return;
            }
            else{
                std::cout << "Invalid input" << std::endl;
            }
        }
        // Create new list/edit existing list
        else if(input == 1){
            int submenuInput = 0;
          
            std::cout << "1. Create new list" << std::endl << "2. Edit existing list" << std::endl << "3. Delete list" << std::endl << "4. Go back" << std::endl << std::endl;
            submenuInput = readInt(cin, cout);

            // Create new list
            if(submenuInput == 1){
                std::string listName;
                std::cout << "What would you like to call this list? ";
                cin.ignore();
                getline(cin, listName);
                std::cout << endl;

                TaskList newList = TaskList(listName);
                allLists.push_back(newList);
            }
            // Edit existing list
            else if(submenuInput == 2){
                std::string listName = "";
                std::cout << "Enter the name of the list you want to edit: "; 
                cin.ignore(); getline(cin, listName); std::cout << std::endl;
                TaskList* temp = findTaskList(listName, allLists);
                if(temp == nullptr){
                    std::cout << "Task list not present" << std::endl;
                }
                else{
                    temp->edit(std::cout,0,"");
                    if(temp->getLookInMain()){ //adds an already existing task to the list
                        std::string taskName = "";
                        std::cout << "Enter the name of the task you want to add: "; 
                        cin.ignore(); getline(cin, taskName); std::cout << std::endl;
                        Goal* tempTask = unsorted.findTask(taskName);
                        if(tempTask->getName() == ""){
                            std::cout << "Task not present" << std::endl;
                        }
                        else{
                            temp->addTask(tempTask);
                            
                            int tempInt = unsorted.findIndex(taskName);
                            for(int i = tempInt; i < unsorted.getList().size()-1; i++){
                                Goal *tempTask; 
                                tempTask = unsorted.getList().at(i+1);
                                unsorted.getList().at(i+1) = unsorted.getList().at(i);
                                unsorted.getList().at(i) = tempTask;
                            }
                            //delete tempTask;
                            unsorted.getList().pop_back();
                        }
                    }
                    int lookIndex = findTaskListIndex(listName, allLists);
                    allLists.at(lookIndex) = *temp;
                }
            }
           // Delete list
           else if(submenuInput == 3){
                std::string listName = "";
                std::cout << "Enter the name of the list you want to delete: "; 
                cin.ignore(); getline(cin, listName); std::cout << std::endl;
                TaskList* temp = findTaskList(listName, allLists);
                if(temp == nullptr){
                    std::cout << "Task list not present" << std::endl;
                }
                else{
                    temp->deleteObj(std::cout);
                    if(temp->isDeleted()){
                        int index = findTaskListIndex(listName, allLists);
                        for(int i = index; i < allLists.size()-1; i++){
                            TaskList tempList;
                            tempList = allLists.at(i+1);
                            allLists.at(i+1) = allLists.at(i);
                            allLists.at(i) = tempList;
                        }
                        allLists.pop_back();
                    }
                }
            }
            else if(submenuInput == 4) {
                return;
            }
            else{
                std::cout << "Please enter a valid input" << std::endl;
            }
        }
        // Print list
        else if(input == 3){
            for(int i = 0; i < allLists.size(); i++){ // prints every list together
                std::cout << "Here are your lists:\n";
                allLists.at(i).print(std::cout);
                unsorted.print(std::cout);
                std::cout << std::endl;
            }
            if(allLists.size() == 0){ // if there are just tasks with no specific list
               std::cout << "Here are your unsorted tasks:\n";
               unsorted.print(std::cout);
               std::cout << std::endl;
            }
        }
        // Filter
        else if(input == 4){
            int submenuInput = 0, answer = 0;
            std::string searchVal;

            std::cout << "Which would you like to filter? \n1. Unsorted Tasks \n2. Yours task lists\n3. Go back" << std::endl << std::endl;
            submenuInput = readInt(cin, cout);

            if (submenuInput == 3) {
                return;
            }

            std::cout << "Which would you like to sort by?\n1. Due Date\n2. Classification\n3. Priority\n4. Due soon" << std::endl << std::endl;
            std::cin >> answer;
            std::cout << "What is your filtering criteria? (Enter the month (MM) for due date, classification or priority):\n";
            std::cin >> searchVal;
            if(submenuInput == 1){
                filter(unsorted,answer,searchVal,std::cout);
            }
            else if(submenuInput == 2){
                std::string listName = "";
                std::cout << "Enter the name of the list you want to filter: "; 
                cin.ignore(); getline(cin, listName); std::cout << std::endl;
                TaskList* temp = findTaskList(listName, allLists);
                if(temp->getName() == "default"){
                        std::cout << "Task list not present" << std::endl;
                }
                else{
                    filter(*temp,answer,searchVal,std::cout);
                }
            }
            else{
                std::cout << "Invalid input" <<std::endl;
            }
        } 
        // removed if (input == 5) statement bc this is called in a while loop in main
        else{
            std::cout << "Please enter a valid menu choice." << std::endl;
            cin >> input;
        }
}

