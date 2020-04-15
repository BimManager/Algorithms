/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:56:19 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 15:01:10 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define XMAX(a, b) ((a) > (b) ? (a) : (b))
#define XABS(x) ((x) < 0 ? -(x) : (x))

struct				s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;

};

int	nodescount(struct s_node *root)
{
	if (!root)
		return (0);
	return (1 + nodescount(root->left) + nodescount(root->right));
}

int	height(struct s_node *root)
{
	if (!root)
		return (-1);
	return (1 + XMAX(height(root->left), height(root->right)));
}

int	is_balanced(struct s_node *root)
{
	if (!root)
		return (1);
	return (is_balanced(root->left)
			&& is_balanced(root->right)
			&& (XABS(height(root->left) - height(root->right)) < 2));
}

static int	xcan_split(struct s_node *root, int n, int *out)
{
	int	count;

	if (!root)
		return (0);
	count = xcan_split(root->left, n, out)
		+ xcan_split(root->right, n, out) + 1;
	if (count == n - count)
		*out = 1;
	return (count);
}

int	can_split(struct s_node *n)
{
	int	n_nodes;
	int	res;

	n_nodes = nodescount(n);
	if (n_nodes & 1)
		return (0);
	res = 0;
	xcan_split(n, n_nodes, &res);
	return (res);
}

