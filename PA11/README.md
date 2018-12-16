# PA11: Mini Golf
Group Members:  
Dongjun Jia  
Ethan Park  
Zachary Young 

The code for this project should be taken from THIS repository. 

For this final project my team, Team Gourand, decided to make a mini golf course. The course currently has 3 holes which increase in difficulty. Lighting options are similar to the previous project in that the game can switch between per vertex and per fragment lighting in real time. Similarly there are also options to increase or decrease the ambient lighting and options to increase or decrease the specular lighting of some objects. A spotlight is also cast on the ball with options to adjust its size and intensity. Q and E are used to rotate the camera and the right and left arror are used to rotate the club. Holding space will pull the club back and releasing space will release the club. When the player finishes a hole a scorecard will appear that shows the holes, par for the holes, the number of shots the player took on each hole (- if zero i.e. no score yet), and the total points that the player has. During this time the player can reset their score. Players can swtich between courses by pressing keys 1-3 with each key corresponding to a hole or can press ~ to go to the next hole. The speed of the rotating fans can be increased using the + and - keys. To run the appliction enter ./PA11

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
This project was built and run using cmake in Linux/Ubuntu. To run the application enter the following in the PA11 directory:

mkdir build  
cd build  
cmake ..  
make  
./PA11 

## Controls
R/L arrow 	- aim club
Spacebar(hold)	- use club

1-3	- press to go to corresponding hole
~	- go to next course
R	- reset score (only available when hole is cleared)

F 	- use per fragment lighting  
V 	- use per vertex lighting  

T 	- increase specular light of the ball  
Y 	- decrese specular light of the ball  
U 	- increase specular light of the windmills  
I 	- decrease specular light of the windmills  
O 	- increase specular light of the club  
P 	- decrease specular light of the club  
g 	- increase specular light of the gates  
h 	- decrease specular light of the gates  

N 	- increase ambient light  
M 	- decrease ambient light  

J 	- increase the size of spotlight  
K 	- decrease the size of spotlight  
Z 	- increase the brightness of spotlight  
X 	- decrease the brightness of spotlight  

'+'	- increase fan speed  
'-'	- decrease fan speed  

# Extra Credit
No extra credit was given for this project.
