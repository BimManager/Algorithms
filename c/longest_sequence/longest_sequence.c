/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 08:13:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 08:49:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct				s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static void	xlongest(struct s_node *root, int expected, int cur_seq, int *max)
{
	if (!root)
		return ;
	if (root->value == expected)
		++cur_seq;
	else
		cur_seq = 1;
	if (cur_seq > *max)
		*max = cur_seq;
	xlongest(root->left, root->value + 1, cur_seq, max);
	xlongest(root->right, root->value + 1, cur_seq, max);
}

int			longest_sequence(struct s_node *root)
{
	int	max;

	if (!root)
		return (0);
	max = 0;
	xlongest(root, root->value, 0, &max);
	return (max);
}

