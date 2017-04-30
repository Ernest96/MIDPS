#include "../corewar.h"
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <conio.h>
# define WIN_HEIGHT 980
# define WIN_WIDTH 1820
#include <graphics.h>
#include "../corewar.h"
#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50


void change_all(int, int, char*, int);

int		ft_count(long value, int base)
{
	int n;
	n = 0;
	while(value)
	{
		value = value / base;
		n++;
	}
	if(n == 0)
		return(1);
	return (n);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*((char*)s + i) = 0;
		i++;
	}
	return ;
}


char	*ft_itoa_base(unsigned char value, int base)
{
	long number;
	char *str;
	int n;
	int i;
	i = 0;
	number = value;
	if(number < 0)
	{
		number = -number;
		n = ft_count(number, base);
		if(base == 10)
		{
		str = (char *)malloc(sizeof(char) * (n + 3));
		str[0] = '-';
		str[n+1] = '\0';
		n++;
		i = 1;
		}
		else
		{
		str = (char *)malloc(sizeof(char) * (n+2));
		str[n] = '\0';
		}
	}
	else
	{
		n = ft_count(number, base);
		str = (char *)malloc(sizeof(char) * (n+2));
		str[n] = '\0';
	}
	if(value >= 0 && value < 16)
	{
		++n;
		str[n] = 0;
		str[0] = '0';
	}
	while(--n >= i)
	{
		if((number % base) == 10)
			str[n] = 'a';
		else if((number % base) == 11)
			str[n] = 'b';
		else if((number % base) == 12)
			str[n] = 'c';
		else if((number % base) == 13)
			str[n] = 'd';
		else if((number % base) == 14)
			str[n] = 'e';
		else if((number % base) == 15)
			str[n] = 'f';
		else
			str[n] = '0' + (number % base);
		number = number / base;
	}
	return (str);
}

int		ft_atoi(const char *str)
{
	int i;
	int nr;
	int n;

	i = 0;
	nr = 0;
	n = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == ' ') ||
			(str[i] == '\f') || (str[i] == '\v') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		n = 1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nr *= 10;
		nr += (int)str[i] - '0';
		i++;
	}
	if (n == 1)
		return (-nr);
	else
		return (nr);
}


void	ft_putstr(char const *s)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	unsigned char d;

	d = (unsigned char)c;
	printf("%c",d);
}

char	*ft_strdup(const char *src)
{
	unsigned int	i;
	char			*mem;
	unsigned int	j;

	if (src == NULL)
	{
		mem = (char*)malloc(1);
		*mem = 0;
		return (mem);
	}
	i = 0;
	while (*(src + i))
		i++;
	mem = (char*)malloc(i + 1);
	if (!mem)
		return (0);
	j = -1;
	while (++j < i)
		*(mem + j) = *(src + j);
	*(mem + j) = 0;
	return (mem);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}



size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (100);
	while (i == 0 && (*(s1 + j) != 0 || *(s2 + j) != 0))
	{
		i = *(unsigned char *)(s1 + j) - *(unsigned char *)(s2 + j);
		j++;
	}
	return (i);
}

int8_t	find_flag(char *s)
{
	if (!ft_strcmp(s, "-dump"))
		return (1);
	if (!ft_strcmp(s, "-n"))
		return (2);
	return (0);
}

int8_t str_is_num(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	return (1);
}

void p_zero()
{
	int i;
	int j;

	i = 0;
	g_winner = 0;
	while(++i < 5)
	{
		j = -1;
		g_arr[i].nr = 0;
		g_arr[i].name = NULL;
		g_arr[i].filename = NULL;
		g_arr[i].alive = 0;
		while(++j < 100)
		{
			ft_bzero(g_arr[i].proc[j].reg, 16);
			g_arr[i].proc[j].reg[0] = i;
			g_arr[i].proc[j].pc = 0;
			g_arr[i].proc[j].ip = 0;
			g_arr[i].proc[j].carry = 1;
			g_arr[i].proc[j].live = 0;
            g_arr[i].proc[j].begin = 0;
            g_arr[i].proc[j].end = 0;
			g_arr[i].proc[j].cycles_to_wait = -1;
		}
		g_arr[i].pr_n = 1;
	}
}

void	ft_check_players()
{
	int8_t flag;
	int8_t i;

	flag = 0;
	i = 0;
	while (++i < 5)
		if (g_arr[i].nr)
			++flag;
	if (flag < 2)
		exit(0);
    g_num = flag;
}

void	set_null()
{
	int i;

	i = -1;
	while(++i < 4)
		g_order[i] = NULL;
}

