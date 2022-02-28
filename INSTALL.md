Installation Instructions
=========================

Install Prerequisites
---------------------

In order to build from the source code, you will need to install CMake and the ncurses development files.

### CMake

1. Go to [the CMake download page](https://cmake.org/download/)
2. Scroll down to the ["Latest Release" section](https://cmake.org/download/#latest)
3. Choose the correct entry from the "Binary distributions" subheading and for your operating system. It is recommended to get the installer executable (`.msi`, `.dmg`, or `.sh`) instead of the archive file (`.tar.gz`)
4. Double click the file and follow the instructions to complete the installation.

### ncurses

See the instructions under `ncurses/README.md`


Main Program
--------------------

### Compile

```bash
cmake .
make task-scheduler
```

### Run

#### macOS and Linux

```bash
./task-scheduler
```

#### Windows

Double click the `task-scheduler.exe` file
