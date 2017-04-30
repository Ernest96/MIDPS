/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:22:56 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:22:58 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else if (nb > 0 && nb < 10)
	{
		ft_putchar('0' + nb);
		return ;
	}
	else if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(nb / (-10));
		ft_putchar('0' + 8);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}
