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
			array[c1][c2] = ft_generate_random_nbr_in_range(0, 1);
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

void	ft_initialize_identity_matrix(int **array, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                array[i][j] = 1; // Diagonal elements are 1
            } else {
                array[i][j] = 0; // Non-diagonal elements are 0
            }
        }
    }
}

short	ft_check_is_identity_matrices(int **p_2d_array)
{
	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < 3)
		if (p_2d_array[c1][c1] != 1)
			return (0);
	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if ((p_2d_array[c1][c2] != 0) && (c1 != c2))
					return (0);
	}
	return (1);
}

void	ft_print_is_array_identity_result(short result)
{
	if (result)
		printf("\n\nYes.\nThe array is identity.\n\n");
	else
		printf("\n\nNo.\nThe array is not identity.\n\n");
}

int	main(void)
{
	int	**p_2d_array;
	short	check_is_array_identity;
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
	check_is_array_identity	= ft_check_is_identity_matrices(p_2d_array);
	ft_print_is_array_identity_result(check_is_array_identity);
	printf("The array filled with identity rules:\n");
	ft_initialize_identity_matrix(p_2d_array, 3);
	ft_print_2d_array(p_2d_array);
	check_is_array_identity	= ft_check_is_identity_matrices(p_2d_array);
	ft_print_is_array_identity_result(check_is_array_identity);
	free(p_2d_array);
	return (0);
}