unsigned char *ft_read_name(int i)
{
	int fd;
	unsigned char *s;
	unsigned char temp[2180];
	char c;

	g_j[i - 1] = 0;
	if(g_arr[i].filename == NULL)
		return (NULL);
	g_arr[i].alive = 1;
	s = (unsigned char*)malloc(sizeof(char)*4096);
	ft_bzero(s, 4096);
	fd = open(g_arr[i].filename, O_RDONLY);
	if (fd < 0)
		exit (21);
	read(fd, temp, 4);
	ft_bzero(temp, 4);
	read(fd, temp, 128);
	g_arr[i].name = ft_strdup((char*)temp);
	read(fd, temp, 2048);
	while(read(fd, &c, 1))
	{
		s[g_j[i - 1]] = c;
		++g_j[i - 1];
	}
	return (s);
}


void	insert_gamelife()
{
	int i;

	g_order = (unsigned char**)malloc(sizeof(char*) * 4);
	set_null();
	i = 0;
	while (++i < 5)
		g_order[i - 1] = ft_read_name(i);
}

void	load()
{
	int i;
	int j;
	int delta;
	int offset;

	i = 0;
	delta = MEMSIZE / g_num;
	offset = 0;
	while (++i < 5)
	{
		j = 0;
        if (g_arr[i].filename == NULL) {
            continue;
        }
		while (j < g_j[i - 1])
		{
			// prepare_show(i, offset + j, g_order[i - 1][j]);
			g_mem[offset + j] = g_order[i - 1][j];
			g_color[offset + j] = i;
			j++;
		}

		g_arr[i].proc[0].pc = offset;
		g_arr[i].proc[0].ip = offset;
        g_arr[i].proc[0].begin = offset;
        g_arr[i].proc[0].end = offset + j - 1;
		offset += delta;
	}
}

void    init_steps(void)
{
    g_steps[0] = 0;
    g_steps[1] = 10;
    g_steps[2] = 5;
    g_steps[3] = 5;
    g_steps[4] = 10;
    g_steps[5] = 10;
    g_steps[6] = 6;
    g_steps[7] = 6;
    g_steps[8] = 6;
    g_steps[9] = 20;
    g_steps[10] = 25;
    g_steps[11] = 25;
    g_steps[12] = 800;
    g_steps[13] = 1000;
    g_steps[14] = 50;
    g_steps[15] = 1000;
    g_steps[16] = 2;
}

void            prepare_show(int juc, int pos, unsigned char val)
{
    g_mem[pos] = val;
    g_pl = juc;
    g_popo = pos;
    g_poval = val;
    g_tear = 1;
}

int             aff(t_instr instr, int juc, int procs)
{
    if (instr.acb != 0x40)
        return (1);
    ft_putchar(instr.arg1 % 256);
    return(0);
}

int             zjmp(t_instr instr, int juc, int procs)
{
    if (instr.acb != 0x80)
        return (1);
    if (g_arr[juc].proc[procs].carry == 0)
        return (0);
    g_arr[juc].proc[procs].pc = (g_arr[juc].proc[procs].pc + instr.arg1) % MEMSIZE;
    g_arr[juc].proc[procs].ip = g_arr[juc].proc[procs].pc;
    return (0);
}

int         add(t_instr instr, int juc, int procs)
{
    int res;

    if (instr.acb != 0x54)
        return (1);
    if (instr.arg1 <= 0 || instr.arg1 > 16)
        return (1);
    if (instr.arg2 <= 0 || instr.arg2 > 16)
        return (1);
    if (instr.arg3 <= 0 || instr.arg3 > 16)
        return (1);
    res = g_arr[juc].proc[procs].reg[instr.arg1 - 1] + g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    g_arr[juc].proc[procs].reg[instr.arg3 - 1] = res;
    return (0);
}

int         sub(t_instr instr, int juc, int procs)
{
    int res;

    if (instr.acb != 0x54)
        return (1);
    if (instr.arg1 <= 0 || instr.arg1 > 16)
        return (1);
    if (instr.arg2 <= 0 || instr.arg2 > 16)
        return (1);
    if (instr.arg3 <= 0 || instr.arg3 > 16)
        return (1);
    res = g_arr[juc].proc[procs].reg[instr.arg1 - 1] - g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    g_arr[juc].proc[procs].reg[instr.arg3 - 1] = res;
    return (0);
}


int         live(t_instr instr, int juc ,int procs)
{
    if (instr.acb != 0x80)
        return (1);
    if(instr.arg1 <= 0 || instr.arg1 > 4)
        return (1);
    g_arr[juc].proc[procs].live++;
    ft_putstr("LIVE JUC = \t\t\t");
    ft_putstr(g_arr[juc].name);
    ft_putstr("\n");

    if(instr.arg1 == juc)
        g_winner = juc;
    return (0);
}

