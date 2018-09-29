# PA4: Blender and Model Loading

This project involved creating a model in blender and exporting the model to an obj file and adding an object loading component to object.cpp to load the object using glm. This was done by adding a seperate function to object.cpp to handle object loading. The function takes in a file name to an obj file and sets the models vertices and indices based on the data in the file. When reading in indices the function takes into account whether the file has either uv vertices and normal vertices, both, or neither. This is done with two boolean variables "hasUV" and "hasNormal" which are set when a file has uv and normal vertices respectively. obj files are located in the "objects" folder in the PA4 directory. I was able to add random color to the model using the <cstdlib> and <ctime> libraries. This is done when seting the vertices the color for each vertex is set by seting each colors vectors to a random float value ranging from 1 to 0. I added rotation on the x-axis for the model so that its dimensions could better represented. For this project I also added command line arguments so that the user does not have to change the code to read a different obj file. To run the appliction enter ./PA4 <filename>. For example to load board.obj enter: ./PA4 ../objects/board.obj

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
This project was built and run using a makefile in Linux/Ubuntu. To run the application using the board obj file, enter the following in the PA4 directory:

mkdir build  
cd build  
cp ../makefile .  
make  
./PA4 ../objects/board.obj 

For any other obj file simply add the file to the objects folder and change board.obj to the disired file.

## Controls
No controls are used for this project.

# Extra Credit
I was able to add color to the model in Blender but was unable to add the color to the model using the mtl file. Color was added to the model, however it was not done using the mtl file.
