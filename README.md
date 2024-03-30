# So_long_42
This is the first project from 42 curriculum with a graphical environment. This is a little game of an Astronaut who needs to collect all stars and come back home without falling into a black hole.

# How To Play

1) Clone the repository via CLI:
	git clone git@github.com:giovannahelena/So_long_42.git

2) Build the MLX:
	cd MLX42
	cmake -B build
	cmake --build build -j4

3) Go back to the root repository:
	cd ..

4) Open the Makefile and remove the first '#' characther of line 20 if you are using Linux or line 23 if you are using MacOs.
	If you are using Windows or having compilation or building problems with MLX, see the MLX42 documentation
	(https://github.com/codam-coding-college/MLX42).

5) Run the game with:
	make play

6) Or compile the game:
	make

7) and run with a map of your choice (maps found on ./maps):
	./so_long ./maps/map6.ber

8) Use your keybord to move the astronaut (A - left, D - right, W - up, S - down or the arrows);

9) Esc will close the game window.

<img src="./.readme_utils/prnt1.png">
<img src="./.readme_utils/prnt2.png">
<img src="./.readme_utils/prnt3.png">