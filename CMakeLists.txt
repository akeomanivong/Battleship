cmake_minimum_required(VERSION 3.12)
project(KeomanivongHW4)

set(CMAKE_CXX_STANDARD 14)

add_executable(KeomanivongHW4 main.cpp Ship.cpp Ship.h Battleship.h Submarine.h Destroyer.h Cruiser.h Carrier.h Grid.cpp Grid.h functions.cpp functions.h)