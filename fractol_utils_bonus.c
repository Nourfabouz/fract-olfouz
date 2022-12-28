/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:41:51 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/12 15:01:41 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	negtv;
	int	sum;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	negtv = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negtv = -1;
		i++;
	}
	sum = 0;
	n = 0;
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		n = (str[i] - 48);
		sum = ((sum * 10) + n * negtv);
		i++;
	}
	return (sum);
}
