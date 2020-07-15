/*
** Copyright 2020 kkozlov
*/

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <assert.h>
  
# define LIVE_CELL	'X'
# define DEAD_CELL	'-'

typedef struct	s_data
{
  void			*content;
  size_t		nbytes;
}				t_data;

typedef struct	s_node
{
  struct s_node	*next;
  t_data		*data;
}				t_node;

typedef struct	s_queue
{
  t_node		*head;
  t_node		*tail;
}				t_queue;

typedef struct	s_grid
{
  char			**cells;
  int			n_rows;
  int			n_cols;
}				t_grid;

#endif /* GAME_OF_LIFE_H */
