# PA10: Pinball
Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 

This project builds off of previous projects and simulates a pinball table. Each game will have 3 balls, after which the player has the option of reseting the game. For each bumper the pinball hits, the player recieves 100 points. The power of the plugner changes depending on how far it is pulled back. The game also keeps track of the top 10 scores, with the option for the player to enter a new score into the database. The simulation has both per vertex and per fragment lighting with the option to swtich between them in real time. A spotlight was also added that follows the pinball and has controls that can change its size and brightness. Controls to adjust the ambient light as well as the specular light of the pinball, bumpers, and the flippers were added to the simulation. Conntrols to change the camera to a top down, front, and back view were added. Finally, spotlights light the cylinders/bumpers when the ball collides with them. To run the appliction go to the PA10 directory, follow the build instructions, and enter ./PA10

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
This project was built and run using cmake in Linux/Ubuntu. To run the application enter the following in the PA10 directory:

mkdir build  
cd build  
cmake ..  
make  
./PA10 

## Controls
Space (hold)	- use plunger  

R-Shift	- use right flipper  
L-Shift	- use left flipper  

R	- reset game

F 	- use per fragment lighting  
V 	- use per vertex lighting  

T 	- increase specular light of the ball  
Y 	- decrease specular light of the ball  
U 	- increase specular light of the flippers  
I 	- decrease specular light of the flippers  
O 	- increase specular light of the bumpers  
P 	- decrease specular light of the bumpers  

N 	- increase ambient light  
M 	- decrease ambient light  

J 	- increase the size of spotlight  
K 	- decrease the size of spotlight  
Z 	- increase the brightness of spotlight  
X 	- decrease the brightness of spotlight  

,	- top down view  
.	- front view  
/	- back view  

WASD	- move camera  
Q	- zoom out camera  
E	- zoom in camera  

# Extra Credit
Plunger intensity changes depending on how far back it is pulled. A spotlight follows the ball with the ability to change its radius and intensity. The game keeps track of the top 10 scores with the option for the player to enter a new score into the database if it is higher than any of the 10 scores already in it. Spotlights light the cylinders/bumpers when the ball collides with them. 
