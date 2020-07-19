/*
** Copyright 2020 kkozlov
*/

#define DIGITS "123456789"
#define NDIGITS 9
#define NSQ     3
#define EMPTY_CELL  '.'

typedef struct  s_board
{
    char        **cells;
    int         nrows;
    int         ncols;
}               t_board;

static int  _is_empty(t_board *board, int row, int col)
{
    return (EMPTY_CELL == board->cells[row][col]);
}

static int  _is_valid(t_board *board, int row, int col, char digit)
{
    int i;
        
    i = -1;
    while (++i < NDIGITS)
        if (board->cells[i][col] == digit || board->cells[row][i] == digit)
            return (0);
    while (row % 3)
        --row;
    while (col % 3)
        --col;
    i = -1;
    while (++i < NSQ)
    {
        if ((board->cells[row + i][col] == digit || board->cells[row][col + i] == digit)
            || board->cells[row + i][col + i] == digit)
            return (0);
        if (NSQ - 1 == i)
            if (board->cells[row + i][col + i - 1] == digit 
                || board->cells[row + i - 1][col + i] == digit)
                return (0);
    }
    return (1);
}

static void _place(t_board *board, int row, int col, char digit)
{
    board->cells[row][col] = digit;
}

static void _remove(t_board *board, int row, int col)
{
    board->cells[row][col] = EMPTY_CELL;
}

static int  _solve(t_board *board, int next)
{
    int i;
    int row;
    int col;
    int solved;
    
    row = next / NDIGITS;
    col = next % NDIGITS;
    if (NDIGITS * NDIGITS == next)
        return (1);
    i = -1;
    if (!_is_empty(board, row, col))
        solved = _solve(board, next + 1);
    else
    {
      while (++i < NDIGITS)
        if (_is_valid(board, row, col, DIGITS[i]))
        {
            _place(board, row, col, DIGITS[i]);
            solved = _solve(board, next + 1);
            if (!solved)
                _remove(board, row, col);
            else
                return (solved);
        }
    }
    return (solved);
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    t_board sudoku;
    
    if (0 >= boardSize)
        return ;
    sudoku.cells = board;
    sudoku.nrows = boardSize;
    sudoku.ncols = boardColSize[0];
    _solve(&sudoku, 0);
}
