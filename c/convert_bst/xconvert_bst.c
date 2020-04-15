/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:24:17 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/05 19:36:01 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct				s_node
{
	struct s_node	*left;
	struct s_node	*right;
	int				value;
};

static void	cvtbst(struct s_node *node, struct s_node **head)
{
	struct s_node	*right_p;

	right_p = node->right;
	if (node->left)
		cvtbst(node->left, head);
	if (!*head)
	{
		*head =  node;
		(*head)->left = *head;
		(*head)->right = *head;
	}
	else
	{
		(*head)->left->right = node;
		node->left = (*head)->left;
		(*head)->left = node;
		node->right = *head;
	}
	if (right_p)
		cvtbst(right_p, head);
}

struct s_node	*convert_bst(struct s_node *bst)
{
	struct s_node	*head;

	if (!bst)
		return (NULL);
	head = NULL;
	cvtbst(bst, &head);
	return (head);
}

typedef struct s_node	t_node;

static t_node	*nodenew(int v)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->left = NULL;
	node->right = NULL;
	node->value = v;
	return (node);
}

int			main(void)
{
	t_node	*bst;
	t_node	*head;
	t_node	*it;

//	bst = NULL;
	bst = nodenew(42);
	bst->left = nodenew(40);
	bst->right = nodenew(45);
	bst->right->right = nodenew(47);
	bst->right->left = nodenew(43);
	bst->right->right->right = nodenew(50);
	bst->right->right->right->right = nodenew(75);
	head = convert_bst(bst);
	if (!head)
		ft_printf("(null)\n");
	else
	{
		it = head;
		ft_printf("%3d", it->value);
		while ((it = it->right) != head)
			ft_printf("%3d", it->value);
		ft_printf("\n");
	}
	return (EXIT_SUCCESS);
}	
