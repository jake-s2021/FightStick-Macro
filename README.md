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

To hold buttons, use ```[ ]Hold``` (eg. ```UHold```, ```URHold```), then release with ```[ ]Rel``` (eg. ```URel```, ```URRel```)

### (integer)

Entering a whole number following a command will delay the execution of the next command by that amount of milliseconds

For example:

```
RHold
2000
RRel
```
will hold Right for 2 seconds

the number of milliseconds must be 50 or greater. 1 frame = 17ms at 60FPS (1/60 = 0.0166667)

### QCF

Command for Quarter-circle Forward, or 236 in numpad notation

### QCB

Command for Quarter-circle Backwards, or 214 in numpad notation

### HCF

Command for Half-circle Forward, or 41236 in numpad notation

### HCB

Command for Half-circle Backward, or 63214 in numpad notation

### HCFB

Command for Half-circle Forward-Backward, or 412364 in numpad notation

### HCBF

Command for Half-circle Backward-Forward, or 632146 in numpad notation

### DP

Command for Dragon Punch, sometimes called a Zigzag or Z input, or 623 in numpad notation

### RDP

Command for Reverse Dragon Punch, sometimes called Reverse Zigzag or Reverse Z, or 421 in numpad notation

### DQCF

Command for Double Quarter-circle Forward, or 236236 in numpad notation

### DQCB

Command for Double Quarter-circle Backward, or 214214 in numpad notation

### DHCF

Command for Double Half-circle Forward, or 4123641236 in numpad notation

### DHCB

Command for Double Half-circle Backward, or 6321463214 in numpad notation

### DHCFB

Command for Double Half-circle Forward-Backward, or 41236412364 in numpad notation

### DHCBF

Command for Double Half-circle Backward-Forward, or 63214632146 in numpad notation

### SPD

Command for Spinning Pile Driver, or 632147896 in numpad notation

### DSPD

Command for Double Spinning Piledriver, or 63214789632147896 in numpad notation