int         ld(t_instr instr, int juc, int procs)
{
    if (instr.acb != 0x90 && instr.acb != 0xD0)
        return (1);
    if (instr.arg2 <= 0 || instr.arg2 > 16)
        return (1);
    g_arr[juc].proc[procs].reg[instr.arg2 - 1] = instr.arg1 % IDX_MOD;
    return (0);
}

int         lld(t_instr instr, int juc, int procs)
{
    if (instr.acb != 0x90 && instr.acb != 0xD0)
        return (1);
    if (instr.arg2 <= 0 || instr.arg2 > 16)
        return (1);
    g_arr[juc].proc[procs].reg[instr.arg2 - 1] = instr.arg1;
    return (0);
}

int         ldi(t_instr instr, int juc ,int procs)
{
    int result;
    short vasea;
    int val1;
    int val2;
    int val3;

    if (instr.acb >> 6 == 0)
        return (1);
    if ((instr.acb >> 4 & 0x3) == 0 || (instr.acb >> 4 & 0x3) == 3)
        return (1);
    if ((instr.acb >> 2 & 0x3) != 1 )
        return (1);
    if ((instr.acb & 0x3) != 0)
        return (1);
    if (instr.acb >> 6 == 1 && (instr.arg1 <= 0 || instr.arg1 > 16))
        return (1);
    if ((instr.acb >> 4 & 0x3) == 1 && (instr.arg2 <= 0 || instr.arg2 > 16))
        return (1);
    if ((instr.acb >> 2 & 0x3) == 1 && (instr.arg3 <= 0 || instr.arg3 > 16))
        return (1);
    if (instr.acb >> 6 == 1)
        val1 = g_arr[juc].proc[procs].reg[instr.arg1 - 1];
    else if (instr.acb >> 6 == 2)
        val1 = instr.arg1;
    else
    {
        vasea = g_mem[g_arr[juc].proc[procs].pc + (instr.arg1 % IDX_MOD)] << 8;
        vasea = vasea | g_mem[g_arr[juc].proc[procs].pc + (instr.arg1 % IDX_MOD) + 1];
        val1 = vasea;
    }
    if ((instr.acb >> 4 & 0x3) == 1 )
        val2 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    else
        val2 = instr.arg2;
    val3 = val1 + val2;
    result = ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)]) << 24;
    result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + 1 + (val3 % IDX_MOD)]) << 16;
    result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + 2  + (val3 % IDX_MOD)]) << 8;
    result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + 3 + (val3 % IDX_MOD)]);
    g_arr[juc].proc[procs].reg[instr.arg3 - 1] = result;
    return (0);

}

int         lldi(t_instr instr, int juc ,int procs)
{
    int result;
    short vasea;
    int val1;
    int val2;
    int val3;

    if (instr.acb >> 6 == 0)
        return (1);
    if ((instr.acb >> 4 & 0x3) == 0 || (instr.acb >> 4 & 0x3) == 3)
        return (1);
    if ((instr.acb >> 2 & 0x3) != 1 )
        return (1);
    if ((instr.acb & 0x3) != 0)
        return (1);
    if (instr.acb >> 6 == 1 && (instr.arg1 <= 0 || instr.arg1 > 16))
        return (1);
    if ((instr.acb >> 4 & 0x3) == 1 && (instr.arg2 <= 0 || instr.arg2 > 16))
        return (1);
    if ((instr.acb >> 2 & 0x3) == 1 && (instr.arg3 <= 0 || instr.arg3 > 16))
        return (1);
    if (instr.acb >> 6 == 1)
        val1 = g_arr[juc].proc[procs].reg[instr.arg1 - 1];
    else if (instr.acb >> 6 == 2)
        val1 = instr.arg1;
    else
    {
        vasea = g_mem[g_arr[juc].proc[procs].pc + (instr.arg1 % MEMSIZE)] << 8;
        vasea = vasea | g_mem[g_arr[juc].proc[procs].pc + (instr.arg1 % MEMSIZE) + 1];
        val1 = vasea;
    }
    if ((instr.acb >> 4 & 0x3) == 1 )
        val2 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    else
        val2 = instr.arg2;
    val3 = val1 + val2;
    result = ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + (val3 % MEMSIZE)]) << 24;
    result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + 1 + (val3 % MEMSIZE)]) << 16;
    result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + 2  + (val3 % MEMSIZE)]) << 8;
    result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].pc + 3 + (val3 % MEMSIZE)]);
    g_arr[juc].proc[procs].reg[instr.arg3 - 1] = result;
    return (0);

}

