/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:51:29 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/04 09:55:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H

# include <unistd.h>
# include <stdlib.h>

# define OK		1
# define ERROR	-1

typedef	unsigned char	t_byte;
typedef unsigned int	t_uint;

t_byte	**gen_board(t_uint size);
int		fill_board(int argc, char **cells);



#endif
