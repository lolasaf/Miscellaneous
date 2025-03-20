/*
Assignment name  : permutations
Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write
---------------------------------------------------------------

Write a program that will print all the permutations of a string given as argument.

The solutions must be given in alphabetical order.

We will not try your program with strings containing duplicates (eg: 'abccd').

For example this should work:

$> ./permutations a | cat -e
a$

$> ./permutations ab | cat -e
ab$
ba$

$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$
*/

#include <stdio.h>
#include <stdlib.h>

void swap(char *str, int i, int j)
{
	char c = (str)[i];
	(str)[i] = (str)[j];
	(str)[j] = c;
}

void firstswap(char *str, int i, int j)
{
	char tmp;

	if (i > j)
		swap(str, i, j);
	else
	{
		while (j > i)
		{
			tmp = str[j];
			str[j] = str[j - 1];
			str[j - 1] = tmp;
			j--;
		}
	}
}

void secondswap(char *str, int i, int j)
{
	char tmp;

	if (i > j)
		swap(str, i, j);
	else
	{
		while (j > i)
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i++;
		}
	}
}

void permutations(char *str, int start, int end)
{
	if (!str)
		return ;
	if (!(*str))
		return ;
	if (start == end)
	{
		// print permutation & RETURN
		puts(str);
		return ;
	}
	for (int i = start; i <= end; i++)
	{
		firstswap(str, start, i); 

		permutations(str, start + 1, end);

		secondswap(str, start, i);
	}
}

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

void sortstring(char *str) // BUBBLE SORT
{
	if (!str) return;
	int len = ft_strlen(str);
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (str[j] > str[j + 1])
			{
				char temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int len = ft_strlen(av[1]);
	sortstring(av[1]);
	permutations(av[1], 0, len - 1);
}
