/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:19:37 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 15:26:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct			s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

struct s_node	*convert_bst(struct s_node *bst);

typedef struct s_node	t_node;

static t_node	*nodenew(int v)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = v;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	main(void)
{
	t_node	*root;
	t_node	*head;
	t_node	*it;

//	root = nodenew(42);
//	root->left = nodenew(42);
//	root->left->right = nodenew(42);
//	root->right = nodenew(42);

/*	root = nodenew(5);
	root->left = nodenew(1);
	root->right = nodenew(6);
	root->right->left = nodenew(7);
	root->right->left->left = nodenew(3);
	root->right->left->right = nodenew(2);
	root->right->right = nodenew(4);
	root->right->right->right = nodenew(8);*/

/*	root = nodenew(28);
	root->left = nodenew(51);
	root->left->left = nodenew(26);
	root->left->right = nodenew(48);
	root->left->left->left = nodenew(76);
	root->left->left->right = nodenew(13);*/
//	root->right->right = nodenew(4);
//	root->right->right->right = nodenew(8);

	root = nodenew(42);
	root->left = nodenew(21);
	root->right = nodenew(84);
//	root->right->right = nodenew(42);
	head = convert_bst(root);
	printf("%d ", head->value);
	it = head;
	while ((it = it->right) != head)
		printf("%d ", it->value);
	return (0);
}



