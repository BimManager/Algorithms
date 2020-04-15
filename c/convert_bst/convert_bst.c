/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:08:56 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 15:21:21 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct			s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static void		xcvtbst(struct s_node *root, struct s_node **head)
{
	struct s_node	*right;

	if (!root)
		return ;
	xcvtbst(root->left, head);
	right = root->right;
	if (!*head)
	{
		*head = root;
		(*head)->left = *head;
		(*head)->right = *head;
	}
	else
	{
		(*head)->left->right = root;
		root->left = (*head)->left;
		root->right = (*head);
		(*head)->left = root;
	}
	xcvtbst(right, head);
	
}

struct s_node	*convert_bst(struct s_node *bst)
{
	struct s_node	*head;

	head = 0;
	xcvtbst(bst, &head);
	return (head);
}
