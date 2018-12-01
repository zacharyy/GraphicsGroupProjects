# PA9: Lighting
Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 

This project builds off of the previous project, PA8, and adds lighting to the simulation. This project as a result also fixes many issues that PA8 had such as the cube not being a dynamic object, the ball not rolling properly, and the colliders for objects being inaccurate. Features added to PA9 were per vertex and per fragement lighting with the option to swtich between them in real time. A spotlight was also added that follows the sphere and has controls that can change its size and brightness. It should be noted that for per vertex lighting, the bottom of the board only consists of 2 triange meshes, meaning that spotlight lighting for the board only occurs at the board's corners when using per vertex lighting. Finally, controls to adjust the ambient light as well as the specular light of each individual object on the board were added to the simulation. To run the appliction enter ./PA9

# Dependencies, Building, and Running

## Dependency Instructions
For operating systems to run this project, installation of these six programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), [SDL2](https://wiki.libsdl.org/Tutorials), [Assimp](http://assimp.sourceforge.net/main_downloads.html), [ImageMagick](https://sourceforge.net/projects/imagemagick/), and [Bullet](https://pybullet.org/wordpress/).

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
This project was built and run using cmake in Linux/Ubuntu. To run the application enter the following in the PA9 directory:

mkdir build  
cd build  
cmake ..  
make  
./PA9 

## Controls
W	- move cube up  
A	- move cube left  
S	- move cube down  
D	- move cube right  

F 	- use per fragment lighting  
V 	- use per vertex lighting  

T 	- increase specular light of the ball  
Y 	- decrese specular light of the ball  
U 	- increase specular light of the cube  
I 	- decrease specular light of the cube  
O 	- increase specular light of the cylinder  
P 	- decrease specular light of the cylinder  

N 	- increase ambient light  
M 	- decrease ambient light  

J 	- increase the size of spotlight  
K 	- decrease the size of spotlight  
Z 	- increase the brightness of spotlight  
X 	- decrease the brightness of spotlight  

# Extra Credit
No extra credit was given for this project.
