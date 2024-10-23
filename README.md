# Cub3d
## "My first RayCaster with miniLibX"

```
This project is inspired by the world-famous Wolfenstein 3D game, which
was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
make a dynamic view inside a maze, in which you’ll have to find your way.
```
~ The subject for this project

Cub3d is a raycaster: a program that displays a 3D environment on the screen using the raycasting method (see here: https://en.wikipedia.org/wiki/Raycasting)

Simply put, it casts rays of "light" from the camera in the direction in which the "player" is looking, and determines what to display (and how to do so) depending on what and when each ray collides with an obstacle.

## Dependencies
This program makes use of 42 School's graphical library, the miniLibX, which will be cloned in the project at compile time. 
For more details, see the miniLibX's github repository: https://github.com/42Paris/minilibx-linux

## Usage
Compile with ```make```

Delete object files with ```make clean```

Delete all files generated during compilation with ```make fclean```

Cub3d takes a path to a map file as an argument.
Maps must follow the following restrictions:
- Maps must contain paths to textures for each wall.
- Maps must contain RGB codes for the ceiling and floor.
- Maps must contain a starting position.
- Maps are entirely closed off.
- Maps are made of 1's for walls, and 0's for empty tiles.

Exemples of valid and invalid maps are included in the project directory.


## Known Issues
- It is possible to crash the program by going through a wall if the player accumulates enough speed.
\
\
\
\
\
Cub3d is written in accordance with 42 School's coding norm, see here:
https://github.com/42School/norminette

