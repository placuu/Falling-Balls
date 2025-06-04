# Falling-Balls
A simple C++/SFML project. First time coding using SFML lib. 

## Dependencies
- [SFML 3.0](https://www.sfml-dev.org/)

## How to Run
- Visit the official SFML website: https://www.sfml-dev.org/
- Download the latest version (3.0)
- Extract the .zip file to a directory, for example: C:\\SFML
- In Visual Studio, right-click your project in Solution Explorer -> Properties

A. Under Configuration Properties -> VC++ Directories:
- Include Directories -> Add:
  C:\\SFML\\include
- Library Directories -> Add:
  C:\\SFML\\lib

B. Under Configuration Properties -> Linker -> Input:
- Additional Dependencies -> Add the following (for Debug build):
  sfml-graphics-d.lib
  sfml-window-d.lib
  sfml-system-d.lib

- For Release build, use:
  sfml-graphics.lib
  sfml-window.lib
  sfml-system.lib

- Go to C:\\SFML\\bin
- Copy all DLL files
- Paste them into your project's output folder next to the .exe file

## How to Build
1. Open FallingBalls.sln in Visual Studio.
2. Select Release x64 build configuration
3. Click Build -> Build Solution
4. If everything is set up correctly, the project will compile without errors.

## In Case of Errors
If you encounter errors during compiling or need more information about setting up the library,
please refer to the official website:
https://www.sfml-dev.org/tutorials/3.0/getting-started/visual-studio/
Everything is clearly explained there.

## Project Structure
- Source code: FallingBalls.cpp
- Solution: FallingBalls.sln

  
