
# So Long

So Long is a simple 2D game developed in C using the MinilibX library. The game involves navigating a character through a maze to collect items and reach an exit, showcasing fundamental game development concepts.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The So Long project is a small 2D game where the player controls a character to collect items and reach the exit of a maze. The project demonstrates basic game development techniques, including handling user input, rendering graphics, and implementing game logic.

## Features

- 2D maze navigation.
- Item collection.
- Exit to complete the level.
- Simple and intuitive controls.

## Requirements

To build and run So Long, you need:
- A UNIX-like operating system (Linux, macOS, etc.)
- `gcc` compiler
- `make` utility
- MinilibX library

## Installation

Clone the repository to your local machine:

```sh
git clone https://github.com/ddcsoftdev/so-long.git
cd so-long
```

Build the project using `make`:

```sh
make
```

## Usage

### Running the Game

To run the game, execute the following command:

```sh
./so_long <map_file.ber>
```

### Example

Here is an example command to run the game with a sample map file:

```sh
./so_long maps/sample.ber
```

### Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **ESC**: Exit the game

## Map Files

Map files are used to define the layout of the game maze. The map should be a `.ber` file containing the maze structure using specific characters:
- `1`: Wall
- `0`: Empty space
- `P`: Player start position
- `C`: Collectible item
- `E`: Exit

### Example Map File

```
1111111
1P0C0E1
1000001
1111111
```

## Contributing

Contributions are welcome! Please fork the repository and open a pull request to add new features, fix bugs, or improve documentation.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
