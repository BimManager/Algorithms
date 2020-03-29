# flood_fill.py

import unittest

def flood_fill(grid, y, x):
    if x < 0 or y < 0 or x >= len(grid) \
       or y >= len(grid):
        return;
    if grid[y][x] == 1 or \
       grid[y][x] == 'x':
        return;
    grid[y][x] = 'x';
    flood_fill(grid, y - 1, x);
    flood_fill(grid, y + 1, x);
    flood_fill(grid, y, x - 1);
    flood_fill(grid, y, x + 1);


class TestFloodFill(unittest.TestCase):
    def test_flood_fill(self):
        grid = [[1,0,0,0],[0,0,0,0],[1,1,1,1],[0,0,0,1]];
        flood_fill(grid, 1, 0);
        self.assertEqual([[1,'x','x','x'],['x','x','x','x'],[1,1,1,1],[0,0,0,1]], grid);
        grid = [[1,0,0,0],[0,0,0,0],[1,1,1,1],[0,0,0,1]];
        flood_fill(grid, 3, 0);
        self.assertEqual([[1,0,0,0],[0,0,0,0],[1,1,1,1],['x','x','x',1]], grid);
        print(grid);

if __name__ == "__main__":
    unittest.main();
