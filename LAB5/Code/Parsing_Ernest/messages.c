/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:32:32 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/02 19:14:00 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_usage(void)
{
	ft_putstr("usage: ");
	ft_putstr("asm input_file\n");
	exit(0);
}

void	ft_invalid_input(void)
{
	ft_putstr("Fatal: ");
	ft_putstr("Invalid input\n");
	exit(0);
}

void	ft_comp_error(void)
{
	ft_putstr("Fatal: ");
	ft_putstr("Compilation error\n");
	ft_putstr("Stray nr: ");
	ft_putnbr(g_line);
	ft_putchar('\n');
	exit(0);
}

void	ft_labe_error(const char *s)
{
	ft_putstr("Fatal: ");
	ft_putstr("Compilation error\n");
	ft_putstr(s);
	ft_putchar('\n');
	exit(0);
}
