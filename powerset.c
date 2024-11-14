// Slightly better Version

#include <stdio.h>
#include <stdlib.h>

void check_print(int *subs, int size, int n)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += subs[i];
	if (sum == n)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(stdout, "%d", subs[i]);
			if (i < size - 1)
				fprintf(stdout, " ");
		}
		fprintf(stdout, "\n");
	}
}

int main(int ac, char **av)
{
	if (ac < 3)
		exit(1);
	int n = atoi(av[1]);
	int subsets = 1 << (ac - 2);

	for (int i = 0; i < subsets; i++)
	{
		int subs[ac - 2];
		int size = 0;

		for (int j = 0; j < ac - 2; j++)
		{
			if (1 & (i >> j))
				subs[size++] = atoi(av[j + 2]);
		}
		check_print(subs, size, n);
	}
	return (0);
}