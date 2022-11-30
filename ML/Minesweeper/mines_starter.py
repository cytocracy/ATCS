def new_game(num_rows, num_cols, bombs):
    game = {
                "dimensions": (num_rows, num_cols),
                "state": "ongoing",
                "board": create_board(bombs, num_rows, num_cols),
                "visible": [[False for i in range(num_cols)] for j in range(num_rows)]
            }

    return game

def create_board(bombs, num_rows, num_cols):
    board = [[0 for i in range(num_cols)] for j in range(num_rows)]

    for bomb in bombs:
        board[bomb[0]][bomb[1]] = '.'
        for i in range(-1, 2):
            for j in range(-1, 2):
                if bomb[0] + i >= 0 and bomb[0] + i < num_rows and bomb[1] + j >= 0 and bomb[1] + j < num_cols:
                    if board[bomb[0] + i][bomb[1] + j] != '.':
                        board[bomb[0] + i][bomb[1] + j] += 1
    return board

def dump(game):
    lines = ["dimensions: {}".format(game['dimensions']),
             "board: {}".format("\n       ".join(map(str, game["board"]))),
             "visible:  {}".format("\n       ".join(map(str, game["visible"]))),
             "state: {}".format(game['state']),
             ]
    print("\n".join(lines))


def dig(game, row, col):
    if(game["visible"][row][col]):
        return 0
    game["visible"][row][col] = True
    if(game["board"][row][col] == '.'):
        # Ms. wholeman-- bruh
        # game["state"] = "defeat"
        return 1
    if(game["board"][row][col] != 0):
        return 1
    num = 1
    for i in range(-1, 2):
        for j in range(-1, 2):
            if row + i >= 0 and row + i < game["dimensions"][0] and col + j >= 0 and col + j < game["dimensions"][1]:
                num += dig(game, row + i, col + j)
    return num
    
def check_game_over(game):
    for i in range(game["dimensions"][0]):
        for j in range(game["dimensions"][1]):
            if(game["board"][i][j] == '.' and game["visible"][i][j]):
                game["state"] = "defeat"
                return True
    for i in range(game["dimensions"][0]):
        for j in range(game["dimensions"][1]):
            if(not game["visible"][i][j] and game["board"][i][j] != '.'):
                return False
    game["state"] = "victory"
    return True


if __name__ == "__main__":
    pass