
# Biquadris (Multi-player Tetris)
## Introduction
This project is a C++ implementation of a Tetris-like game featuring both text-based and graphical interfaces. The game utilizes object-oriented design principles, including the Observer pattern, to separate game logic from presentation. It emphasizes low coupling and high cohesion to ensure maintainability, scalability, and resilience to change.

## Features
Text-Based Interface: Play the game using a terminal interface, suitable for environments without graphical support.
Graphical Interface: Enjoy a graphical version of the game using the X11 library for rendering.
Observer Pattern Implementation: The game uses the Observer pattern to decouple the game logic from the display logic.
Extendable Design: The architecture supports easy addition of new features, such as special blocks, new levels, and effects.
Configurable Levels: Levels can be configured to introduce new block types or behaviors.
Blinding Effect: Implements a blinding effect where certain cells become hidden during gameplay.
Timed Blocks: Introduces blocks that disappear if not cleared within a certain number of moves (optional feature).
Customizable Commands: Supports renaming commands and creating macros for complex actions.

## Design Overview
Object-Oriented Principles
Low Coupling: Classes interact through well-defined interfaces, minimizing dependencies between modules.

High Cohesion: Each class has a single, focused responsibility, improving maintainability and readability.
## Key Classes
Game: Manages the overall game flow, player turns, and game state.
Player: Represents a player in the game, holding their board and score.
Board: Manages the state of the game board, including cell states and block placements.
Cell: Represents an individual cell on the board, holding its type and state.
Observer (Abstract Class): Defines the interface for observers that update the display.
TextObserver: Implements the Observer interface for text-based display.
GraphicsObserver: Implements the Observer interface for graphical display using X11.
Block and TimedBlock: Represents game blocks, with TimedBlock introducing disappearing behavior.

## Design Patterns
Observer Pattern: Decouples game logic from the display, allowing multiple observers to respond to game state changes.
Strategy Pattern: Can be used for level behaviors and block generation strategies.
Decorator Pattern: Applies effects like blinding or heavy blocks in a modular way.
Command Pattern: Manages user commands, allowing for dynamic command addition and macros.

## Requirements
C++ Compiler: Compatible with C++11 standard or higher.
X11 Library: Required for the graphical interface.
Linux: Typically comes pre-installed.
macOS: Install XQuartz.
Windows: Use an X11 server like Xming and compile with Cygwin or WSL.

## Installation
Clone the Repository:

```
git clone https://github.com/yourusername/tetris-game.git
cd tetris-game
Install Dependencies:
```

### Linux:

```
sudo apt-get install libx11-dev
```

### macOS:

Install XQuartz from https://www.xquartz.org/.

### Windows:

Install an X11 server and use WSL or Cygwin for compilation.

## Compilation Instructions
Compile the game using existing Makefile.

```
make
```

## Run the game
```
./biquadris [options]
```

## Available Options
-text: Run the game in text-only mode.
-seed [number]: Set the random seed for block generation.
-startlevel [number]: Start the game at a specific level.
-scriptfile1 [file]: Specify a script file for player one.
-scriptfile2 [file]: Specify a script file for player two.

## Controls
### Movement:
left: Move the block left.
right: Move the block right.
down: Move the block down.

### Rotation:
clockwise or cw: Rotate the block clockwise.
counterclockwise or ccw: Rotate the block counterclockwise.

### Dropping:
drop: Drop the block immediately.

### Level Control:
levelup: Increase the level.
leveldown: Decrease the level.

### Special Commands:
rename [old] [new]: Rename an existing command.
macro [name] [command sequence]: Define a macro command.

### Gameplay
- The game starts with an empty board and a sequence of blocks.
- Players take turns moving and rotating blocks to fill rows.
- Completing a full row clears it from the board.
- The game introduces new block types and effects at higher levels.
- The game ends when a block cannot be placed on the board.


## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments
X11 Library: Used for rendering the graphical interface.

## Contact
For questions or support, contact the project maintainer z253chen@uwaterloo.ca or w3zou@uwaterloo.ca.

## Additional Notes
### Ensuring Low Coupling and High Cohesion
- Modular Design: The project emphasizes modularity, making it easier to maintain and extend.
- Design Patterns: The use of design patterns like Observer, Strategy, Decorator, and Command contributes to a flexible and scalable architecture.
- Resilience to Change: The design allows for new features to be added with minimal impact on existing code.
- 
## Possible Extensions
- Networked Multiplayer: Implement a NetworkObserver to allow remote players to join.
- AI Opponents: Introduce computer-controlled players for single-player modes.
- High Score Persistence: Save high scores to a file or database for persistence across sessions.
- Enhanced Graphics: Use advanced graphics libraries for improved visuals.