int         sti(t_instr instr, int juc, int procs)
{
    int res;
    int val1;
    int val2;
    int val3;
    short vasea;

    if(instr.acb >> 6 != 1)
        return(1);
    if(juc == 2)
        vasea = 0;
    if(instr.arg1 <= 0 || instr.arg1 > 16)
        return(1);
    if((instr.acb >> 4 & 0x3) == 0)
        return(1);
    if((instr.acb & 0x3) != 0)
        return(1);
    if((instr.acb >> 2 & 0x3) == 0 || (instr.acb >> 2 & 0x3) == 3)
        return(1);
    if ((instr.acb >> 4 & 0x3) == 1 && (instr.arg2 <= 0 || instr.arg2 > 16))
        return (1);
    if ((instr.acb >> 2 & 0x3) == 1 && (instr.arg3 <= 0 || instr.arg3 > 16))
        return (1);
    if ((instr.acb >> 4 & 0x3) == 1 )
        val1 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    else if ((instr.acb >> 4 & 0x03) == 2)
        val1 = instr.arg2;
    else
    {
        vasea = g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] << 8;
        vasea = vasea | g_mem[g_arr[juc].proc[procs].pc + ((instr.arg2 + 1) % IDX_MOD)];
        val1 = vasea;
    }
    if ((instr.acb >> 2 & 0x3) == 1 )
        val2 = g_arr[juc].proc[procs].reg[instr.arg3 - 1];
    else
        val2 = instr.arg3;
    val3 = val1 + val2;

    res = g_arr[juc].proc[procs].reg[instr.arg1 - 1];

    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)] = juc;
    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 1] = juc;
    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 2] = juc;
    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 3] = juc;
    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)] = (res >> 24) & 0xff;

    change_all((g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)) % 74, (g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)) / 74,
               ft_itoa_base((res >> 24) & 0xff, 16), juc);

    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 1] =  (res >> 16) & 0xff;

    change_all((g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)+1) % 74, (g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)+1) / 74,
               ft_itoa_base((res >> 16) & 0xff, 16), juc);

    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 2] =  (res >> 8) & 0xff;

    change_all((g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)+2) % 74, (g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)+2) / 74,
               ft_itoa_base((res >> 8) & 0xff, 16), juc);

    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 3] =  res & 0xff;

    change_all((g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)+3) % 74, (g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)+3) / 74,
               ft_itoa_base(res & 0xff, 16), juc);

    return (0);
}

int         st(t_instr instr, int juc ,int procs)
{
    int val1;

    if (instr.acb != 0x50 && instr.acb != 0x70)
        return (1);
    if (instr.arg1 > 16 || instr.arg1 <= 0)
        return (1);
    if (((instr.acb >> 4 & 0x3) == 1) && (instr.arg2 > 16 || instr.arg2 <= 0))
        return (1);
    if ((instr.acb >> 4 & 0x3) == 1)
    {
             g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD)] = juc;
        g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 1] = juc;
        g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 2] = juc;
        g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 3] = juc;

        val1 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];

        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD)] = (g_arr[juc].proc[procs].reg[instr.arg1 -1] >> 24) & 0xff;
        change_all((g_arr[juc].proc[procs].pc + (val1 % IDX_MOD)) % 74, (g_arr[juc].proc[procs].pc + (val1 % IDX_MOD)) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 -1] >> 24 & 0xff, 16), juc);

        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 1] =  (g_arr[juc].proc[procs].reg[instr.arg1-1]) >> 16 & 0xff;
        change_all((g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 1) % 74, (g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 1) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 -1] >> 16 & 0xff, 16), juc);

        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 2] =  g_arr[juc].proc[procs].reg[instr.arg1-1] >> 8 & 0xff;
        change_all((g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 2) % 74, (g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 2) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 -1] >> 8 & 0xff, 16), juc);

        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 3] =  g_arr[juc].proc[procs].reg[instr.arg1-1] & 0xff;
        change_all((g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 3) % 74, (g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 3) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 -1] & 0xff, 16), juc);

    }
    else
    {
          g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] = juc;
        g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 1] = juc;
        g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 2] = juc;
        g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 3] = juc;

        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] = g_arr[juc].proc[procs].reg[instr.arg1 -1] >> 24 & 0xff;
        change_all((g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)) % 54, (g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 - 1] >> 24 & 0xff, 16), juc);

        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 1] =  g_arr[juc].proc[procs].reg[instr.arg1-1] >> 16 & 0xff;
        change_all((g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 1) % 74, (g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 1) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 - 1] >> 16 & 0xff, 16), juc);

        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 2] =  g_arr[juc].proc[procs].reg[instr.arg1-1] >> 8 & 0xff;
              change_all((g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 2) % 74, (g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) +2) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 - 1] >> 8 & 0xff, 16), juc);

        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 3] =  g_arr[juc].proc[procs].reg[instr.arg1-1] & 0xff;
        change_all((g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 3) % 54, (g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 3) / 74,
               ft_itoa_base(g_arr[juc].proc[procs].reg[instr.arg1 - 1] & 0xff, 16), juc);


    }
    return 0;
}

