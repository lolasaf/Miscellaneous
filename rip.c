// Simpler Solution:
// This solution assumes input string contains only paranthesis, no spaces or anything else

/*
Assignment name: rip
Expected files: *.c *.h
Allowed functions: puts, write

Write a program that will take as argument a string containing only parenthesis.

If parenthesis are unbalanced (for example "(()") your program shall remove the minimum number of parenthesis for the expression to be balanced.

By removing we mean replacing by spaces.

You will print all the solutions (can be more than one).

The order of the solutions is not important.

For example this should work:

(For readability reasons the '_' means space and the spaces are for readability only.)

$> ./rip '( ( )' | cat -e
_ ( ) $
( _ ) $

$> ./rip '( ( ( ) ( ) ( ) ) ( ) )' | cat -e
( ( ( ) ( ) ( ) ) ( ) ) $

$> ./rip '( ) ( ) ) ( )' | cat -e
( ) ( ) _ ( ) $
( ) ( _ ) ( ) $
( _ ( ) ) ( ) $

$> ./rip '( ( ) ( ( ) (' | cat -e
( ( ) _ _ ) _ $
( _ ) ( _ ) _ $
( _ ) _ ( ) _ $
_ ( ) ( _ ) _ $
_ ( ) _ ( ) _ $
*/

#include <stdio.h>
#include <unistd.h>

int isbalance(char *s, int mask)
{
	int counter = 0;
	int removed = 0;

	int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
		{
			if (1 & (mask >> i))
				counter++;
			else
				removed++;
		}
		else if (s[i] == ')')
		{
			if (1 & (mask >> i))
				counter--;
			else
				removed++;
		}

		if (counter < 0) return (-1);
		i++;
	}
	if (counter) return (-1);
	return (removed);
}

int ft_strlen(char *s)
{
	int i = 0;
	if (!s) return (0);
	while (s[i]) i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int len = ft_strlen(av[1]);
	int full_mask = (1 << len) - 1;

	int removed = 0;
	for (int i = full_mask; i > 0; i--)
	{
		removed = isbalance(av[1], i);
		if (removed > -1)
			break;
	}
	if (removed == -1)
		return (1);
	else if (removed == 0)
	{
		puts("av[1]");
		return (0);
	}

	for (int i = full_mask; i > 0; i--)
	{
		if (isbalance(av[1], i) == removed)
		{
			int j = 0;
			while (av[1][j])
			{
				if (1 & (i >> j))
					write(1, &(av[1][j]), 1);
				else
					write (1, " ", 1);
				j++;
			}
			write(1, "\n", 1);
		}
	}
}