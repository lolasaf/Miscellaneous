/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:15:49 by wel-safa          #+#    #+#             */
/*   Updated: 2024/11/12 21:05:32 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void check_print(int n, char **av, int *subsets, int subset_size)
{
	int sum = 0;
	for (int i = 0; i < subset_size; i++) {
		sum += atoi(av[subsets[i]]);
	}
	if (sum == n) {
		for (int i = 0; i < subset_size; i++) {
			fprintf(stdout, "%s", av[subsets[i]]);
			if (i != subset_size - 1)
				fprintf(stdout, " ");
		}
		fprintf(stdout, "\n");
	}
}

int	main(int ac, char **av)
{
	if (ac < 3)
		exit(1);
	int n = atoi(av[1]);
	int total_subsets = 1 << (ac - 2); // calculate num of subsets 2^(ac-2)
	
	for (int i = 1; i < total_subsets; i++) {
		int subsets[ac - 2];
		int subset_size = 0;

		for (int j = 0; j < (ac - 2); j++) {
			if (i & (1 << j)) {
				// include j-th element of set av[2] to av[n]
				subsets[subset_size++] = j + 2;
			}
		}
		check_print(n, av, subsets, subset_size);
	}
}
