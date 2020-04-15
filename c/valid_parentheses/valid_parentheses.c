/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parentheses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 09:17:11 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/03 09:56:20 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define BUFF_SIZE	4096
#define EMPTY		-1

typedef struct		s_stack
{
	char			buffer[BUFF_SIZE];
	int				top;
}					t_stack;

int		stackempty(t_stack *stack)
{
	return (EMPTY == stack->top);
}

void	stackpush(t_stack *stack, char item)
{
	++stack->top;
	(stack->buffer)[stack->top] = item;
}

char	stackpop(t_stack *stack)
{
	char	ret;

	ret = EMPTY;
	if (!stackempty(stack))
	{
		ret = (stack->buffer)[stack->top];
		--stack->top;
	}
	return (ret);
}

char	stackpeek(t_stack *stack)
{
	char	ret;

	if (EMPTY != (ret = stackpop(stack)))
		++stack->top;
	return (ret);
}

int		isparentheses(char c)
{
	return ('[' == c || ']' == c
			|| '(' == c || ')' == c 
			|| '{' == c || '}' == c);
}

int		valid_parentheses(const char *str)
{
	t_stack	stack = { .top = EMPTY };
	char	tmp;

	--str;
	while (*++str)
	{
		if (isparentheses(*str))
		{
			if (!stackempty(&stack))
			{
				tmp = stackpeek(&stack);
				if (1 == *str - tmp
					|| 2 == *str - tmp)
				{
					stackpop(&stack);
					continue ;
				}
			}
			stackpush(&stack, *str);
		}
	}
	return (stackempty(&stack));
}

int		main(int argc, char **argv)
{
	if (2 == argc)
		printf("is_valid: %d\n",
			   valid_parentheses(argv[1]));
	return (0);
}
