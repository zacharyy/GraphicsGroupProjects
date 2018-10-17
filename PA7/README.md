# PA7: Solar System

Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 

This project builds off of all previous projects from this course as it involves creating a simulation of the Solar System using affine trasformations to manipulate planets and moons, model loading to load in planets and moons, texture loading to add detail to planets and moons, and user interaction that can change aspects of the simulation. Data such as orbit velocity, rotation speed, diameter, and other data necessary to simulate the movement of planets and moons are stored in a new class called planet_object. planet_object is a child class of the object class used in previous projects but contains additional functions such as Update() which overrides the Update() function from the object class and GetPlanetSize() which returns the size of the planet when called. It also contains data for moons as well as a seperate update function for moons. To run the appliction enter ./PA7

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
./PA7 

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
"+"	- speed up simulation  
"-"	- slow down simulation  
p	- change scale of Solar System  

# Extra Credit
Live adjustment of simulation speed was implemented in this project, the =/+ key will increase the simulation speed by a factor of 2 while the -/_ key will decrease the speed by a factor of 2. The option to go from actual data to scaled view and vise versa was also added and can be done by pressing p. Rings were also added on Uranus and Neptune.
