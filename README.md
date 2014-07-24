stigame
=======
StiGame is a C++ 2D game library using SDL2 in the background.
You can fork this repository if you want to bootstrap your new game with this library and modify the library for the need of your game
or you can use the pre-compiled binary and use this library for your project.

### What is included ?
At the moment, these features are already implemented into StiGame.

- Basic State
  - BaseGameState
  - GuiState
- Viewport
  - Window Size
  - Window Mode
  - FPS Handling
- Action Binding
  - Key Action
  - Mouse Action
  - Binding Configuration File
- User Interface
  - Gui Elements
    - Button
	- Label
	- Combo Box
	- Selection List
	- Tab Panel
	- etc...
- Game Sprite
  - Directional Sprite
  - General Sprite
  - Sprite Library for texture management
  
### Purpose
This library will be used for StiCode game development and this library will be development for the need of StiCode Games.
But we will try to keep the library "general", so no game specific thing will be implemented in this library.

### Compile and Test

#### Windows

At the moment the only test is to run the Sample coming with the library. This sample only show gui elements at the moment.

We currently compile StiGame using mingw32-TDM-GCC-4.8.1 (Coming with Code::Blocks).

Windows 7 is the only tested Operating System at the moment.

You need to first retrieve the extern files like SDL2 header and libraries.

A Python script is included for this.

After you can compile using Code::Blocks IDE.

#### Linux

Linux will be supported in an early future

### TO DO

- Gui Test Project, to test all Gui Element

- Viewport
  -	Save resolution information, to persist configuration
 
- Controller Support
  - Map Controller and handle event
  - Persitant configuration of the default controller

and things that don't come to my mind at the moment...


