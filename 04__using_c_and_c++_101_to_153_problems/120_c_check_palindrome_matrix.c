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
			array[c1][c2] = ft_generate_random_nbr_in_range(0, 20);
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

void	ft_initialize_palindrome_matrix(int **array, int size) 
{
	short	side_nbr;

    for (int i = 0; i < size; ++i) 
	{
        for (int j = 0; j < size; ++j) 
		{
			side_nbr = ft_generate_random_nbr_in_range(1, 100);
            if (j == 0) 
				array[i][j] = side_nbr;
			else if (j == 2)
				array[i][j] =  array[i][0];
			else
				array[i][j] = ft_generate_random_nbr_in_range(1, 100);
        }
    }
}

short	ft_check_is_palindrome_matrix(int **p_2d_array, short size)
{
	short	is_palindrome_line;
	short	c1;
	short	c2;

	c2 = -1;
	c1 = -1;
	while (++c1 < size)
	{
		++c2;
			if (p_2d_array[c1][c2] != p_2d_array[c1][size - c2 - 1])	
				return (0);
	}
	return (1);
}

void	ft_print_is_palindrome_matrix(short result)
{
	if (result)
		printf("\n\nYes.\nThe array is palindrome matrix.\n\n");
	else
		printf("\n\nNo.\nThe array is not palindrome matrix.\n\n");
}

int	main(void)
{
	int	**p_2d_array;
	short	check_is_array_palindrome;
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
	check_is_array_palindrome = ft_check_is_palindrome_matrix(p_2d_array, 3);
	ft_print_is_palindrome_matrix(check_is_array_palindrome);
	printf("The array filled with scalar matrix rules:\n");
	ft_initialize_palindrome_matrix(p_2d_array, 3);
	ft_print_2d_array(p_2d_array);
	check_is_array_palindrome = ft_check_is_palindrome_matrix(p_2d_array, 3);
	ft_print_is_palindrome_matrix(check_is_array_palindrome);
	c = -1;
	while (++c < 3)
		free(p_2d_array[c]);
	free(p_2d_array);
	return (0);
}


