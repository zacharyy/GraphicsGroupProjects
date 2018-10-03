# PA5: Assimp and Model Loading

Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 

This project was very similar to the previous project, but involved using Assimp to load in models. As a result, a similar object loading function is used in object.cpp. It is modified to use Assimp to read information from a file and create a "scene" object from it. Information from the scene such as vertices and faces are then extracted to make the model. The current program cannot load models with sub-meshes. We added random color to each model using the <cstdlib> and <ctime> libraries. This is done when adding the vertices as the color for each vertex is set by setting each of the colors vectors to a random float value ranging from 1 to 0. Rotation of the model on the x-axis was also added so its dimensions could better represented. Command line arguments are used to read in the name of files that contain models. These files are located in the objects directory of PA5. To run the appliction enter ./PA5 <filename>. For example, to load box.obj enter: ./PA5 ../objects/box.obj 

# Dependencies, Building, and Running

## Dependency Instructions
For operating systems to run this project, installation of these four programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), [SDL2](https://wiki.libsdl.org/Tutorials), and [Assimp](http://assimp.sourceforge.net/main_downloads.html).

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
This project was built and run using a makefile in Linux/Ubuntu. To run the application using the box obj file, enter the following in the PA5 directory:

mkdir build  
cd build  
cp ../makefile .  
make  
./PA5 ../objects/box.obj 

For any other obj file simply add the file to the objects folder and change box.obj to the desired file.

## Controls
No controls are used for this project.

# Extra Credit
Adding color using an mtl file was attempted but not completed. As a result, the code pertaining to this attempt has been commented out. Colors were instead applied to the model using random variables. 
