# PA1: Spinning Cube

This project involved taking the given code which caused the cube to spin and modify it so that the cube rotates around the y-axis. This is done by multiplying the tranlation matrix (that sets the cube some distance away from the y-axis) by and the rotation matrix (set to make the cube spin on the y-axis) which causes the cube to rotate on the y-axis. To make the cube spin while rotating simple multiply the result of the previous calculation by the rotation matrix again. The project also required that the code be modified to read in the vertex and fragment shaders from seperate files. This is done by creating a seperate shaders folder in the PA1 directory. The shaders folder has text files that contain the information for the vertex and fragment shaders. To read in the shaders, the AddShader function in shader source file is modified to read in the file information of each shader into strings which are then copied over.

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
This project was built and run using a makefile in Linux/Ubuntu. To run the application, enter the following in the PA1 directory:

mkdir build  
cd build  
cp ../makefile .  
make  
./PA1 

## Controls
No controls are used for this project.
