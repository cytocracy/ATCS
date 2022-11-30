import random
from copy import copy, deepcopy
import time


# no extra imports!

##############################################################################################
### ------------------------------- Given Helper Functions ------------------------------- ###
##############################################################################################

def make_board(num_rows, num_cols, element):
    '''
    Creates and returns a new 2D array of size num_rows x num_cols where every element 
    is in the array is element

    >>> make_board(2, 3, 'L')
    [['L', 'L', 'L'], ['L', 'L', 'L']]

    '''
    puzzle = []
    for r in range(num_rows):
        row = []
        for c in range(num_cols):
            row.append(element)
        puzzle.append(row)
    return puzzle

def make_random_move(puzzle):
	'''
	Mutates the puzzle to make a random (valid) move. Chooses a random tile to move.
	'''
	b = find_blank(puzzle)
	rn = random.choice([(i, j) for i,j in [(b[0]+1, b[1]), (b[0]-1, b[1]), (b[0], b[1]+1), (b[0], b[1]-1)] if 0<=i<len(puzzle) and 0<=j<len(puzzle[0])])
	
	puzzle[b[0]][b[1]] = puzzle[rn[0]][rn[1]]
	puzzle[rn[0]][rn[1]]=0

def create_sliding_puzzle(n):
	'''
	Creates an nxn sliding puzzle represented as a 2D list. 
	Chooses tile positions by putting the puzzle in the ending configuration, then 
	making tile moves between 2*n**2 and 2*n**2+n times
	'''
	puzzle = make_board(n, n, 0)
	numbers = list(range(0, n**2))
	for row in range(n):
		for col in range(n):
			puzzle[row][col]=row*n+col+1
	puzzle[row][col] = 0

	num_moves = random.randint(n**2, 2*n**2)
	for i in range(num_moves):
		make_random_move(puzzle)

	return puzzle 

def find_blank(puzzle):
	'''
	Returns the location of the blank (0) spot in the puzzle as a (row, column) tuple. Expects
	puzzle to be given as an nxn 2D list.
	'''
	for i in range(len(puzzle)):
		for j in range(len(puzzle[0])):
			if puzzle[i][j]==0:
				return (i,j)


def print_puzzle(puzzle):
	print('_'*(4*len(puzzle)+1))
	for i in range(len(puzzle)):
		line = '|'
		for j in range(len(puzzle[0])):
			if puzzle[i][j] == 0:
				line+="   "
			else:
				line+=str(puzzle[i][j]).ljust(3)
			line += '|'
		print(line)


def check_victory(puzzle):
	'''
	Returns True if the puzzle is in a victory state, False otherwise. Victory state should
	have numbers increasing from 1 to n**2-1 in row major order, with the 0 in the bottom right
	corner.
	'''
	for i in range(len(puzzle)):
		for j in range(len(puzzle[0])):
			if i==len(puzzle)-1 and j==len(puzzle[0])-1:
				if puzzle[i][j]!=0:
					return False
			elif puzzle[i][j]!=i*len(puzzle[0]) + j+1:
				return False
	return True

def to_tuple(puzzle):
	return tuple(map(tuple, puzzle))



# Part 0!

##############################################################################################
### --------------------------- Helper Functions (you write!) ---------------------------- ###
##############################################################################################



# put any other helper functions you need here!


# Part 1!

##############################################################################################
### ---------------------------------- Search Functions ---------------------------------- ###
##############################################################################################

def solve_puzzle(puzzle, heuristic=None):
	'''
	Uses a search algorithm to solve the sliding puzzle! 

	An example puzzle might look like:
	[[1, 2, 3], 
	 [4, 5, 6],
	 [7, 0, 8]]

	and your function might return:
	[[[1, 2, 3], [4, 5, 6], [7, 0, 8]], [[1, 2, 3], [4, 5, 6], [7, 8, 0]]]

	For Part 1: If there is a heuristic function passed in, your function 
	should use the heuristic to decide what is most important to take off the queue next.
	'''
	raise NotImplementedError


# Part 2!

##############################################################################################
### --------------------------------- Heuristic Functions -------------------------------- ###
##############################################################################################

def num_incorrect_locations(puzzle):
	'''
	This function should return the number of tiles that are NOT in the correct position (the 
	position they should be in if the game was over, aka the winning confirguration)
	'''
	raise NotImplementedError


def tile_manhattan_distance(puzzle):
	'''
	This function should return the sum of the manhattan distances between each tile and 
	its correct position (the position it should be in if the game was over, aka the 
	winning confirguration). 
	'''
	raise NotImplementedError



if __name__=="__main__":
	pass




