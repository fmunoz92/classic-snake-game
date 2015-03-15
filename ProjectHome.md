Classic snake game written in C++ with SFML.

Dependences: SFML 1.6

-How to install SFML?

download SFML 1.6 http://www.sfml-dev.org/download/sfml/1.6

$ cd SFML-1.6/
$ sudo make install

Install dependences on ubuntu:

$ sudo apt-get build-dep libsfml

more information in http://www.sfml-dev.org/tutorials/1.6/start-linux.php

- How to compile snake-game?

$ g++ -c -Wall -Wextra -ansi -pedantic Snake.cpp

$ g++ -o Snake Snake.o -lsfml-graphics -lsfml-window -lsfml-system

- How to run?:

$ ./Snake