int             andd(t_instr instr, int juc, int procs)
{
    int res;
    int val1;
    int val2;

    if ((instr.acb >> 6) == 0)
        return (1);
    if  ((instr.acb >> 4 & 0x3) == 0)
        return (1);
    if ((instr.acb >> 2 & 0x3) != 1)
        return (1);
    if ((instr.acb & 0x3) != 0)
        return (1);
    if (instr.acb >> 6 == 1 && (instr.arg1 <= 0 || instr.arg1 > 16))
        return (1);
    if ((instr.acb >> 4 & 0x3) == 1 && (instr.arg2 <= 0 || instr.arg2 > 16))
        return (1);
    if ((instr.acb >> 2 & 0x3) == 1 && (instr.arg3 <= 0 || instr.arg3 > 16))
        return (1);
    if (instr.acb >> 6 == 1 )
        val1 = g_arr[juc].proc[procs].reg[instr.arg1 - 1];
    else if (instr.acb >> 6 == 2)
        val1 = instr.arg1;
    else
    {
        val1 = g_mem[g_arr[juc].proc[procs].pc + (instr.arg1 % IDX_MOD)] >> 8;
        val1 = val1 | g_mem[g_arr[juc].proc[procs].pc + ((instr.arg1 + 1) % IDX_MOD)];
    }
    if ((instr.acb >> 4 & 0x3) == 1 )
        val2 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    else if (instr.acb >> 4 == 2)
        val2 = instr.arg2;
    else
    {
        val2 = g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] >> 8;
        val2 = val2 | g_mem[g_arr[juc].proc[procs].pc + ((instr.arg2 + 1) % IDX_MOD)];
    }
    res = val1 & val2;
    g_arr[juc].proc[procs].reg[instr.arg3 - 1] = res;
    return (0);
}

int             orr(t_instr instr, int juc, int procs)
{
    int res;
    int val1;
    int val2;

    if ((instr.acb >> 6) == 0)
        return (1);
    if  ((instr.acb >> 4 & 0x3) == 0)
        return (1);
    if ((instr.acb >> 2 & 0x3) != 1)
        return (1);
    if ((instr.acb & 0x3) != 0)
        return (1);
    if (instr.acb >> 6 == 1 && (instr.arg1 <= 0 || instr.arg1 > 16))
        return (1);
    if ((instr.acb >> 4 & 0x3) == 1 && (instr.arg2 <= 0 || instr.arg2 > 16))
        return (1);
    if ((instr.acb >> 2 & 0x3) == 1 && (instr.arg3 <= 0 || instr.arg3 > 16))
        return (1);
    if (instr.acb >> 6 == 1 )
        val1 = g_arr[juc].proc[procs].reg[instr.arg1 - 1];
    else if (instr.acb >> 6 == 2)
        val1 = instr.arg1;
    else
    {
        val1 = g_mem[g_arr[juc].proc[procs].pc + (instr.arg1 % IDX_MOD)] >> 8;
        val1 = val1 | g_mem[g_arr[juc].proc[procs].pc + ((instr.arg1 + 1) % IDX_MOD)];
    }
    if ((instr.acb >> 4 & 0x3) == 1 )
        val2 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    else if (instr.acb >> 4 == 2)
        val2 = instr.arg2;
    else
    {
        val2 = g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] >> 8;
        val2 = val2 | g_mem[g_arr[juc].proc[procs].pc + ((instr.arg2 + 1) % IDX_MOD)];
    }
    res = val1 | val2;
    g_arr[juc].proc[procs].reg[instr.arg3 - 1] = res;
    return (0);
}

