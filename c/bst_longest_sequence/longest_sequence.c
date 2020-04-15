/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:40:08 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 18:44:36 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define XMAX(a, b) ((a) > (b) ? (a) : (b))

struct				s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static void	xlongest(struct s_node *root, int expected, int cur_len, int *res)
{
	if (!root)
		return ;
	if (root->value == expected)
		++cur_len;
	else
		cur_len = 1;
	*res = XMAX(*res, cur_len);
	xlongest(root->left, root->value + 1, cur_len, res);
	xlongest(root->right, root->value + 1, cur_len, res);
}

int			longest_sequence(struct s_node *root)
{
	int	res;

	if (!root)
		return (0);
	res = 0;
	xlongest(root, root->value, 0, &res);
	return (res);
}
