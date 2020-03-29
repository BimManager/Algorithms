# n_queens_problem.py

import sys;
import unittest;

#n = int(sys.argv[1]);
n = 4;

board = [[0 for x in range(n)] for i in range(n)];
#print(board);

def isPositionSafe(board, i, j):
    if isRowSafe(board, i, j) and \
       isColumnSafe(board, i, j) and \
       isDiagonalSafeLeft(board, i, j) and \
       isDiagonalSafeRight(board, i, j):
        return (True);
    return (False);

def isRowSafe(board, i, j):
    while j >= 0:
        if 1 == board[i][j]:
            return (False);
        j -= 1;
    return (True);

def isColumnSafe(board, i, j):
    while i >= 0:
        if board[i][j] == 1:
            return (False);
        i -= 1;
    return (True);

def isDiagonalSafeLeft(board, i, j):
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return (False);
        i -= 1;
        j -= 1;
    return (True);


def isDiagonalSafeRight(board, i, j):
    while i >= 0 and j < len(board):
        if board[i][j] == 1:
            return (False);
        i -= 1;
        j += 1;
    return (True);


def placeQueen(board, i, j):
    board[i][j] = 1;

def removeQueen(board, i, j):
    board[i][j] = 0;

def solveNQueenProblem(board, i):
    if i == len(board):
        print(board);
        return;
    for j in range(len(board)):
        if isPositionSafe(board, i, j):
            placeQueen(board, i, j);
#            print(board);
            solveNQueenProblem(board, i + 1);
            removeQueen(board, i, j);


class TestNQueenProblem(unittest.TestCase):
    def test_isRowSafe(self):
        board_ = [[0 for x in range(n)] for i in range(n)];
        self.assertTrue(isRowSafe(board_,0,0));
        board_[0][0] = 1;
        self.assertFalse(isRowSafe(board_,0,0));
        board_[2][0] = 1;
        self.assertTrue(isRowSafe(board_,3,0));

    def test_isColumnSafe(self):
        board_ = [[0 for x in range(n)] for i in range(n)];
        board_[0][0] = 1;
        self.assertFalse(isColumnSafe(board_,0,0));
        self.assertTrue(isColumnSafe(board_,0,1));

    def test_isDiagonalSafeLeft(self):
        board_ = [[0 for x in range(n)] for i in range(n)];
        board_[0][0] = 1;
        self.assertFalse(isDiagonalSafeLeft(board_,0,0));
        self.assertTrue(isDiagonalSafeLeft(board_,0,1));
        board_[2][2] = 1;
        self.assertFalse(isDiagonalSafeLeft(board_,3,3));

    def test_isPositionSafe(self):
        board_ = [[0 for x in range(n)] for i in range(n)];
        board_[0][0] = 1;
        self.assertFalse(isPositionSafe(board_,1,1));
        self.assertTrue(isPositionSafe(board_,1,2));

    def test_solveNQueenProblem(self):
        board_ = [[0 for x in range(n)] for i in range(n)];
        solveNQueenProblem(board_, 0);
        
if __name__ == "__main__":
    unittest.main();
