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
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller actionable development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 8. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members

## Class Diagram
 > <img width="750" alt="UML chart" src="uml.svg" />
 > 
 > Our project will include a way to create an individual task as well as group them in a task list. To the left and right of these classes are the method classes we will be implementing in order to perform all of the expected actions on both the tasks and tasks in a list. These include editing, finding, deleting, and printing.
 
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
 
