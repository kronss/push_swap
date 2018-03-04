/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 22:17:33 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/16 22:17:37 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ps_error(char i)
{
	i == 1 ? ft_printf("Error\n") : 0;
	i == 2 ? ft_printf("Error\n") : 0;
	i == 3 ? ft_printf("Error\n") : 0;
	i == 4 ? ft_printf("Error\n") : 0;
	i == 5 ? ft_printf("Error\n") : 0;
	exit(i);
}
