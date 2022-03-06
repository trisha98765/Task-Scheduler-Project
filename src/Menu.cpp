#include "../header/TaskList.h"
#include "../header/Task.h"
#include "../header/Goal.h"
#include "../header/Menu.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

TaskList findTaskList(string inputName, vector<TaskList> tempList){
    for(int i = 0; i < tempList.size(); i++){
        if(inputName == tempList.at(i).getName()){
            return tempList.at(i);
        }
    }
    TaskList none = TaskList();
    return none;
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

        if(input == 2){
            int input2 = 0;
            std::cout << "1. Create new task" << std::endl << "2. Edit existing task" << std::endl << "3. Delete task" << std::endl;
            cin >> input2;

            std::string string1, string2, string3, string4;
            int int1, int2, int3;
            bool bool1;
            if(input2 == 1){
                bool1 = false; //set to false bc it's a new task
                Task temp; 
                Goal *newTask = temp.userInput();
                unsorted.addTask(newTask);
            }
            else if(input2 == 2){ //maybe we could print the tasks out in case user doesn't remember name?
                std::string taskName = "";
                std::cout << "Enter the name of the task you want to edit: "; cin.ignore(); getline(cin, taskName); std::cout << std::endl;
                Goal* tempTask = unsorted.findTask(taskName);
                if(tempTask->getName() == ""){
                    std::cout << "Task not present" << std::endl;
                }
                else{
                    tempTask->edit(std::cout,0,"");
                }
            }
            else if(input2 == 3){
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
            else{
                std::cout << "Invalid input" << std::endl;
            }
        }
        else if(input == 1){
            int input2 = 0;
            std::cout << "1. Create new list" << std::endl << "2. Edit existing list" << std::endl << "3. Delete list" << std::endl;
            cin >> input2;

            if(input2 == 1){
                std::string listName;
                std::cout << "What would you like to call this list? ";
                cin.ignore();
                getline(cin, listName);
                std::cout << endl;

                TaskList newList = TaskList(listName);
                allLists.push_back(newList);
            }
            else if(input2 == 2){
                std::string listName = "";
                std::cout << "Enter the name of the list you want to edit: "; cin.ignore(); getline(cin, listName); std::cout << std::endl;
                TaskList temp = findTaskList(listName, allLists);
                if(temp.getName() == "default"){
                    std::cout << "Task list not present" << std::endl;
                }
                else{
                    temp.edit(std::cout,0,"");
                    if(temp.getLookInMain()){ //adds an already existing task to the list
                        std::string taskName = "";
                        std::cout << "Enter the name of the task you want to add: "; cin.ignore(); getline(cin, taskName); std::cout << std::endl;
                        Goal* tempTask = unsorted.findTask(taskName);
                        if(tempTask->getName() == ""){
                            std::cout << "Task not present" << std::endl;
                        }
                        else{
                            temp.addTask(tempTask);
                            
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
                    allLists.at(lookIndex) = temp;
                }
            }
            else if(input2 == 3){
                std::string listName = "";
                std::cout << "Enter the name of the list you want to edit: "; cin.ignore(); getline(cin, listName); std::cout << std::endl;
                TaskList temp = findTaskList(listName, allLists);
                if(temp.getName() == "default"){
                    std::cout << "Task list not present" << std::endl;
                }
                else{
                    temp.deleteObj(std::cout);
                    if(temp.getBool()){
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
            else{
                std::cout << "Please enter a valid input" << std::endl;
            }
        }
        else if(input == 3){
            std::cout << std::endl;
            for(int i = 0; i < allLists.size(); i++){
                allLists.at(i).print(std::cout);
                std::cout << std::endl;
            }
            std::cout << "Here are your unsorted tasks:" << std::endl << std::endl;
            unsorted.print(std::cout);
            std::cout << std::endl;
        }
        else{
            std::cout << "Please enter a valid input" << std::endl;
            cin >> input;
        }
}

