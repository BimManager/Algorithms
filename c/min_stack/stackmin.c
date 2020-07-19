#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct	s_stackmin
{
	int			*storage;
	int			capacity;
	int			top;
	int			min;
}				t_stackmin;

t_stackmin		*stackmin_new(int capacity)
{
	t_stackmin	*stack;

	stack = malloc(sizeof(t_stackmin));
	stack->storage = malloc(capacity * sizeof(int));
	stack->capacity = capacity;
	stack->top = -1;
	return (stack);
}

int				stackmin_isempty(t_stackmin *stack)
{
	return (-1 == stack->top);
}

int				stackmin_min(t_stackmin *stack)
{
	return (stack->min);
}

void			stackmin_push(t_stackmin *stack, int x)
{
	int	tmp;
	
	if (stackmin_isempty(stack))
		stack->min = x;
	else if (stack->min > x)
	{
		tmp = 2 * x - stack->min;
		stack->min = x;
		x = tmp;
	}
	stack->storage[++stack->top] = x;
}

int				stackmin_pop(t_stackmin *stack)
{
	int	x;
	
	if (stackmin_isempty(stack))
		return (INT_MIN);
	x = stack->storage[stack->top--];
	if (x < stack->min)
	{
		stack->min = 2 * stack->min - x;
		x = (x + stack->min) / 2;
	}
	return (x);
}


int				main(void)
{
	int	arr[] = { 1, 2, -42, 5, -32 };
	int	n;
	int	i;
	t_stackmin	*stack;

	stack = stackmin_new(42);
	n = sizeof(arr) / sizeof(arr[0]);
	i = -1;
	while (++i < n)
	{
		stackmin_push(stack, arr[i]);
		printf("push: %d min: %d\n", arr[i], stackmin_min(stack));
	}
	while (!stackmin_isempty(stack))
	{
		i = stackmin_pop(stack);
		printf("pop: %d min: %d\n", i, stackmin_min(stack));
	}
	return (0);
}

