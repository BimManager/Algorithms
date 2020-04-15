/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 08:41:20 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 13:07:43 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct				s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

typedef struct s_node	t_node;

static t_node	*nodenew(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	return (node);
}

int			longest_sequence(struct s_node *root);

int			main(void)
{
	t_node	*root;

	root = nodenew(42);
	root->left = nodenew(44);
	root->left->right = nodenew(45);
	root->right = nodenew(3);
	root->right->right = nodenew(45);
	root->right->right->right = nodenew(46);
	root->right->right->right->right = nodenew(47);
//	root = NULL;
	printf("%d\n", longest_sequence(root));
	return (0);
}
