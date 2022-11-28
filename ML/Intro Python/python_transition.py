# These exercises are meant to help you get used to coding in python! You've
# probably coded some of these before, but now it's time to practice using
# different syntax

def is_even(x):

    return x % 2 == 0


    '''
    If x is even, returns True; otherwise returns False

    is_even(2)
    >>> True

    '''
    raise NotImplementedError

def is_in_bounds(row, col, num_rows, num_cols):

    return 0 <= row < num_rows and 0 <= col < num_cols
    ''' 
    Returns True if the location at (row, col) lies within the bounds
    of (num_rows, num_cols), False otherwise

    is_in_bounds(2, 3, 3, 3)
    >>> False

    '''
    raise NotImplementedError

def list_reverse(l):

    return l[::-1]
    '''
    Given list l, return with the same elements as l, but in the reverse order. You
    can either mutate the original list OR return a new list.

    list_reverse([4, 8, 10, 2, 5])
    >>> [5, 2, 10, 8, 4]
    '''
    raise NotImplementedError

def dict_from_lists(l1, l2):

    dict = {}
    for i in range(len(l1)):
        dict[l1[i]] = l2[i]


    return dict

    '''
    Given two lists of equal length l1 and l2, creates and returns a dictionary 
    mapping each element in l1 to the corresponding element in l2.
    '''
    raise NotImplementedError

#### Iteration #################################################################

def is_prime(x):

    if x <2:
        return False
    elif x == 2:
        return True
    elif is_even(x):
        return False
    r = int(x**0.5)
    for i in range(3, r, 2):
        if x % i == 0:
            return False

    return True

    '''
    Given a number x, returns True if it is prime; otherwise returns False
    '''
    raise NotImplementedError
    
def primes_up_to(x):
    list = []
    for i in range(1, x-1):
        if is_prime(i):
            list.append(i)

    return list

    '''
    Given a number x, returns an in-order list of all primes up to and including x
    '''
    raise NotImplementedError

def make_board(num_rows, num_cols, element):
    board = [[element for i in range(num_cols)] for j in range(num_rows)]
    return board
    '''
    Creates and returns a new 2D array of size num_rows x num_cols where every element 
    is in the array is element
    '''
    raise NotImplementedError

def recreate_list(start, d):
    list = []
    elem = start
    while(elem != None):
        list.append(elem)
        elem = d.get(elem)
    return list

    '''
    Given a starting value and a dictionary d, creates a list from the dictionary 
    and returns it. Start will ALWAYS be a key in the dictionary. The list that's 
    returned should start with start, then the next element in the list will be whatever 
    start is mapped to in the dictionary. None in the dictionary signifies the end of 
    the list (think linked list). See the example below.

    recreate_list(5, {10:2, 5:7, 7:10, 2:None})
    >>> [5, 7, 10, 2]
    '''
    raise NotImplementedError

#### Functions with functions as parameters ####################################

def apply_function(l, func):
    list = []
    for i in l:
        list.append(func(i))

    return list
    '''
    Applies a function to every element in a list WITHOUT modifying original list.
     
    For example, if we do:
    >>> apply_function([1,2,3], is_even)
    our function should return
    >>> [False, True, False]
    '''
    raise NotImplementedError

#### Using the "key" argument ##################################################

def sort_points_by_Y(list_of_points):

    return list_of_points.sort(key = lambda x: x[1], reverse = False)

    '''
    Given a list of points (represented as tuples), uses "sort" with the "key" 
    argument to sort (mutate!) list of the points in ascending order 
    based on their Y coordinates (you should modify the original list). This function
    will not return anything.

    For example, if we input:
    [(1,5), (2,1), (3,7), (8,4), (5,10)] 

    the sorted list should be:
    [(2,1), (8,4), (1,5), (3,7), (5,10)]
    '''
    raise NotImplementedError

def sort_points_by_dict(list_of_ids, d):
    return list_of_ids.sort(key = lambda x: d[x])
    '''
    Given a list of ID numbers (represented as integers)and a dictionary mapping ID numbers to other integers, 
    uses "sort" with the "key" argument to sort (mutate!) list of IDs in ascending order 
    based on their value in the dictionary (you should modify the original list). This function
    will not return anything.

    For example, if we input:
    [578, 920, 418, 395] and {578:10, 395:7, 920:2, 418:15}

    the sorted list should be:
    [920, 395, 578, 418]
    '''
    raise NotImplementedError

def max_sum(list_of_points):
    max = list_of_points[0]
    for i in list_of_points:
        if i[0] + i[1] > max[0] + max[1]:
            max = i
    return max

    '''
    Given a list of points (represented as tuples), uses "max" with the "key" argument 
    to return the point that has the largest sum of X and Y coordinates.
    '''
    raise NotImplementedError


if __name__=="__main__":

    pass


