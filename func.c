/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:41:20 by abureau           #+#    #+#             */
/*   Updated: 2016/04/21 16:30:12 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_number.h"

void		print_map_number(int **arraynum)
{
	int	index;
	int	line;

	index = 1;
	line = 1;
	while (line < arraynum[0][0])
	{
		while (index <= (arraynum[line][0]))
		{
			ft_putnbr(arraynum[line][index]);
			ft_putchar(' ');
			index++;
		}
		ft_putchar('\n');
		index = 1;
		line++;
	}
}

int		contain_letter(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (ft_isalpha(line[i]) == 1 || line[1] == '+')
		{
			return (1);
		}
			else
			i++;
	}
	return (0);
}

int		ft_satoi(char	*str)
{
	unsigned int	signe ;
	int		i;
	int		j;
	int		countsigne;

	j = 0;
	countsigne = 0;
	while (!ft_isdigit(str[j]) && (str[j]) != 0)
	{
		if (str[j] == '-')
		{
			countsigne++;
			i = j;
		}
		j++;
	}
	signe = (countsigne % 2 ) ?  0 : 1 ;
	ft_putstrnb("signe number :", signe);
	if (!signe)
	{
		str[j - 1] = '-';
	}
	else
		countsigne = 0;
	return ((countsigne > 0) ? ft_atoi(&str[j - 1]) :ft_atoi(&str[j]));
}




