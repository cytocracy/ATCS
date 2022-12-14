from graphics_maze import *

def neighbors(maze, row, col):
    '''
    This function takes in a 2D maze and (row, col) maze location and should return a list of
    all of the valid neighboring locations in the board.
    '''
    init_n = [(row+1, col), (row-1, col), (row, col+1), (row, col-1)]
    true_n = []
    for n in init_n:
        if n[0]>=0 and n[0]<len(maze) and n[1]>=0 and n[1]<len(maze[0]):
            if maze[n[0]][n[1]]!="|":
                true_n.append(n)
    return true_n

def maze_gen_neighbors(row, col, num_rows, num_cols, seen):
    init_n = [(row+2, col), (row-2, col), (row, col+2), (row, col-2)]
    true_n = []
    for n in init_n:
        if n[0]>=1 and n[0]<num_rows-1 and n[1]>=1 and n[1]<num_cols-1 and n not in seen:
            true_n.append(n)
    return true_n


# We'll code here!

def maze_DFS(window, canvas, maze, start, goal):
    curr = None
    queue = [start]
    parent = {start: None}
    visited = {start}

    while queue:
        curr = queue.pop(0)
        row, col = curr
        for n in neighbors(maze, row, col):
            if n == goal:
                parent[n] = curr
                path = [n]
                current_node = n
                while current_node != start:
                    current_node = parent[current_node]
                    path.append(current_node)
                return path[::-1]
            if n not in visited:
                queue = [n] + queue
                visited.add(n)
                parent[n] = curr
                update_graphics(window, canvas, new_loc=n)

def maze_BFS(window, canvas, maze, start, goal):
    curr = None
    queue = [start]
    parent = {start: None}
    visited = {start}

    while queue:
        curr = queue.pop(0)
        row, col = curr
        for n in neighbors(maze, row, col):
            if n == goal:
                parent[n] = curr
                path = [n]
                current_node = n
                while current_node != start:
                    current_node = parent[current_node]
                    path.append(current_node)
                return path[::-1]
            if n not in visited:
                queue.append(n)
                visited.add(n)
                parent[n] = curr
                update_graphics(window, canvas, new_loc=n)



if __name__ == "__main__":

    # feel free to change the maze size to test out different mazes!
    
    window, canvas, maze, start, goal = make_maze(maze_size = "large") # change the map size to see different ones!

    path = maze_DFS(window, canvas, maze, start, goal)
    if path != None:
        update_graphics(window, canvas, path=path)
        print(path)
    else:
        print("No path found!")


    window.mainloop()

