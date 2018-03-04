/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:19:28 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/21 21:19:29 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		read_flags(char **av, int ar)
{
	int	i;
	int	j;

	i = 1;
	while (i < ar && av[i][0] == '-' && ft_strchr("vcf", av[i][1]))
	{
		j = 1;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == 'v')
				g_block.debug = 1;
			else if (av[i][j] == 'c')
				g_block.color = 1;
			else if (av[i][j] == 'f')
				g_block.file = 1;
			++j;
		}
		++i;
	}
	return (i);
}
