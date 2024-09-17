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
			array[c1][c2] = ft_generate_random_nbr_in_range(1, 100);
	}
}

int	*ft_get_middle_row_of_array(int **p_2d_array, int *row_or_column)
{
	short	c;

	c = -1;
	row_or_column = (int *)malloc(3 * sizeof(int));
	while (++c < 3)
		row_or_column[c] = p_2d_array[1][c];
	return (row_or_column);
}

int	*ft_get_middle_column_of_array(int **p_2d_array, int *row_or_column)
{
	short	c;

	c = -1;
	if (row_or_column == NULL)
		row_or_column = (int *)malloc(3 * sizeof(int));
	while (++c < 3)
		row_or_column[c] = p_2d_array[c][1];
	return (row_or_column);
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
				printf("%03d\t,", array[c1][c2]);
			else 
				printf("%03d\n", array[c1][c2]);
	}
	printf("\n");
}

void	ft_print_1d_array_of_middle_row_or_colums(int *row_or_column)
{
	short	c;

	c = -1;
	while (++c < 3)
		if (c != 2)
			printf("%03d\t,", row_or_column[c]);
		else
			printf("%03d\n", row_or_column[c]);

}

int	main(void)
{
	int	**p_2d_array;
	int	*row_or_column;
	short	c;

	srand((unsigned)time(NULL));
	p_2d_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	ft_print_2d_array(p_2d_array);
	printf("Get the middle row:\n");
	row_or_column = ft_get_middle_row_of_array(p_2d_array, row_or_column);
	ft_print_1d_array_of_middle_row_or_colums(row_or_column);
	printf("\nGet the middle Column:\n");
	row_or_column = ft_get_middle_column_of_array(p_2d_array, row_or_column);
	ft_print_1d_array_of_middle_row_or_colums(row_or_column);
	free(p_2d_array);
	free(row_or_column);
	return (0);
}
