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
			array[c1][c2] = ft_generate_random_nbr_in_range(1, 10);
	}
}

int	ft_get_sum_of_matrix_numbers(int **p_2d_array)
{
	int	sum;
	short	c1;
	short	c2;

	c1 = -1;
	sum = 0;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			sum += p_2d_array[c1][c2];
	}
	return (sum);
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

int	main(void)
{
	int	**p_2d_array;
	short	c;

	srand((unsigned)time(NULL));
	p_2d_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	ft_print_2d_array(p_2d_array);
	printf("\nThe sum of array numbers: (%d)\n", ft_get_sum_of_matrix_numbers(p_2d_array));
	free(p_2d_array);
	return (0);
}

