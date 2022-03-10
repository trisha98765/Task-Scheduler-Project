# Task Scheduler

 > Authors: [Melissa Hidalgo](https://github.com/melle-issa),  [Trisha Agrawal](https://github.com/trisha112), [Evan Shimoniak](https://github.com/eshimoniak-ucr), [Pranoy Giri](https://github.com/pranoygiri)

## Phase I: Project Description
 Why is it important or interesting to you?
 * We found this project interesting because many people - especially college students - need help managing their list of things to do. The high level of customization with the task lists is an extra challenge for us and should be a good opportunity to grow our skills individually and as a team.
 What languages/tools/technologies do you plan to use?
 * We will be doing this project in C++
 * Tools: [Git](https://git-scm.com/), [GitHub](https://github.com/), [Vim](https://www.vim.org), [CMake](https://cmake.org), [Google Test](https://github.com/google/googletest), [Command Line Compilation](https://docs.microsoft.com/en-us/cpp/build/walkthrough-compile-a-c-program-on-the-command-line?view=msvc-170), and the [Linux File System](https://tldp.org/LDP/intro-linux/html/sect_03_01.html). 
 
 What will be the input/output of your project?
 * Input:
    * Allowing the user to name different lists for tasks, enter, edit, set a priority level, enter a description and delete tasks. These options will be presented to the user through a menu, where the user will be able to enter their choices.
 * Output:
    * A menu is printed that allows the user to pick an action; create new task, new task list, delete task, delete task list, edit task, edit task list, print list, filter through lists and quit the program. Output is printed in a box format with texts of different colors.

 What are the features that the project provides? 
 * Some other features of our project include the ability to undo the deletion of a task, finding a specific task and print a filtered version of a task list based on the users specifications.. 
 * We intend to have 13 files: `Menu.cpp, Menu.h, Filter.cpp, Filter.h, main.cpp, Task.cpp, TaskList.cpp, Task.h, TaskList.h. Goal.h Goal.cpp InputHelper.h InputHelper.cpp`.
 * The graphics involve the files: `ColorManager.h ColorManager.cpp PrintHelper.h PrintHelper.cpp View.h View.cpp` 
 * Most of the methods in the task files will be setters and getters along with functions to delete, edit, and print tasks. In the taskList files, we'll implement functions to delete and edit lists as well as functions to find a task, remove a task, and print the list details (sorted or unsorted). When the user chooses to delete a task, they are also given the option to undo their delete command, which brings the previously deleted task back onto their task list.

## Phase II

## Class Diagram

![Structural UML Diagram](https://lucid.app/publicSegments/view/44dcc957-5e92-4d40-9203-75094bef565e/image.png)

Our `Goal`, `TaskList`, and `Task` classes on the left half of the diagram were created using the Composite strategy. As seen above, `TaskList` and `Task` both inherit from `Goal` while the latter two compose a Task list.

* Our project will include a way to create an individual task as well as group them in a task list. The main component is `Goal`, a class that consists of getters and methods for printing, editing and deleting. One child class of `Goal` is `Task`, where one object would represent an individual task. Another child class of `Goal` is `TaskList`, where one object of this class would represent an entire list of tasks. Finally, the `ColorManager.h PrintHelper.h and View.h` files will be used to organize the output in boxes when presented to the user.
 * The `Task` class involves setters and getters which will be used to collect information about a specific task and it is a child of the `Goal` class. This includes getting the name, description, priority, due date and duration of a task. It will also consist of the methods that will be presented to the user through a menu, which includes printing, editing and deleting an individual task.
 * The `TaskList` class has an aggregation association with the `Goal` class. This is because the TaskList class has a private attribute where a vector of Task objects is made. The `TaskList` class can be used to set the name of a list of tasks which will be entered by the user. It will consist of methods to print, edit or delete an individual task. It will also have a searching method to find a specific task which will not be a menu option for the user, it will instead be used by the print, edit and delete methods.
 * The `Filter` functions allow the user to view specific task in a task list based on the due date, priority level, and classification. It uses functions from `Task` in order to check for validity with the provided arguments and print the task's details.
 * The `Menu` functions present options to the user by printing a menu with various choices before operating on Task and TaskList objects.

## Phase III

> What design pattern did you use?
 * We picked the Composite design pattern. We decided this was the best pattern to follow because our project consists of different levels of hierarchy, however the user will treat them the same. Using this pattern, we implemented our goals, tasks, and task lists. Here, goals are the component, task lists are the composite, and tasks are the leaves. The Composite design pattern allowed our code to be more organized and prevented us from having to write multiple repeat functions. 

 > During the meeting with your reader you will discuss: 
 * How effective your last sprint was (each member should talk about what they did)
     * Melissa(filter, print) Trisha(test cases, Task and TaskList files), Evan(graphics set up for user interface), Pranoy(editing tasks and tasklist).
 * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
     * We didn't finish the deleting functions and we edited our epics accordingly.
 * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
     * We decided to only have an undo feature for deleting a task or task list because undoing edits to a task or task list would be repetitive of the edit features. We also took some time to figure out how to apply the composite design pattern to our project but we were able to implement it by adding the Goal class as the component.
 * What tasks you are planning for this next sprint.
     * Finish delete functions, finish graphics, and finish testing for every method.


## Final deliverable
 * Our Kanban Board is up to date and contains plans for a future sprint. All our completed issues with user stories have been moved to the Done column and the only remaining issues in To Do are bug fixes and enhancement ideas.  
 * Our README file reflects the current status of our project including the UML diagram and any feature descriptions. Previous versions are still visible through the commit history as well as in small notes under our diagram about what we changed throughout the project.

## Screenshots
 > Screenshots of the input/output after running your application
## Installation/Usage

* See `INSTALL.md` for installation instructions
* See `USAGE.md` for usage instructions when running the program.

## Testing
 * We used the Google Test Suite for testing our code and wrote unit tests to ensure all of our functions work as expected. The unit tests tested the functionality of every method in the Task and TaskList class that would be used by the user to add, edit or delete tasks.
     * In test suite "TaskConstructorTest," the default and overloaded constructors were tested as well as the getters for every private variable in the class.
     * In test suite "TaskMethodTest," adding, editing and deleting a task was tested. Invalid input and deleting a task that does not exist was also tested.
     * In test suite "FilterTest," the four different filtering methods, by due date, classification, priority and due soon, were tested by comparing the expected output to actual output.
     * In test suite "TaskListMethodTest," the default and overloaded constructor were tested. Deleting a task in a task list, adding a task to an old list and adding a task to a new list was also tested. 
  * The screenshot below shows no memory leaks for the 18 unit tests that were written for this program.
 <img width="541" src = https://user-images.githubusercontent.com/74077340/157297257-a7774aed-d8e8-4d9a-928e-f889ef1c52e3.png>
 * We also created a bash script for automating valgrind testing. The script pipes sample input from text files and saves the valgrind output to log files in a separate directory. This speeds up testing and ensures greater consistency.
