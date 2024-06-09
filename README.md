per creare un nuovo progetto.

crea il progetto in clion
verifica se la WSL è attiva nella toolchain
setup di CMAKE qui 
    --> File | Settings | Build, Execution, Deployment | CMake
    --> qui inserire la WSL per la buil

ora puoi buildare con il comando:
- cmake --build /mnt/c/Users/p.di.pasquale/Desktop/Learn/challenge/cmake-build-debug-wsl --target challenge
- oppure premento il martello in alto a dx per effettuare la build


ora puoi entrare in cmake-build-debug-wsl
--> cd cmake-build-debug-wsl

e infine puoi runnare l'eseguibile con
--> ./challenge

per fare debug in vscode vai nella command palette e cerca cmake: build

qui istruzioni più dettagliate su come setuppare


Setting up a C++ project can be done in various ways depending on the scale of the project, 
the tools you have, and the environment you're working in. Here's a step-by-step guide to set up a basic C++ project 
using Visual Studio Code (VS Code) and CMake. This setup is ideal for cross-platform development.

### Prerequisites

1. **Install a C++ compiler:**
    - On Windows: Install MinGW or use Microsoft Visual C++.
    - On macOS: Install Xcode Command Line Tools.
    - On Linux: Install `g++` or `clang`.

2. **Install CMake:**
    - Download and install from [cmake.org](https://cmake.org/download/).

3. **Install Visual Studio Code:**
    - Download and install from [code.visualstudio.com](https://code.visualstudio.com/).

4. **Install VS Code Extensions:**
    - C++ (ms-vscode.cpptools)
    - CMake Tools (ms-vscode.cmake-tools)

### Setting Up the Project

1. **Create a Project Directory:**

   ```bash
   mkdir MyCppProject
   cd MyCppProject
   ```

2. **Create the Source and Build Directories:**

   ```bash
   mkdir src
   mkdir build
   ```

3. **Create a Simple C++ Source File:**

   Inside the `src` directory, create a file named `main.cpp` with the following content:

   ```cpp
   #include <iostream>

   int main() {
       std::cout << "Hello, World!" << std::endl;
       return 0;
   }
   ```

4. **Create a CMake Configuration File:**

   In the root of your project directory, create a `CMakeLists.txt` file with the following content:

   ```cmake
   cmake_minimum_required(VERSION 3.10)

   # Set the project name
   project(MyCppProject)

   # Add an executable
   add_executable(MyCppProject src/main.cpp)
   ```

5. **Open the Project in VS Code:**

   Open VS Code and open the `MyCppProject` directory.

6. **Configure VS Code:**

    - Open the Command Palette (Ctrl+Shift+P) and type `CMake: Configure`. Select it.
    - VS Code will prompt you to select a kit (compiler). Choose the appropriate compiler for your system.
    - After the configuration is complete, you should see the generated build files in the `build` directory.

7. **Build the Project:**

    - Open the Command Palette (Ctrl+Shift+P) and type `CMake: Build`. Select it.
    - This will compile the `main.cpp` file and create an executable in the `build` directory.

8. **Run the Executable:**

   You can run the compiled executable from the terminal:

   ```bash
   ./build/MyCppProject
   ```

   Or you can configure a task in VS Code to run it automatically.

### Additional Configuration (Optional)

- **Debugging:**
    - Set up a `launch.json` file for debugging. VS Code will prompt you to configure it when you start a debugging session.

- **Version Control:**
    - Initialize a Git repository in your project directory:
      ```bash
      git init
      ```
    - Create a `.gitignore` file to exclude build files:
      ```
      /build/
      ```

### Example Directory Structure

```
MyCppProject
├── build
├── src
│   └── main.cpp
└── CMakeLists.txt
```

This basic setup will help you start developing in C++ using a modern and flexible approach with VS Code and CMake. For larger projects, you can expand the 
`CMakeLists.txt` to include libraries, tests, and more complex build configurations.