#include "TaskList.h" //change these back to say "../header/"
#include "Task.h"
#include "Goal.h"
#include <iostream> //are we suppposed to have this?
#include <vector>
#include <string>

using namespace std;


int main(){
    TaskList unsorted = TaskList();

    int input = 0;

    while(input != 4){
        std::cout << "What would you like to do?" << std::endl << "1. Create new list/edit existing list" << std::endl 
        << "2. Create new task/edit existing task" << std::endl << "3. Print list" << std::endl << "4. Quit" << std::endl;
        cin >> input;

        if(input == 2){
            int input2 = 0;
            std::cout << "1. Create new task" << std::endl << "2. Edit existing task" << std::endl << "3. Delete task" << std::endl;
            cin >> input2;

            std::string string1, string2, string3, string4;
            int int1, int2, int3;
            bool bool1;
            if(input2 == 1){
                bool1 = false; //set to false bc it's a new task
                cin.ignore();
                std::cout << "Create a name: "; getline(std::cin, string1);
                std::cout << std::endl << "Write a short description: "; getline(std::cin, string2);
                std::cout << std::endl << "Set the priority level: "; cin >> int1;
                std::cout << std::endl << "Classify your task: "; cin.ignore(); getline(cin, string3);
                std::cout << std::endl << "Set the duration: "; cin >> int2;
                std::cout << std::endl << "Create a due date: "; cin.ignore(); getline(cin, string4);
                std::cout << std::endl << "Enter a progress level: 1-10: "; cin >> int3; std::cout << std::endl;
                Goal *newTask = new Task(string1, string2, int1, int2, string4, string3, bool1, int3);
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
                    tempTask->edit();
                }
            }
            // else if(input2 == 3){
            //     std::string taskName = "";
            //     std::cout << "Enter the name of the task you want to delete: "; cin >> taskName; std::cout << std::endl;
            //     Goal *tempGoal = unsorted.findTask(taskName);

            //     Task *tempTask = dynamic_cast<Task *>(tempGoal);

            //     int tempInt = unsorted.findIndex(taskName);
            //     tempTask->deleteObj(tempInt, unsorted);
            // }
            else{
                std::cout << "Invalid input" << std::endl;
            }
        }
        else if(input == 1){
            std::cout << "edit list";
        }
        else if(input == 3){
            unsorted.print();
        }
        else if(input == 4){
            break;
        }
        else{
            std::cout << "Please enter a a valid input" << std::endl;
            cin >> input;
        }
    }
    return 0;
}
