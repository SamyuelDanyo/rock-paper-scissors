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

__Example Build Command:__ <g++ -I "E:\\Code\\Projects\\rock-paper-scissors" -g "E:\\Code\\Projects\\rock-paper-scissors\\src\\include\\*.cc" ".\*.cc" -o .\rps.exe>

__[Example Build Config](https://github.com/SamyuelDanyo/rock-paper-scissors/docs/tasks.json)__

__Make sure to:__  
     1. Include the project root directory to include path via the "-I" compiler option. Example: <-I "E:\\Code\\Projects\\rock-paper-scissors">  
	2. Include all project source files via the "-g" compiler option. Example: <-g "E:\\Code\\Projects\\rock-paper-scissors\\src\\include\\*.cc">  
     3. Include executable wrappers via the "-g" compiler option. Example: <-g "${fileDirname}\\*.cc">  
     4. Reccommended: Build while in executable directory. Example: <root/src> for the game and <root/test/manual/player> for manual player tests.