int             xorr(t_instr instr, int juc, int procs)
{
    int res;
    int val1;
    int val2;

    if ((instr.acb >> 6) == 0)
        return (1);
    if  ((instr.acb >> 4 & 0x3) == 0)
        return (1);
    if ((instr.acb >> 2 & 0x3) != 1)
        return (1);
    if ((instr.acb & 0x3) != 0)
        return (1);
    if (instr.acb >> 6 == 1 && (instr.arg1 <= 0 || instr.arg1 > 16))
        return (1);
    if ((instr.acb >> 4 & 0x3) == 1 && (instr.arg2 <= 0 || instr.arg2 > 16))
        return (1);
    if ((instr.acb >> 2 & 0x3) == 1 && (instr.arg3 <= 0 || instr.arg3 > 16))
        return (1);
    if (instr.acb >> 6 == 1)
        val1 = g_arr[juc].proc[procs].reg[instr.arg1 - 1];
    else if (instr.acb >> 6 == 2)
        val1 = instr.arg1;
    else
    {
        val1 = g_mem[g_arr[juc].proc[procs].pc + (instr.arg1 % IDX_MOD)] >> 8;
        val1 = val1 | g_mem[g_arr[juc].proc[procs].pc + ((instr.arg1 + 1) % IDX_MOD)];
    }
    if ((instr.acb >> 4 & 0x3) == 1 )
        val2 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];
    else if (instr.acb >> 4 == 2)
        val2 = instr.arg2;
    else
    {
        val2 = g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] >> 8;
        val2 = val2 | g_mem[g_arr[juc].proc[procs].pc + ((instr.arg2 + 1) % IDX_MOD)];
    }
    res = val1 ^ val2;
    g_arr[juc].proc[procs].reg[instr.arg3 - 1] = res;
    return (0);
}

int forks(t_instr instr, int juc, int procs)
{
    int j;
    int beg;
    int pr;
    int temp;

    temp = 0;
    if (instr.acb != 0x80)
        return (1);
    if (g_arr[juc].pr_n > 99)
        return (1);
    j = g_arr[juc].proc[procs].begin;
    beg = g_arr[juc].proc[procs].pc + (instr.arg1 % IDX_MOD);
    pr = (++(g_arr[juc].pr_n)) - 1;
    while (j <= g_arr[juc].proc[procs].end)
    {
        g_mem[(beg + temp) % MEMSIZE] = g_mem[j % MEMSIZE];
        g_color[(beg + temp) % MEMSIZE] = juc;
        change_all(((beg + temp) % MEMSIZE) % 74, ((beg + temp) % MEMSIZE) / 74,
               ft_itoa_base(g_mem[j % MEMSIZE], 16), juc);
        temp++;
        j++;
    }
    g_arr[juc].proc[pr].begin = beg;
    g_arr[juc].proc[pr].end = beg + j - 1;
    g_arr[juc].proc[pr].pc = beg;
    g_arr[juc].proc[pr].ip = beg;
    g_arr[juc].proc[pr].carry =  g_arr[juc].proc[procs].carry;
    j = -1;
    while (++j < 16)
        g_arr[juc].proc[pr].reg[j] = g_arr[juc].proc[procs].reg[j];
    return (0);
}

int lforks(t_instr instr, int juc, int procs)
{
    int j;
    int beg;
    int pr;
    int temp;

    temp = 0;
    if (instr.acb != 0x80)
        return (1);
	if (g_arr[juc].pr_n > 99)
		return (1);
    j = g_arr[juc].proc[procs].begin;
    beg = g_arr[juc].proc[procs].pc + (instr.arg1 % MEMSIZE);
    pr = ++(g_arr[juc].pr_n) - 1;
    while (j <= g_arr[juc].proc[procs].end)
    {
        g_mem[(beg + temp) % MEMSIZE] = g_mem[j % MEMSIZE];
        g_color[(beg + temp) % MEMSIZE] = juc;
          change_all(((beg + temp) % MEMSIZE) % 74, ((beg + temp) % MEMSIZE) / 74,
               ft_itoa_base(g_mem[j % MEMSIZE], 16), juc);
        temp++;
        j++;
    }
    g_arr[juc].proc[pr].begin = beg;
    g_arr[juc].proc[pr].end = j - 1;
    g_arr[juc].proc[pr].pc = beg;
    g_arr[juc].proc[pr].ip = beg;
    g_arr[juc].proc[pr].carry =  g_arr[juc].proc[procs].carry;
    j = -1;
    while (++j < 16)
        g_arr[juc].proc[pr].reg[j] = g_arr[juc].proc[procs].reg[j];
    return (0);
}

int				execute_instr(t_instr instr, int juc, int procs)
{
    unsigned char code;

    code = instr.code;
    if (code == 1)
        return (live(instr, juc, procs));
    else if (code == 2)
        return (ld(instr, juc, procs));
    else if (code == 3)
        return (st(instr, juc, procs));
    else if (code == 4)
        return (add(instr, juc, procs));
    else if (code == 5)
        return (sub(instr, juc, procs));
    else if (code == 6)
        return (andd(instr, juc, procs));
    else if (code == 7)
        return (orr(instr, juc, procs));
    else if (code == 8)
        return (xorr(instr, juc, procs));
    else if (code == 9)
        return (zjmp(instr, juc, procs));
    else if (code == 10)
        return (ldi(instr, juc, procs));
    else if (code == 11)
        return (sti(instr, juc, procs));
    else if (code == 12)
        return (forks(instr, juc, procs));
    else if (code == 13)
        return (lld(instr, juc, procs));
    else if (code == 14)
        return (lldi(instr, juc, procs));
    else if (code == 15)
        return lforks(instr, juc, procs);
    else if (code == 16)
		return (aff(instr, juc, procs));
    return (0);
}


