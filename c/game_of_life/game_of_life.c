/*
** Copyright 2020 kkozlov
*/

#include "game_of_life.h"

static t_data	*data_new(const void *content, size_t nbytes)
{
  t_data	*data;

  data = malloc(sizeof(t_data));
  data->nbytes = nbytes;
  data->content = malloc(nbytes);
  assert(data->content);
  memcpy(data->content, content, nbytes);
  return (data);
}

static void		data_del(t_data **data, void (*f)(void *))
{
  if (f)
    f((*data)->content);
  free(*data);
  *data = NULL;
}

static t_node	*node_new(const void *content, size_t nbytes)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  node->next = NULL;
  node->data = data_new(content, nbytes);
  return (node);
}

static void		node_del(t_node **node, void (*f)(void *))
{
  if (f)
    data_del(&(*node)->data, f);
  free(*node);
  *node = NULL;
}

static void		queue_init(t_queue *queue)
{
  queue->head = NULL;
  queue->tail = NULL;
}

static int		queue_isempty(t_queue *queue)
{
  return (NULL == queue->head);
}

static void		enqueue(t_queue *queue, const void *data, size_t nbytes)
{
  t_node	*node;

  node = node_new(data, nbytes);
  if (queue_isempty(queue))
    queue->head = node;
  else
    queue->tail->next = node;
  queue->tail = node;
}

static t_data	*dequeue(t_queue *queue)
{
  t_node	*node;
  t_data	*data;

  if (queue_isempty(queue))
    return (NULL);
  node = queue->head;
  if (queue->head == queue->tail)
    queue->tail = NULL;
  queue->head = queue->head->next;
  data = node->data;
  node_del(&node, NULL);
  return (data);
}

static t_grid	*queue_to_grid(t_queue *queue, size_t n_lines, size_t row_len)
{
  t_grid	*grid;
  t_data	*data;
  size_t	i;

  grid = malloc(sizeof(t_grid));
  grid->n_rows = n_lines;
  grid->n_cols = row_len;
  grid->cells = malloc(n_lines * sizeof(void *));
  i = 0;
  while (!queue_isempty(queue))
  {
    data = dequeue(queue);
    grid->cells[i++] = (char *)data->content;
    free(data);
  }
  return (grid);
}

static char		line_isvalid(const char *line)
{
  while (*line)
  {
    if (*line != LIVE_CELL && *line != DEAD_CELL)
      return (0);
    ++line;
  }
  return (1);
}

static t_grid	*input_parse(FILE *fp)
{
  char		*line;
  size_t	linecap;
  ssize_t	linelen;
  ssize_t	rowlen;
  t_queue	queue;
  size_t	n_lines;

  queue_init(&queue);
  line = NULL;
  linecap = 0;
  if (1 == (rowlen = getline(&line, &linecap, fp)))
  {
    printf("An empty line\n");
    exit(1);
  }
  line[rowlen - 1] = '\0';  
  enqueue(&queue, line, rowlen - 1);
  n_lines = 1;
  while ((linelen = getline(&line, &linecap, fp)) > 0)
  {
    if (linelen != rowlen)
    {
      printf("the line of the wrong length\n");
      exit(1);
    }
    line[linelen - 1] = '\0';
    if (!line_isvalid(line))
    {
      printf("line: %s contains invalid symbols\n", line);
      exit(1);
    }
    enqueue(&queue, line, linelen - 1);
    ++n_lines;
  }
  return (queue_to_grid(&queue, n_lines, rowlen - 1));
}

static char		**buffer_alloc(int n_rows, int n_cols)
{
  char	**ret;

  ret = malloc(n_rows * sizeof(void *));
  while (n_rows--)
    ret[n_rows] = malloc(n_cols * sizeof(char));
  return (ret);
}

static void		buffer_free(char **buffer, int n_rows)
{
  while (n_rows--)
    free(buffer[n_rows]);
  free(buffer);
}

static size_t	nbrs_count(t_grid *grid, int i, int j)
{
  size_t	n;

  n = 0;
  if (i)
    n += LIVE_CELL == grid->cells[i - 1][j] ? 1 : 0;
  if (i < grid->n_rows - 1)
    n += LIVE_CELL == grid->cells[i + 1][j] ? 1 : 0;
  if (j)
    n += LIVE_CELL == grid->cells[i][j - 1] ? 1 : 0;
  if (j < grid->n_cols - 1)
    n += LIVE_CELL == grid->cells[i][j + 1] ? 1 : 0;
  if (i && j)
    n += LIVE_CELL == grid->cells[i - 1][j - 1] ? 1 : 0;
  if (i < grid->n_rows - 1 && j < grid->n_cols - 1)
    n += LIVE_CELL == grid->cells[i + 1][j + 1] ? 1 : 0;
  if (i < grid->n_rows - 1 && j)
    n += LIVE_CELL == grid->cells[i + 1][j - 1] ? 1 : 0;
  if (j < grid->n_cols - 1 && i)
    n += LIVE_CELL == grid->cells[i - 1][j + 1] ? 1 : 0;
  return (n);
}

static void		cell_process(t_grid *grid, char **buffer, int i, int j)
{
  size_t	n;

  n = nbrs_count(grid, i, j);
  if (n < 2)
    buffer[i][j] = DEAD_CELL;
  else if (3 == n)
    buffer[i][j] = LIVE_CELL;
  else if (2 == n)
    buffer[i][j] = grid->cells[i][j];
  else
    buffer[i][j] = DEAD_CELL;
}

static void		_swap(void *pv1, void *pv2, size_t n)
{
  char	tmp;

  while (n--)
  {
    tmp = *((char *)pv1 + n);
    *((char *)pv1 + n) = *((char *)pv2 + n);
    *((char *)pv2 + n) = tmp;
  }
}

static void		grid_display(t_grid *grid)
{
  int	i;
  int	j;

  i = -1;
  while (++i < grid->n_rows)
  {
    j = -1;
    while (++j < grid->n_cols)
      printf("%c", grid->cells[i][j]);
    printf("\n");
  }  
}

static void		_play(t_grid *grid)
{
  int	i;
  int	j;
  char	**buffer;

  buffer = buffer_alloc(grid->n_rows, grid->n_cols);
  while (42)
  {
    i = -1;
    while (++i < grid->n_rows)
    {
      j = -1;
      while (++j < grid->n_cols)
        cell_process(grid, buffer, i, j);
    }
    _swap(grid->cells, buffer, grid->n_rows * sizeof(void *));
    grid_display(grid);
    printf("\n");
    sleep(1);
  }
  buffer_free(grid->cells, grid->n_rows);
  buffer_free(buffer, grid->n_rows);
  free(grid);
}

int	main(int argc, char **argv)
{
  int		map_fd;
  t_grid	*grid;
  
  if (2 != argc)
  {
    printf("usage: \n");
    return (EXIT_FAILURE);
  }
  if (-1 == (map_fd = open(argv[1], O_RDONLY)))
  {
    printf("%s\n", strerror(errno));
    return (EXIT_FAILURE);
  }
  grid = input_parse(fdopen(map_fd, "r"));
  close(map_fd);
  _play(grid);
  return (EXIT_SUCCESS);
}
