#!/usr/bin/env python3
import python_transition as pt
import unittest

class Test00_Beginning(unittest.TestCase):
    def test_is_even(self):
        result1 = pt.is_even(0)
        result2 = pt.is_even(-1)
        result3 = pt.is_even(-6)
        result4 = pt.is_even(11)
        result5 = pt.is_even(2)

        self.assertTrue(result1)
        self.assertFalse(result2)
        self.assertTrue(result3)
        self.assertFalse(result4)
        self.assertTrue(result5)

    def test_is_in_bounds(self):
        num_rows = 5
        num_cols = 3
        in_bounds = pt.is_in_bounds(1, 2, num_rows, num_cols)
        rbefore0 = pt.is_in_bounds(-1, 2, num_rows, num_cols)
        cbefore0 = pt.is_in_bounds(1, -1, num_rows, num_cols)
        row_afterw = pt.is_in_bounds(1, 3, num_rows, num_cols)
        col_afterh = pt.is_in_bounds(5, 2, num_rows, num_cols)

        self.assertTrue(in_bounds)
        self.assertFalse(rbefore0)
        self.assertFalse(cbefore0)
        self.assertFalse(row_afterw)
        self.assertFalse(col_afterh)

    def test_list_reverse(self):
        l1 = [1, 3, 8]
        l2 = ["yes", "no", "yes"]

        result1 = pt.list_reverse(l1)
        result2 = pt.list_reverse(l2)

        if result1 == None:
            self.assertEqual(l1, [8, 3, 1])
            self.assertEqual(l2, ["yes", "no", "yes"])
        else:
            self.assertEqual(result1, [8, 3, 1])
            self.assertEqual(result2, ["yes", "no", "yes"])


    def test_dict_from_lists(self):
        l1 = [1, 3, 8]
        l2 = ["yes", "no", "yes"]

        result = pt.dict_from_lists(l1, l2)

        for i in range(len(l1)):
            self.assertTrue(l1[i] in result)
        
        self.assertTrue(result[1]=="yes")
        self.assertTrue(result[3]=="no")
        self.assertTrue(result[8]=="yes")

class Test01_Iteration(unittest.TestCase):
    def test_is_prime(self):
        self.assertFalse(pt.is_prime(0))
        self.assertFalse(pt.is_prime(1))
        self.assertTrue(pt.is_prime(2))
        self.assertTrue(pt.is_prime(5))
        self.assertFalse(pt.is_prime(6))

    def test_primes_up_to(self):
        result = pt.primes_up_to(10)
        expected = [2, 3, 5, 7]

        self.assertEqual(result, expected)

        result = pt.primes_up_to(1)

        self.assertEqual(result, [])

    def test_make_board(self):
        result = pt.make_board(2, 5, 0)
        expected = [[0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0]]
        self.assertEqual(result, expected)
        result[1][1]=5
        self.assertFalse(result[0][1]==5, msg="Your rows are aliasing!")

        result = pt.make_board(3, 3, True)
        expected = [[True, True, True],
                    [True, True, True],
                    [True, True, True]]
        self.assertEqual(result, expected)


    def test_recreate_list(self):
        start = 5
        d = {10:2, 5:7, 7:10, 2:None}
        result = pt.recreate_list(start, d)
        self.assertEqual([5, 7, 10, 2], result)

        d = {5:None}
        result2 = pt.recreate_list(start, d)
        self.assertEqual([5], result2)

        start = (1,1)
        d = {(1,1):(3,5), (3,5):(2,1), (2,1):None}
        result3 = pt.recreate_list(start, d)
        self.assertEqual([(1,1), (3,5), (2,1)], result3)


class Test02_FuncAsParam(unittest.TestCase):
    def test_apply_function(self):
        l = [1, 2, 3]
        result = pt.apply_function(l, lambda x:x%2==0)
        self.assertEqual(result, [False, True, False])
        self.assertEqual(l, [1,2,3], msg="You shouldn't modify the original list!")
        
        l = [1,2,3]
        result = pt.apply_function(l, lambda x:x**2)
        self.assertEqual(result, [1,4,9])

class Test03_UsingKey(unittest.TestCase):
    def test_sort_points_by_Y(self):
        l = [(1,5), (2,1), (3,7), (8,4), (5,10)] 
        start = [(1,5), (2,1), (3,7), (8,4), (5,10)] 
        pt.sort_points_by_Y(l)
        expected = [(2,1), (8,4), (1,5), (3,7), (5,10)]
        self.assertEqual(l, expected)
        self.assertNotEqual(l, start, msg="Make sure you change the input list!")

    def test_sort_points_by_dict(self):
        inp_list = [578, 920, 418, 395] 
        start = [578, 920, 418, 395]
        inp_dict = {578:10, 395:7, 920:2, 418:15}
        pt.sort_points_by_dict(inp_list, inp_dict)
        expected = [920, 395, 578, 418]
        self.assertEqual(inp_list, expected)
        self.assertNotEqual(inp_list, start, msg="Make sure you change the input list!")

    def test_max_sum(self):
        inp_list = [(1,5), (2,1), (3,7), (8,4), (5,10)]

        result = pt.max_sum(inp_list)
        expected = (5,10)
        self.assertEqual(expected, result)

        inp_list = [(-2, 11), (5, 7), (1, 4)]

        result = pt.max_sum(inp_list) 
        expected = (5,7)
        self.assertEqual(expected, result)





if __name__ == '__main__':
    res = unittest.main(verbosity=3, exit=False)

