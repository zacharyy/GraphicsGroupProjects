# PA5: Assimp and Model Loading

Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 

This project builds of the previous Assimp model loading project with the loader now being able to load textures onto a model. This was done using ImageMagick, specifically magick++ which allows us to read in textures. This project also fixes problems with the previous project, namely loading for multiple mesh models. In order to achieve this, a new mesh class was added to assist in multiple mesh loading for this project. Because of this most of the set up for the models (such as model loading, texture loading, drawing) are now moved to the function of this class. The model loader can currently load multiple textures onto a single model, but the textures must be hard coded in object.cpp to achieve this. Rotation of the model on the x-axis was also added so its dimensions could better represented. Command line arguments are used to read in the name of files that contain models. These files are located in the objects directory of PA6. To run the appliction enter ./PA6 <filename>. For example, to load buddha.obj enter: ./PA6 ../objects/buddha.obj 

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
This project was built and run using a makefile in Linux/Ubuntu. As of publishing this README, ImageMagick has not been installed on machines in the ECC, and as a result we have not been able to test the project in the ECC. To run the application using the buddha file, enter the following in the PA6 directory:

mkdir build  
cd build  
cmake ..  
make  
./PA6 ../objects/buddha.obj 

For any other model file simply add the file to the objects folder and change buddha.obj to the desired file. As mention before, textures are hard coded an must be changed in object.cpp

## Controls
No controls are used for this project.

# Extra Credit
No extra credit was given for this project.