int	get_arg(unsigned char acb, int juc, int procs)
{
    int result;
    short vasea;

    if (acb == 1)
    {
        g_arr[juc].proc[procs].ip++;
        return (g_mem[(g_arr[juc].proc[procs].ip - 1) % MEMSIZE] & 0x000000FF);
    }
    else if (acb == 2)
    {
        result = 0;
        result = ((unsigned int)g_mem[g_arr[juc].proc[procs].ip % MEMSIZE]) << 24;
        result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].ip + 1 % MEMSIZE]) << 16;
        result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].ip + 2 % MEMSIZE]) << 8;
        result = result | ((unsigned int)g_mem[g_arr[juc].proc[procs].ip + 3 % MEMSIZE]);
        g_arr[juc].proc[procs].ip += 4;
        return (result);
    }
    else if (acb == 3)
    {
        result = 0;
        vasea = ((unsigned short)g_mem[g_arr[juc].proc[procs].ip % MEMSIZE]) << 8;
        vasea= vasea | ((unsigned short)g_mem[g_arr[juc].proc[procs].ip + 1 % MEMSIZE]);
        result = vasea;
        g_arr[juc].proc[procs].ip += 2;
        return (result);
    }
    return (0);
}

int		get_args(t_instr *instr, int juc , int proc)
{
    unsigned int acb;

    acb = instr->acb;
    if (instr->code >= 16)
        return (1);
    instr->arg1 = 0;
    instr->arg2 = 0;
    instr->arg3 = 0;
    if (acb > 0xFC)
        return 0;
    if ((acb >> 6 & 0x3) == 0)
        return 0;
    else
        instr->arg1 = get_arg(acb >> 6 & 0x3, juc , proc);
    if (((acb >> 4) & 0x3) == 0)
        return (execute_instr(*instr, juc, proc));
    else
        instr->arg2 = get_arg(acb >> 4 & 0x3, juc, proc);

    if (((acb >> 2) & 0x3) == 0)
        return (execute_instr(*instr, juc, proc));
    else
        instr->arg3 = get_arg(((acb >> 2) & 0x3), juc, proc);
    return (execute_instr(*instr, juc, proc));
}

void    execute_proc(int j)
{
    int i;
    int flag;

    flag = 0;
    i = -1;
    while (++i < g_arr[j].pr_n)
    {
        t_instr instr;
        if (g_arr[j].proc[i].cycles_to_wait == -1) {
            instr.code = g_mem[g_arr[j].proc[i].ip % MEMSIZE];

            g_arr[j].proc[i].cycles_to_wait = g_steps[instr.code];
            continue;
        }
        else if (g_arr[j].proc[i].cycles_to_wait > 0)
        {
            g_arr[j].proc[i].cycles_to_wait--;
            continue;
        }
        instr.code = g_mem[g_arr[j].proc[i].ip % MEMSIZE];
        g_arr[j].proc[i].ip++;
        instr.acb = g_mem[g_arr[j].proc[i].ip % MEMSIZE];
        g_arr[j].proc[i].ip++;
        flag = get_args(&instr, j, i);
        g_arr[j].proc[i].cycles_to_wait = -1;
        if (flag == 0)
            g_arr[j].proc[i].pc = g_arr[j].proc[i].ip;
        else
        {
            g_arr[j].proc[i].pc++;
            g_arr[j].proc[i].ip = g_arr[j].proc[i].pc;
        }
        if (g_arr[j].proc[i].pc >= g_arr[j].proc[i].end) {
            g_arr[j].proc[i].pc = g_arr[j].proc[i].begin;
            g_arr[j].proc[i].ip = g_arr[j].proc[i].begin;
        }
    }
}


int		decrease_cycle(int *nr_cycle)
{
    static int	count;
    int			i;
    int         j;
    int			flag;
    int         sum;
    int         total_sum;

    i = 0;
    flag = 0;
    total_sum = 0;
    while (++i <= 4)
    {
        if (g_arr[i].filename == NULL || g_arr[i].alive == 0)
            continue ;
        j = -1;
        sum = 0;
        while (++j < g_arr[i].pr_n) {
            sum += g_arr[i].proc[j].live;
            g_arr[i].proc[j].live = 0;
        }
        total_sum += sum;
        if (sum >= 21)
        {
            (*nr_cycle) += CYCLE_DELTA;
            flag = 1;
        }
        if (sum == 0)
        {
            g_arr[i].alive = 0;
            ft_putstr("A MUUUUUUUUUUUUUUUUUUUURIT : ");
            ft_putstr(g_arr[i].name);
            ft_putchar('\n');
        }

    }
    if (flag == 0)
        count++;
    if (count == 10)
    {
        (*nr_cycle) += CYCLE_DELTA;
        count = 0;
    }
    if (total_sum == 0)
        return (0);
    else
        return (1);
}


