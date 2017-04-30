#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../corewar.h"
#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50

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
    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)] = res >> 24 & 0xff;
    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 1] =  res >> 16 & 0xff;
    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 2] =  res >> 8 & 0xff;
    g_mem[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 3] =  res & 0xff;
    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD)] = juc;
    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 1] = juc;
    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 2] = juc;
    g_color[g_arr[juc].proc[procs].pc + (val3 % IDX_MOD) + 3] = juc;
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
        val1 = g_arr[juc].proc[procs].reg[instr.arg2 - 1];
        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD)] = g_arr[juc].proc[procs].reg[instr.arg1 -1] >> 24 & 0xff;
        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 1] =  g_arr[juc].proc[procs].reg[instr.arg1-1] >> 16 & 0xff;
        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 2] =  g_arr[juc].proc[procs].reg[instr.arg1-1] >> 8 & 0xff;
        g_mem[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 3] =  g_arr[juc].proc[procs].reg[instr.arg1-1] & 0xff;
        g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD)] = juc;
        g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 1] = juc;
        g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 2] = juc;
        g_color[g_arr[juc].proc[procs].pc + (val1 % IDX_MOD) + 3] = juc;
    }
    else
    {
        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] = g_arr[juc].proc[procs].reg[instr.arg1 -1] >> 24 & 0xff;
        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 1] =  g_arr[juc].proc[procs].reg[instr.arg1-1] >> 16 & 0xff;
        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 2] =  g_arr[juc].proc[procs].reg[instr.arg1-1] >> 8 & 0xff;
        g_mem[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 3] =  g_arr[juc].proc[procs].reg[instr.arg1-1] & 0xff;
        g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD)] = juc;
        g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 1] = juc;
        g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 2] = juc;
        g_color[g_arr[juc].proc[procs].pc + (instr.arg2 % IDX_MOD) + 3] = juc;
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
    while (1){
        nr_cycle = CYCLE_TO_DIE - delta;
        while (nr_cycle >= 0) {
            juc = 0;
            while (++juc <= 5) {
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
