/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:27:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/08 13:37:37 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct				s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static int	xls(struct s_node *node, int prv)
{
	if (!node)
		return (0);
	if (node->value == prv + 1)
		return (1 + MAX(xls(node->left, node->value),
						xls(node->right, node->value)));
	return (MAX(xls(node->left, node->value),
				xls(node->right, node->value)));
}

int			longest_sequence(struct s_node *root)
{
	if (!root)
		return (0);
	return (xls(root, root->value - 1));
}

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node	t_node;

static t_node	*nodenew(int v, t_node *left, t_node *right)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = v;
	node->left = left;
	node->right = right;
	return (node);
}

int	main(void)
{
	t_node	*root;

	root = NULL;
	root = nodenew(41, NULL, NULL);
	root->left = nodenew(43, NULL, NULL);
	root->left->right = nodenew(44, NULL, NULL);
	printf("%d\n", longest_sequence(root));
	return (EXIT_SUCCESS);
}
