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

void	ft_multiply_2_matricies_into_third(int **p_2d_array, int **p_2d_array2, int **p_2d_multiply_array)
{
	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)	
			p_2d_multiply_array[c1][c2] = p_2d_array[c1][c2] * p_2d_array2[c1][c2];
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
				printf("%02d\t,", array[c1][c2]);
			else 
				printf("%02d\n", array[c1][c2]);
	}
	printf("\n");
}

int	main(void)
{
	srand((unsigned)time(NULL));

	int	**p_2d_array;
	int	**p_2d_array2;
	int	**p_2d_multiply_array;
	short	c;

	p_2d_array = (int **)malloc(3 * sizeof(int *));
	p_2d_array2 = (int **)malloc(3 * sizeof(int *));
	p_2d_multiply_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
	{
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
		p_2d_array2[c] = (int *)malloc(3 * sizeof(int));
		p_2d_multiply_array[c] = (int *)malloc(3 * sizeof(int));
	}
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	ft_fill_2d_array_with_random_nbrs(p_2d_array2);
	printf("1'st Array:\n");
	ft_print_2d_array(p_2d_array);
	printf("2'nd Array:\n");
	ft_print_2d_array(p_2d_array2);
	ft_multiply_2_matricies_into_third(p_2d_array, p_2d_array2, p_2d_multiply_array);
	printf("Multiplied Array:\n");
	ft_print_2d_array(p_2d_multiply_array);
	free(p_2d_array);
	free(p_2d_array2);
	free(p_2d_multiply_array);
	return (0);
}
