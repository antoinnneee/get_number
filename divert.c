/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:41:20 by abureau           #+#    #+#             */
/*   Updated: 2016/04/22 15:26:44 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_number.h"

int		ft_issignednumber(const char c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (1);
	return (0);
}

void	print_map_number(int **arraynum)
{
	int	index;
	int	line;

	index = 1;
	line = 1;
	ft_putstrnb("number of line : ", arraynum[0][0]);
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

int		parse_number(char *line)
{
	int	i;
	int state;

	i = 0;
	state = 0;
	if (!ft_strlen(line))
		return (0);
	while (line[i] != 0)
	{
		if (ft_issignednumber(line[i]) == 1)
		{
			while (ft_issignednumber(line[i]) ^ ft_isdigit(line[i]))
				i++;
			while (ft_isdigit(line[i]))
			{
				i++;
				state++;
			}
			if (!(line[i] == ' ' ^ line[i] == '\0') || state == 0)
				return (0);
			state = 0;
		}
		i++;
	}
	return (1);
}

int		ft_satoi(char *str)
{
	unsigned int	signe;
	int				i;
	int				j;
	int				countsigne;

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
	signe = (countsigne % 2) ? 0 : 1;
	if (!signe)
	{
		str[j - 1] = '-';
	}
	else
		countsigne = 0;
	return ((countsigne > 0) ? ft_atoi(&str[j - 1]) : ft_atoi(&str[j]));
}
