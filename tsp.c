/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:58:26 by wel-safa          #+#    #+#             */
/*   Updated: 2024/11/12 13:34:23 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : tsp
Expected files   : *.c *.h
Allowed functions and globals: write, sqrtf, getline, fabsf, memcpy, printf, 
malloc, calloc,realloc, free, errno, write

-----------------------------------------------------------------------------

The first publication referring to this problem as the 
"traveling salesman problem"
is found in the 1949 RAND Corporation report by Julia Robinson,
"On the Hamiltonian game (a traveling salesman problem)."

Here is how she defines the problem:

"The purpose of this note is to give a method for solving a problem related
to the traveling salesman problem. It seems worthwhile to give a description
of the original problem. One formulation is to find the shortest route for a
salesman starting from Washington, visiting all the state capitals and then
returning to Washington.
More generally, to find the shortest CLOSED CURVE
containing n given points in the plane."

For example with the following set of cities:
0, 0
1, 0
2, 0
0, 1
1, 1
2, 1
1, 2
2, 2

which can be represented as follows:
 +  +  +
 +  +  +
    +  +

the shortest path is:
  _____
 |__   |
    |__|

so you should print the length of this path that is:
8.00

Write a program that will read a set of city coordinates under the form
"%f, %f\n" from the standard input and will print the length of the shortest
possible path containing all these cities under the form "%.2f".

Your program will not be tested with more than 11 cities.

You will find in this directory a file tsp.c containing all the boring parts of
this exercise and example files to help you test your program.

hint: In order to use sqrtf, add -lm at the end of your compilation command.

For example this should work:
$> cat square.txt
1, 1
0, 1
1, 0
0, 0
$> ./tsp < square.txt | cat -e
4.00$
*/

