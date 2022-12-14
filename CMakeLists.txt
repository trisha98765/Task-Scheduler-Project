CMAKE_MINIMUM_REQUIRED(VERSION 2.8)A

SET(CMAKE_CXX_STANDARD 11)

# Main production executable
ADD_EXECUTABLE(task-scheduler
    src/main.cpp
    src/Goal.cpp
    src/Menu.cpp
    src/Task.cpp
    src/TaskList.cpp
    src/Filter.cpp
    src/InputHelper.cpp
    src/ColorManager.cpp
    src/PrintHelper.cpp
    src/View.cpp
)

# GTest testing executable
ADD_SUBDIRECTORY(googletest)
ADD_EXECUTABLE(test
    src/test.cpp
    src/Goal.cpp
    src/Menu.cpp
    src/Task.cpp
    src/TaskList.cpp
    src/Filter.cpp
    src/InputHelper.cpp
    src/ColorManager.cpp
    src/PrintHelper.cpp
    src/View.cpp
)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
