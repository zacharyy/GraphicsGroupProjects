# PA3: PA3 - Moons

This project involved building off code from project 2 and modifying it to have a smaller cube orbit around the big cube. This is done by creating a public object pointer, *moon, in the object class which will act as a child to the planet. A seprate UpdateMoon function is also added which will manipulate the moon. It takes in all the variables of the normal update function but also takes in the parent's model so it knows its location. This is used in the translate function in which the location of the parent model is used as the origin for the moon. Other components such as the graphics files had to be slightly modified to account for the changes in the object files. Most of the changes occured in the update function of graphics.cpp which now calls the update moon function which is passed in the parent model and the control variables. The render function was also changed to render the moon. This project also involved updating the planet controls to take in user input from the arrow keys. This was done in the same manner as the last project and only involved a few modfications to the PA2 code. Additionally, I added the same control functionality to the moon and modified my object update function to use sine and cosine instead of matrix multiplcation.

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
This project was built and run using a makefile in Linux/Ubuntu. To run the application, enter the following in the PA3 directory:

mkdir build  
cd build  
cp ../makefile .  
make  
./PA3

## Controls

### Planet Controls
right arrow or 1 - reverses spin  
left arrow or 2 - toggles spin  
up arrow or lmb - reverses revolution  
down arror or rmb - toggles revolution  

### Moon Controls
3 - reverses spin  
4 - toggles spin  
5 - reverses revolution  
6 - toggles revolution  

# Extra Credit
The extra credit was not attempted.
