/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:57 by cmarsone          #+#    #+#             */
/*   Updated: 2022/09/01 09:53:56 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= ' '
				|| base[i] > 126 || base[j] <= ' ' || base[j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;

	if (!is_base_valid(base))
		return ;
	nb = (long int)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	else
	{
		if (nb / is_base_valid(base) != 0)
			ft_putnbr_base(nb / is_base_valid(base), base);
		write(1, &base[nb % is_base_valid(base)], 1);
	}
	return ;
}
