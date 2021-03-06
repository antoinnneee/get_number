/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:44:23 by abureau           #+#    #+#             */
/*   Updated: 2016/04/22 14:49:30 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NUMBER_H
#define GET_NUMBER_H

#include "GNL_NOFD/get_next_line.h"
#include "GNL_NOFD/libft/includes/libft.h"

int		**get_number(int fd);
int		ft_satoi(char *str);
void	print_map_number(int **arraynum);
int		parse_number(char *line);
int		ft_issignednumber(const char c);
#endif
