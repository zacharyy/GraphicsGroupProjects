# PA8: Bullet
Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 

This project involves using bullet to apply physics to objects. To achieve this, this project involves loading a simple board that contains a cylinder, cube, and sphere. The board and cylindar are statuc objects while the cube and sphere are dynamic objects. Use of the bullet physics are demonstated by allowing the user to move the cube and interact with the sphere. Users can use the the cube to push the sphere into other objects such as the cylinder and board walls which the sphere will bounce off of. This project also uses knowlege learned from previous projects such as texture and model loading. To run the appliction enter ./PA8

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
This project was built and run using cmake in Linux/Ubuntu. To run the application enter the following in the PA8 directory:

mkdir build  
cd build  
cmake ..  
make  
./PA8 

## Controls
W	- move cube up
A	- move cube left
S	- move cube down
D	- move cube right

# Extra Credit
Triangle meshes for the board, cylinder, and cube are loaded into Bullet instead of primitive objects.
