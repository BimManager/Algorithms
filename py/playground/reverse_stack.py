# reverse_stack.py

import unittest

def reverse_stack(stack):
    if len(stack) == 0:
        return ;
    top = stack.pop();
    reverse_stack(stack);
    insert_at_bottom(stack, top);

def insert_at_bottom(stack, item):
    if len(stack) == 0:
        stack.append(item);
        return ;
    tmp = stack.pop();
    insert_at_bottom(stack, item);
    stack.append(tmp);


class ReverseStackTests(unittest.TestCase):
    def test_reverse_stack(self):
        stack = [1, 2, 3, 4, 5, 6];
        reverse_stack(stack);
        self.assertEqual(stack, [6, 5, 4, 3, 2, 1]);


if __name__ == "__main__":
    unittest.main();
