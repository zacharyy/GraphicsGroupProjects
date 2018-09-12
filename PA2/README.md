# PA2: Interaction: Menus, Keyboard, and Mouse

This project involved taking the code from project 1 and modifying it react to user input. Specifically, the cube should reverse spin and rotation as well as stop spin and rotation using mouse and keyboard input. This is achieved by modifying the engine, graphics, and object files. Most of the changes are made in engine.cpp in the function Keyboard() renamed User_input as the function now take mouse and keyboard input. 4 boolean variables, spin_reverse, spin_stop, revolution_reverse, and revolution_stop were made to keep track of the spin and revolution of the cube and are set in User_input according to user input. The headers of all mentioned files and the update functions in graphics.cpp and object.cpp were updated to reflect these changes. Specifically, the in the update function of object.cpp, the function takes in the four mentioned boolean variables. If spin spin_stop or revolution_stop are true, the angles on the rotate matrices do not increase or decrease. If they are true, the angles on the rotate matrices either increase or decrease if spin_reverse and revolution_reverse are false or true respectively. It should be noted that I also updated shaders.cpp to eliminate duplicate code in the update function. This was done by creating a seperate function that copies the shader text files into strings.

# Dependencies, Building, and Running

## Dependency Instructions
For both of the operating systems to run this project installation of these three programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), and [SDL2](https://wiki.libsdl.org/Tutorials).

This project uses OpenGL 3.3. Some computers, such as virtual machines in the ECC, can not run this version. In in order to run OpenGL 2.7 follow the instructions at [Using OpenGL 2.7](https://github.com/HPC-Vis/computer-graphics/wiki/Using-OpenGL-2.7)

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```

### Mac OSX
Installation of brew is suggested to easily install the libs. Ensure that the latest version of the Developer Tools is installed.
```bash
brew install glew glm sdl2
```

## Building and Running
This project was built and run using a makefile in Linux/Ubuntu. To run the application, enter the following in the PA2 directory:

mkdir build  
cd build  
cp ../makefile .  
make  
./PA2

## Controls

1 - reverses cube spin
2 - toggles cube spin
lmb - reverses revolution
rmb - toggles revolution

# Extra Credit
The extra credit was attempted using the imgui library, however I was unable to compile the files. Specifically, imgui_impl_opengl3.cpp gave me trouble as giving me the error: GL/gl3w.h: No such file or directory.
