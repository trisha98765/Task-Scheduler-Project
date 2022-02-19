 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Task Scheduler
 
 > Authors: [Melissa Hidalgo](https://github.com/melle-issa),  [Trisha Agrawal](https://github.com/trisha112), [Evan Shimoniak](https://github.com/eshimoniak-ucr), [Pranoy Giri](https://github.com/pranoygiri)
 
 ## Expectations
 > * Incorporate **at least one** design pattern
 >   * It is recommended that you include a design pattern that we will teach this session (Composite, Strategy, or Visitor)

## Phase I: Project Description
 > Why is it important or interesting to you?
 * We found this project interesting because many people - especially college students - need help managing their list of things to do. The high level of customization with the task lists is an extra challenge for us and should be a good opportunity to grow our skills individually and as a team.
 > What languages/tools/technologies do you plan to use?
 * We will be doing this project in C++
 * Tools: [Git](https://git-scm.com/), [GitHub](https://github.com/), [Vim](https://www.vim.org), [CMake](https://cmake.org), [Google Test](https://github.com/google/googletest), [Command Line Compilation](https://docs.microsoft.com/en-us/cpp/build/walkthrough-compile-a-c-program-on-the-command-line?view=msvc-170), and [Linux File System](https://tldp.org/LDP/intro-linux/html/sect_03_01.html). 
 > What will be the input/output of your project?
 * Input:
    * allowing the user to name different lists for tasks, enter, edit, set a priority level, enter a description and delete tasks. These options will be presented to the user through a menu, where the user will be able to enter their choices.
 * Output:
    * printing the tasks, which could be in progress, completed, sorted by completion time or sorted by priority. These options will also be presented through a menu for the user to select from.
 > What are the features that the project provides? 
 * Some other features of our project include the ability to undo the deletion of a task and finding a specific task. 
 * We intend to have 5 files: `main.cpp`, `task.cpp`, `taskList.cpp`, `task.h`, `taskList.h`. 
 * Most of the methods in the task files will be setters and getters along with functions to delete, edit, and print tasks. In the taskList files, we'll implement functions to delete and edit lists as well as functions to find a task, remove a task, and print the list details. When the user chooses to delete a task, they are also given the option to undo their delete command, which brings the previously deleted task back onto their task list.

 ## Phase II

## Class Diagram

![Structural UML Diagram](https://lucid.app/publicSegments/view/44dcc957-5e92-4d40-9203-75094bef565e/image.png)

* Our project will include a way to create an individual task as well as group them in a task list. The main component is `Goal`, a class that consists of getters and methods for printing, editing and deleting. One child class of `Goal` is `Task`, where one object would represent an individual task. Another child class of `Goal` is `TaskList`, where one object of this class would represent an entire list of tasks. Finally, the `MainView`, `TaskListView` and `TaskView` classes will be used to create visuals of the objects and menu for the user.
 * The `Task` class involves setters and getters which will be used to collect information about a specific task and it is a child of the `Goal` class. This includes getting the name, description, priority, due date and duration of a task. It will also consist of the methods that will be presented to the user through a menu, which includes printing, editing and deleting an individual task.
 * The `TaskList` class has an aggregation association with the `Goal` class. This is because the TaskList class has a private attribute where a vector of Task objects is made. The `TaskList` class can be used to set the name of a list of tasks which will be entered by the user. It will consist of methods to print, edit or delete an individual task. It will also have a searching method to find a specific task which will not be a menu option for the user, it will instead be used by the print, edit and delete methods.
 * The `MainView` class is the main graphical interface that will be used to present the program to the user. It will consist of a vector of `Task` objects and a vector of `TaskList` objects. 
 * The `TaskListView` class is a child class of `MainView` through a composition association. It consists of a vector of `TaskView` objects and methods that allow for visual representations of a task list.
 * The `TaskView` class is a child class of `TaskListView` through a composition association. It consists of methods that allow for visual representations of tasks.
 
 ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with a reader (using Calendly). Your entire team must be present. This meeting will occur on week 8 but NOT during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
