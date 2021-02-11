#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "src/Engine/Engine.h"


/*
2D tank game with two players- 
One person controls with (wasd), the other (ijkl). We need to be able to implement 
a rotation feature where the w and s keys move the tank forward and backwards, and a and d rotate the tank
left and right, not forgetting that i and k move forward/backwards j and l left/right as well.

So far, we only have the ability to control the player tank, and shoot with spacebar- if a bullet hits the 'enemy' tank, it disappears.
We need to be able to control both tanks and have collision for both of them; with bullets and the borders of the map (there will also
be obstacles in the map such as walls or boxes). One of my partners already designed the map, and the other has a sprite
being made for the tank.


Controls 

Player 1
w - forward
s - backward
a - left
d - right
spacebar - shoot 

Player 2
i - forward
s - backward
j - left
d - right
(shoot)

Installing SFML: https://www.sfml-dev.org/download/sfml/2.5.1/ (Use 32 Bit, works on 2017 VS)

Setting up directories and dll files: https://www.youtube.com/watch?v=YfMQyOw1zik

Using SFML: https://www.sfml-dev.org/tutorials/2.5/graphics-transform.php
*/

int main() 
{
  Engine& gameEngine = Engine::get();
  gameEngine.initialize();

  gameEngine.gameLoop();

  gameEngine.shutdown();
 
  return 0;

}