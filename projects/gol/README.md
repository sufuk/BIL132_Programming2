BIL132: Programming 2
---------------------

Project #1: The Game of Life

## Overview

In this assignment you will be using arrays, matrices to write the functions needed to play [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

## Game of life

The Game of Life was created by John Conway in 1970's for a cellular automaton simulation. The game played on a two dimentional grid and each box of the grid represents a cell which can be either dead or alive. Every cell interacts with its immediate eight neighbours, which are the horizontally, vertically, or diagonally adjacent to the cell (Note that the cell on the borders will not have 8 neighbours!). Once the initial positions of living cells set, the board evolves to the next generation using following rules:

- An alive cell with 1 or less alive neighbours will die (under population/loneliness)
- An alive cell with 4 or more alive neighbours will die (overpopulation)
- An alive cell with 2 or 3 neighbours will suvive to the next generation.
- A dead cell with exactly 3 alive nieghbours will be alive on the next generation (reproduction)


Despite it's simple nature many very complex patterns can evolve or be created. An example 10 x 10 board, and the 1st generation where "#" is alive and "." is dead: 

	Generation 0
	| . | . | . | . | . | . | . | . | . | . |
	| . | # | # | # | . | . | . | . | . | . |
	| # | # | # | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |

	Generation 1
	| . | . | # | . | . | . | . | . | . | . |
	| # | . | . | # | . | . | . | . | . | . |
	| # | . | . | # | . | . | . | . | . | . |
	| . | # | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |
	| . | . | . | . | . | . | . | . | . | . |


You will have a framework to get the initial board, print the current one and overall flow. However you must write the fuctions to evaluate current population to the next generation.

## Submission

You must deliver your project yourself. Please make an appointment before via email.

## Evaluation

You will have an verbal test about your project.

## F.A.Q



