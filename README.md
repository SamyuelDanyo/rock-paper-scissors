# Rock-Paper-Scissors game for two.
![Rock-Paper-Scissors Thumbnail](/res/Rock-paper-scissors.svg)  
Program that plays Rock-Paper-Scissors between the computer and a real player. You can play the game n times before the program exits.

## Introduction
Rock-Paper-Scissors is a game for two players. Each player simultaneously opens their hand to
display a symbol:

     • Fist equals rock.  
     • Open hand equals paper.  
     • Showing the index and middle finger equals scissors.

The winner is determined by the following schema:

     • paper beats (wraps) rock.  
     • rock beats (blunts) scissors.  
     • scissors beats (cuts) paper.

## Build

__Example Build Command:__  
	`<g++ -I "E:\\Code\\Projects\\rock-paper-scissors" -g "E:\\Code\\Projects\\rock-paper-scissors\\src\\include\\*.cc" ".\*.cc" -o .\rps.exe>`

__[Example Build Config](https://github.com/SamyuelDanyo/rock-paper-scissors/docs/tasks.json)__

__Make sure to:__  
	1. Include the project root directory to include path via the "-I" compiler option. Example:  
     		`<-I "E:\\Code\\Projects\\rock-paper-scissors">`  
	2. Include all project source files via the "-g" compiler option. Example:  
		`<-g "E:\\Code\\Projects\\rock-paper-scissors\\src\\include\\*.cc">`  
	3. Include executable wrappers via the "-g" compiler option. Example:  
		`<-g "${fileDirname}\\*.cc">`  
	4. Recommended: Build while in executable directory. Example: <root/src> for the game and <root/test/manual/player> for manual player tests.

## Design

The Game and Round classes are templated to allow easy game-making for humans or computers.
The project supports extensibility through OOP and templates - in order to facilitate readability template classes' definitions and implementations are separated in a <.h> and <.cc> files.  
__If new <Player> types are added - make sure to add explicit instantiations in the <.cc> file!__

The process of picking a symbol is intentionally concurrent and unsynchronized since that is the closest behavior to what happens in-person. Sometimes one of the players is slightly ahead, sometimes the other, but they are never perfectly synchronized in neither saying rock-paper-scissors nor in showing their symbols.

For choosing symbols PlayerComputer uses a random number generator, which is seeded via <std::chrono::high_resolution_clock>. That was picked over <std::random_device()>, since the latter is implemented as PRNG and hence that leads to the computer always following the same sequence.

### Style

The project follows __[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#File_Names)__
