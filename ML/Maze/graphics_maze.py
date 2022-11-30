# wow this code is so spaghetti pls don't look

import math
import random
from tkinter import *
from PIL import Image, ImageTk
import time

# Module for drawing figures using Tkinter python library and pillow image library

def make_maze(maze_dims = None, maze_size = "small"):
    '''
    Creates a new maze. There are six default mazes: 
    "small", "medium", "large", and "huge" have a corresponding image file in the mazes folder.
    "no_connect" is a graph that should have no path
    '''
    window_size = None

    if maze_size == "small":
        window_size = (80, 80)
        im = Image.open("test_mazes/smol_maze.png")
        start_loc = (5, 6)
        goal_loc = (1, 1)

    elif maze_size == "medium":
        window_size = (190, 190)
        im = Image.open("test_mazes/med_maze.png")
        start_loc = (17, 17)
        goal_loc = (1, 1)

    elif maze_size == "large":
        window_size = (490, 490)
        im = Image.open("test_mazes/lrg_maze.png")
        start_loc = (47, 47)
        goal_loc = (1, 1)

    elif maze_size == "no_connect":
        window_size = (80, 80)
        start_loc = (6, 1)
        goal_loc = (1, 6)
        list_maze = make_no_connect_maze()
        im = None

    elif maze_size == "blank":
        if maze_dims != None:
            window_size = (10*maze_dims[1], 10*maze_dims[0])
        else:
            print("Maze dims not valid.")
            return None
        im = None
        start_loc = (1,1)
        goal_loc = (maze_dims[0]-2,maze_dims[1]-2)

    elif maze_size == "open":
        window_size = (200, 200)
        goal_loc = (1,1)
        start_loc = (18, 18)
        list_maze = make_open_maze()
        im=None

    else:
        print("Maze size not valid. Please use 'small', 'medium', 'large', 'no_connect', 'open', or 'blank'.")
        return None


    # tkinter window things

    window = Tk()
    window.geometry(f'{window_size[0]}x{window_size[1]}')
    # canvas = Canvas(window, width=window_size[1], height=window_size[0])
    canvas = Canvas(window, width=window_size[0], height=window_size[1])
    canvas.pack()

    if im !=None:
        window.img = img = ImageTk.PhotoImage(im)
        canvas.create_image(0,0,anchor=NW,image=img)
        canvas.create_rectangle(start_loc[1]*10, start_loc[0]*10, start_loc[1]*10+9, start_loc[0]*10+9, fill="Lime", outline = 'Lime')
        canvas.create_rectangle(goal_loc[1]*10, goal_loc[0]*10, goal_loc[1]*10+9, goal_loc[0]*10+9, fill="Aqua", outline = 'Aqua')
        
    if maze_size in ["open", "no_connect"]:
        make_graphics_from_list_maze(window, canvas, list_maze)
        canvas.create_rectangle(start_loc[1]*10, start_loc[0]*10, start_loc[1]*10+9, start_loc[0]*10+9, fill="Lime", outline = 'Lime')
        canvas.create_rectangle(goal_loc[1]*10, goal_loc[0]*10, goal_loc[1]*10+9, goal_loc[0]*10+9, fill="Aqua", outline = 'Aqua')
        
    # maze list representation things

    
    wsize = (int(window_size[0]/10), int(window_size[1]/10))
    if maze_size not in ["no_connect", "blank", "open"]:
        list_maze = []
        for i in range(wsize[1]):
            row = []
            for j in range(wsize[0]):
                val = im.getpixel((j*10, i*10))[0]
                if val == 255 or (i,j)==start_loc or (i,j)==goal_loc:
                    val = "O"
                else:
                    val = "|"
                row.append(val)
            list_maze.append(row)
    
    elif maze_size == "blank":
        list_maze = make_blank_maze()
        make_graphics_from_list_maze(window, canvas, list_maze)
    
    window.update()

    return window, canvas, list_maze, start_loc, goal_loc

def make_graphics_from_list_maze(window, canvas, list_maze):
    for i in range(len(list_maze)):
        for j in range(len(list_maze[0])):
            if list_maze[i][j]=='O':
                canvas.create_rectangle(j*10, i*10, j*10+9, i*10+9, fill="White", outline="White")
            else:
                canvas.create_rectangle(j*10, i*10, j*10+9, i*10+9, fill="Black", outline="Black")

def make_no_connect_maze():
    list_maze = [['|', '|', '|', '|', '|', '|', '|', '|']]
    for i in range(1, 7):
        row = ['|']
        for j in range(1, 7):
            if i==j:
                ch = '|'
            else:
                ch = 'O'
            row.append(ch)
        row.append('|')
        list_maze.append(row)

    list_maze.append(['|', '|', '|', '|', '|', '|', '|', '|'])
    return list_maze

def make_open_maze():
    list_maze = [['|']*20]
    for i in range(1, 19):
        row = ['|']
        for j in range(1, 19):
            row.append('O')
        row.append('|')
        list_maze.append(row)
    list_maze.append(['|']*20)
    return list_maze

def make_blank_maze():
    list_maze = []
    for i in range(maze_dims[0]):
        row = []
        for j in range(maze_dims[1]):
            if (i,j)==goal_loc:
                row.append('X')
            elif (i,j)==start_loc:
                row.append('O')
            else:
                row.append('|')
        list_maze.append(row)
    return list_maze

def update_graphics(window, canvas, new_loc=None, path=[]):
    for (r, c) in path[1:-1]:
        canvas.create_rectangle(c*10, r*10, c*10+9, r*10+9, fill="Red", outline = 'Red')
    if path:
        canvas.create_rectangle(path[0][1]*10, path[0][0]*10, path[0][1]*10+9, path[0][0]*10+9, fill="Lime", outline = 'Lime')
        canvas.create_rectangle(path[-1][1]*10, path[-1][0]*10, path[-1][1]*10+9, path[-1][0]*10+9, fill="Aqua", outline = 'Aqua')
    if new_loc!=None:
        canvas.create_rectangle(new_loc[1]*10, new_loc[0]*10, new_loc[1]*10+9, new_loc[0]*10+9, fill="Thistle", outline = 'Thistle')

    window.after(50, window.update())

def remove_wall(window, canvas, maze, loc, n):
    wall_rem = (int((loc[0]-n[0])/2) + n[0], int((loc[1]-n[1])/2) + n[1])
    if maze[n[0]][n[1]]!='O':
        if maze[n[0]][n[1]] != "X":
            canvas.create_rectangle(n[1]*10, n[0]*10, n[1]*10+9, n[0]*10+9, fill="White", outline = 'White')
        maze[n[0]][n[1]] = 'O'
    if maze[wall_rem[0]][wall_rem[1]] != 'O': 
        if maze[wall_rem[0]][wall_rem[1]] != "X":
            canvas.create_rectangle(wall_rem[1]*10, wall_rem[0]*10, wall_rem[1]*10+9, wall_rem[0]*10+9, fill="White", outline = 'White')
        maze[wall_rem[0]][wall_rem[1]] = 'O'

    window.after(50, window.update())

    return maze
