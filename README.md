# CSE165Project

Robert Palermo & Shelly Anne Abu
Professor Farias
CSE 165
26 April 2023
CSE 165 Project
Explanation of the chosen app and what it does:
Wanting to make something fun and exciting, and creating a tribute to our childhood games, 
we thought that having a player character was a must so games like Tetris would be out of the question. 
Next, we initially wanted to go for Super Mario Bros, but that felt limited since Mario will be the main character
of the game and we wanted to make a game that can act as a foundation for us to be creative with it, like having custom characters,
enemies, and backgrounds. So we went with a more open-ended game, a vertical side-scroller.
This game features a top-down view of the player's spaceship flying through space and defeating alien ships as they come.
The player is able to move from left to right by pressing the left and right arrows on the keyboard.
By pressing the spacebar button the player’s spaceship can shoot a laser that if it connects with an enemy ship will destroy both it and the enemy, 
if the laser misses it will simply delete itself as it goes past the screen. 
The anime alien ships are generated in random places and in set intervals just above the game screen and gradually move down toward the player's direction. 
There is also background music for the game and a sound effect of the player’s laser as it is shot from the player’s spaceship. Lastly, the game also features 
a game menu screen before the actual game begins this screen is there so the game doesn’t automatically start as soon as the application opens and allows 
the player to begin the game whenever they want by clicking on the play button.
Significant feature(s) each member of the group was responsible for:
The workload was divided with Robert Palermo implementing the main game logic and Shelly Anne Abu implementing the images of the various game items 
and creating the game menu.
How you used objected-oriented programming:
The framework that we used to create the game is Qt and we used various of its libraries to help make the game, such as QMultimedia to play the 
sounds and QGraphicsScene to render the objects. Also, we have QGraphicsScene utilize OpenGL with its Qt widget, QOpenGLWidget, for our viewport. 
As for object-oriented concepts, we use inheritance a lot throughout our code such as for our Game class inheriting from the QGraphicsView class. 
With our code being divided between header and implementation files, we use constructors to hold the functions of our code. 
We also use polymorphism for example our Enemy and Bullet classes both have the same base class, QGraphicsPixmapItem, 
but they do different things the move() function in the Enemy class moves the enemy down while in the Bullet class, it moves the bullet up.
