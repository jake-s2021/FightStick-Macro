# FightStick-Macro
Logic for a Raspberry Pi Zero W to allow button Macros on a DIY Arcade Stick

## Build Instrucions

Build with ```g++ -std=c++11 -Wall -o macro macro.cpp -lwiringPi``` in the Raspberry Pi terminal

## Profiles

Profile files ```Profile_One```, ```Profile_Two```, ```Profile_Three```, and ```Profile_Four``` hold the commands for each of the 4 corresponding macro buttons.

Commands have to be listed seperated by newlines, for example:

```
QCF
X
```
Would execute a Hadouken

```
LHold
100
LRel
RHold
X
RRel
```
Would execute Chun-Li's Kikoken

## Commands

### A, B, X, Y, RB, RT, LB, LT

Commands corresponding to Xbox-style layout for button presses

To hold buttons, use ```[ ]Hold``` (eg. ```AHold```, ```BHold```), then release with ```[ ]Rel``` (eg. ```ARel```, ```BRel```) 

### U, D, L, R, UR, UL, DR, DL

Commands for the 8 directions: Up, Down, Left, Right, Up-Right, Up-Left, Down-Right, and Down-Left

To hold buttons, use [ ]Hold (eg. UHold, URHold), then release with [ ]Rel (eg. URel, URRel)

### QCF

Command for Quarter-circle Forward, or 236 in numpad notation

### QCB

Command for Quarter-circle Backwards, or 214 in numpad notation

