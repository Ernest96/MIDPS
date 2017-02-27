/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:00:47 by ebitca            #+#    #+#             */
/*   Updated: 2016/08/21 19:28:16 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "check.c"
#include "f_package.c"
#include "get.c"
#include "queue_stack.c"
#include "eval_expr.c"


int	main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("%f\n",(eval_expr(av[1])));
	}
	return (0);
}
