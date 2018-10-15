# PA7: Solar System

Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 



# Dependencies, Building, and Running

## Dependency Instructions
For operating systems to run this project, installation of these five programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), [SDL2](https://wiki.libsdl.org/Tutorials), [Assimp](http://assimp.sourceforge.net/main_downloads.html), and [ImageMagick](https://sourceforge.net/projects/imagemagick/).

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
This project was built and run using a cmake file in Linux/Ubuntu. To run the application, enter the following in the PA7 directory:

mkdir build  
cd build  
cmake ..  
make  
./PA7 ../objects/sphere.obj 

## Controls
N	- normal viewing mode  
T	- top down view mode  
WASD	- move camera (top down view mode only)  
e	- zoom in camera (top down view mode only)  
q	- zoom out camera (top down view mode only)  
1	- view Mercury  
2	- view Venus  
3	- view Earth  
4	- view Mars  
5	- view Jupiter  
6	- view Saturn  
7	- view Uranus  
8	- view Neptune  
9	- view Pluto 

# Extra Credit
No extra credit was given for this project.
