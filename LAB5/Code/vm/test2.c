#include "../corewar.h"
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# define WIN_HEIGHT 980
# define WIN_WIDTH 1820
//#include <graphics.h>



void waitFor (long secs)
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while (difftime(start.tv_usec + secs, end.tv_usec) > 0)
		gettimeofday(&end, NULL);
	;
}

void	print_usage()
{
	ft_putstr("Usage: ./corewar -n 1 {name} -n 2 {name}");
	ft_putstr("[-n 3 {name} -n 4 {name} -dump {nr.}]\n");
	exit (0);
}

int		main(int argc, char **argv)
{
	time_t  t;
	int8_t flag;
	int i;
	int8_t p_n;
	int8_t found;

	srand((unsigned) time(&t));
	found = 0;
    init_steps();
	if (argc == 1)
		print_usage();
	if (argv[1][0] != '-')
		print_usage();
	i = 0;
	p_zero();
	while (++i < argc)
	{
		flag = find_flag(argv[i]);
		if (!flag)
			print_usage();
		if (flag == 1)
		{
			++i;
			if (i >= argc || found)
				print_usage();
			found = 1;
			if (str_is_num(argv[i]))
				g_dump = ft_atoi(argv[i]);
			else
				print_usage();
		}
		if (flag == 2)
		{
			if (i - argc > -2)
				print_usage();
			if (!argv[i + 1])
				print_usage();
			if(str_is_num(argv[i+1]))
				p_n = ft_atoi(argv[i+1]);
			else
				print_usage();
			if (p_n < 1 || p_n > 4)
				print_usage();
			if (g_arr[p_n].nr)
				print_usage();
			g_arr[p_n].nr = p_n;
			if (!argv[i + 2])
				print_usage();
			if (ft_strcmp(argv[i + 2] + (ft_strlen(argv[i + 2]) - 4), ".cor"))
				print_usage();
			g_arr[p_n].filename = ft_strdup(argv[i+2]);
			i += 2;
		}
	}
	ft_check_players();
	insert_gamelife();
	load();
    ft_start();
}
