# So_long

<img width="665" alt="So_long" src="https://github.com/user-attachments/assets/80ed3aec-0eac-4171-b20e-14f41790333d">

## Description

**So Long** is a small 2D game project designed to help you learn and implement basic graphical programming concepts using the MiniLibX library. The goal is to create a simple game where the player must collect items on a map and reach an exit. The project focuses on window management, event handling, and basic game mechanics.

## Preview

![](https://github.com/vicire1/So_long/blob/master/so_long.gif)

## Project Objectives

- **Graphics Programming**: Learn how to work with textures, sprites, and handle basic 2D graphics.
- **Event Handling**: Manage user inputs such as keyboard and mouse events.
- **Game Development**: Understand the fundamentals of creating a simple 2D game.

## Requirements

- Implement a game where the player must collect all collectibles on a map and reach the exit.
- The game must use the MiniLibX library for window management and rendering.
- The project must be written in C and adhere to the school's coding standards.
- Ensure thorough error handling, avoiding crashes due to segmentation faults, bus errors, double free, etc.
- The program must not have memory leaks.

## Compilation

To compile the project, use the provided `Makefile` with the following rules:

- `make` or `make all`: Compile the `so_long` program.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the executable.
- `make re`: Recompile the project.

```bash
$ make
```

## Usage
To run the `**so_long**` game, pass a map file (with the `**.ber**` extension) as an argument:

```bash
$ ./so_long maps/map.ber
```

### Game Mechanics
The player controls the main character using the **W**, **A**, **S**, and **D** keys.
The player's objective is to collect all collectibles (`C`) on the map and reach the exit (`E`).
The player can move up, down, left, and right but cannot move through walls (`1`).

## Map Format

The map file should consist of the following characters:
- `0`: Empty space
- `1`: Wall
- `C`: Collectible
- `E`: Exit
- `P`: Player's starting position
- `X`: Ennemy
  
The map must be rectangular, enclosed by walls, and contain at least one exit, one collectible, and one starting position.

### Example Map

Here is a simple valid map:

```
1111111111111
10010000X00C1
1000011111X01
1P0X11E000001
1111111111111
```
