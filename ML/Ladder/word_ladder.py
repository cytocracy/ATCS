import string

def word_ladder_neighbors(state, valid_words):
    alphabet = string.ascii_lowercase
    neighbors = []

    for i in range(len(state)):
        for letter in alphabet:
            new_word = state[:i] + letter + state[i+1:]
            if new_word in valid_words and new_word != state:
                neighbors.append(new_word)

    return neighbors


def word_ladder_search(valid_words, start_word, end_word, heuristic=None):
    parent = {start_word: None}
    visited = {start_word}
    queue = [start_word]
    curr = None

    num_explored = 0
    while queue:
        curr = queue.pop(0)
        num_explored += 1
        for neighbor in word_ladder_neighbors(curr, valid_words):
            if neighbor == end_word:
                parent[neighbor] = curr
                path  = [neighbor]
                curr_word = neighbor
                while curr_word != start_word:
                    curr_word = parent[curr_word]
                    path.append(curr_word)
                return path[::-1], num_explored
    
            if neighbor not in visited:
                parent[neighbor] = curr
                visited.add(neighbor)
                queue.append(neighbor)

        if heuristic:
            queue.sort(key=lambda x: heuristic(x, end_word), reverse=True)

    return None


def heuristic_function(state, end_word):
    letters_correct = 0
    for i in range(len(state)):
        if state[i] == end_word[i]:
            letters_correct += 1
    return letters_correct
            


if __name__=="__main__":
    with open('words.txt') as f:
        valid_words = {i.strip() for i in f}

    print("You have", len(valid_words), "words to work with.")

    start = "start"
    end = "final"

    path, num_explored = word_ladder_search(valid_words, start, end, heuristic=heuristic_function)
    print(path)
    print("Number of nodes explored:", num_explored)