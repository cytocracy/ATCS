import string

def word_ladder_neighbors(state, valid_words):
    '''
    Given a word (state) as a string and a set of valid words,
    returns a list of words that are all one letter different 
    than state.
    '''
    alphabet = string.ascii_lowercase

    return []

def word_ladder_search(valid_words, start_word, end_word, heuristic=None):
    '''
    Given a list of valid words, a starting word (string), and an ending 
    word (string), returns the path of of strings representing the word ladder from
    start_word to end_word.
    '''
    return None


def heuristic_function(state, end_word):
    pass


if __name__=="__main__":
    # valid_words is a set containing all strings that should be considered valid
    # words (all in lower-case)
    with open('words.txt') as f:
        valid_words = {i.strip() for i in f}

    print("You have", len(valid_words), "words to work with.")

    # start = "start"
    # end = "final"

    # path = word_ladder_search(valid_words, start_word, end_word)