void    run()
{
    int nr_cycle;
    int alive;
    int juc;
    int delta;
    long int total_sum;


    delta = 0;
    total_sum = 0;
    while (1)
    {
        nr_cycle = CYCLE_TO_DIE - delta;
        while (nr_cycle >= 0)
        {
            juc = 0;
            while (++juc <= 5)
            {
                if (g_arr[juc].filename == NULL || g_arr[juc].alive == 0)
                    continue;
                execute_proc(juc);
            }
            nr_cycle--;
            total_sum++;
            if (g_dump > 0 && total_sum >= g_dump)
                return;

        }

        alive = decrease_cycle(&delta);
        if (alive == 0)
        {
            if (g_winner == 0)
                ft_putstr("Nimeni nu a cistigat");
            else
            {
                ft_putstr("\t\t\tWINNER: \t\t");
                ft_putstr(g_arr[g_winner].name);
                ft_putstr("\n\n\n");
            }
            break;
        }
    }
}

int     ft_start()
{
    run();
    return (0);
}


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

void	print_black(int x, int y)
{
	int i;
	int j;

	i = -1;
	while(++i < 15)
	{
		j = -1;
		while(++j < 12)
			putpixel(x+i, y+j, BLACK);
	}
}

void	print_chars()
{
	int i;
	int j;
	int c[] = {0xa8a8a8, 0xff0000, 0x00ff00, 0x5060ff, 0xffff00};

	i = -1;

	while(++i < 54)
	{
		j = -1;
		while(++j < 74)
        {
            setcolor(c[g_color[i*74+j]]);
			outtextxy(j*17+10, i*13, ft_itoa_base(g_mem[i*74+j], 16));
        }
	}
}

void	print_square(int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while(++i < 20)
	{
		j = -1;
		while(++j < 16)
			putpixel(x+i, y+j, color);
	}
}

void	print_map(void)
{
    setcolor(0xff0000);
    rectangle(1290, 50, 1320, 80);
    setfillstyle(1, 0xff0000);
    floodfill(1295, 60, 0xff0000);
	setcolor(WHITE);
	outtextxy(1297, 58, "P1");

	 setcolor(0x00ff00);
    rectangle(1290, 100, 1320, 130);
    setfillstyle(1, 0x00ff00);
    floodfill(1295, 110, 0x00ff00);
	setcolor(WHITE);
	outtextxy(1297, 108, "P2");

    setcolor(0x5060ff);
    rectangle(1290, 150, 1320, 180);
    setfillstyle(1, 0x5060ff);
    floodfill(1295, 160, 0x5060ff);
	setcolor(WHITE);
	outtextxy(1297, 158, "P3");

    setcolor(0xffff00);
    rectangle(1290, 200, 1320, 230);
    setfillstyle(1, 0xffff00);
    floodfill(1295, 210, 0xffff00);
	setcolor(WHITE);
	outtextxy(1297, 208, "P4");
	/*
	mlx_string_put(mlx, win, 1650, 80, 0x00ff00, "PLAYER 2");
	print_square(1625, 82, 0x00ff00);
	mlx_string_put(mlx, win, 1650, 110, 0x5060ff, "PLAYER 3");
	print_square(1625, 112, 0x5060ff);
	mlx_string_put(mlx, win, 1650, 140, 0xffff00, "PLAYER 4");
	print_square(1625, 142, 0xffff00);
	*/
}

void    change_all(int a, int b, char *text, int color)
{

   int c[] = {0xa8a8a8, 0xff0000, 0x00ff00, 0x5060ff, 0xffff00};

   Sleep(5);
    print_black(10+a*17, 2+ b * 13);
    setcolor(c[g_color[b*74 + a]]);
    outtextxy(a*17+10, b*13, text);
}

int		main(int argc, char **argv)
{
	time_t  t;
	int8_t flag;
	int i;
	int8_t p_n;
	int8_t found;

	srand((unsigned) time(&t));
	initwindow(1360, 710);
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
	ft_bzero(g_mem, 4096);
	ft_check_players();
	insert_gamelife();
	load();
    print_map();
     print_chars();
     print_chars();
    ft_start();

    //print_black(10, 2);
     getch();
     //cleardevice();
      print_map();
     print_chars();
     getch();
}
