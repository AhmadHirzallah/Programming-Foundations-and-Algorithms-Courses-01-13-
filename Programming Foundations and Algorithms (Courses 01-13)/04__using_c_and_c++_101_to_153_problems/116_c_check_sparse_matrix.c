/*Sparce Matrix is a matrix in which the zero's elements count is more the other elements count*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	ft_generate_random_nbr_in_range(int from, int to)
{	
	int	i_generated_random_nbr;

	i_generated_random_nbr = rand() % (to - from + 1) + from;
	return (i_generated_random_nbr);
}

void	ft_fill_2d_array_with_random_nbrs(int **array)
{
	short	c1;
	short	c2;

	c1 = -1;
	c2 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)	
			array[c1][c2] = ft_generate_random_nbr_in_range(0, 2);
	}
}

void	ft_print_2d_array(int **array)
{
	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if (c2 != 2)
				printf("%d\t,", array[c1][c2]);
			else 
				printf("%d\n", array[c1][c2]);
	}
	printf("\n");
}

short	ft_check_is_sparse(int **p_2d_array)
{
	short	c1;
	short	c2;
	short	count_of_0s;

	count_of_0s = 0;
	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if (p_2d_array[c1][c2] == 0)
				count_of_0s++;
	}
	return (count_of_0s > (9 - count_of_0s));
}

void	ft_print_is_matrix_sparse(short result)
{
	if (result)
		printf("\n\nYes.\nThe matrix is sparse.\n\n");
	else
		printf("\n\nNo.\nThe matrix is not sparse.\n\n");
}

int	main(void)
{
	int	**p_2d_array;
	short	check_is_sparse_matrix;
	short	c;

	srand((unsigned)time(NULL));
	p_2d_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
	{
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	}
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	printf("The array:\n");
	ft_print_2d_array(p_2d_array);
	check_is_sparse_matrix	= ft_check_is_sparse(p_2d_array);
	ft_print_is_matrix_sparse(check_is_sparse_matrix);
	free(p_2d_array);
	return (0);
}

