/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:22:44 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/08 13:25:43 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct 				s_node
{	   				
	int				value;
	struct s_node	**nodes;
};

int	height_tree(struct s_node *root)
{
	int	h;
	int	max;

	if (!root)
		return (-1);
	h = 0;
	max = 0;
	while (*root->nodes)
	{
		h = 1 + height_tree(*root->nodes);
		++root->nodes;
		if (h > max)
			max = h;
	}
	return (max);
}
