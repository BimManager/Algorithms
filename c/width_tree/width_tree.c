/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:56:25 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 15:04:53 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define XMAX(a, b) ((a) > (b) ? (a) : (b))
#define XMIN(a, b) ((a) < (b) ? (a) : (b))

struct			s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static int	xwidth(struct s_node *root, int *diameter)
{
	int	lh;
	int	rh;
	int	cd;
	
	if (!root)
		return (0);
	lh = xwidth(root->left, diameter);
	rh = xwidth(root->right, diameter);
	cd = lh + rh + 1;
	*diameter = cd > *diameter ? cd : *diameter;
	return (1 + XMAX(lh, rh));
}

int	width_tree(struct s_node *root)
{
	int	diameter;

	diameter = 0;
	xwidth(root, &diameter);
	return (diameter);
}
