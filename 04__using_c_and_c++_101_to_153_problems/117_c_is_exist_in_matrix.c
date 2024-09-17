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

int	ft_i_read_nbr(char *speak)
{
	int	i_entered_nbr;

	printf("%s", speak);
	scanf("%d", &i_entered_nbr);
	return (i_entered_nbr);
}

short	ft_check_is_nbr_in_array(int **array, short searched_nbr)
{
	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if (array[c1][c2] == searched_nbr)
				return (1);
	}
	return (0);
}

void	ft_print_searching_nbr_result(short result)
{
	if (result)
		printf("\nThe Number is exist in the matrix.\n");
	else
		printf("\nThe Number isn't exist in the matrix.\n");
}

int	main(void)
{
	int	**p_2d_array;
	short	nbr_wanted_to_check;
	short	is_nbr_found;
	short	c;

	srand((unsigned)time(NULL));
	p_2d_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	printf("The array:\n");
	ft_print_2d_array(p_2d_array);
	nbr_wanted_to_check = (short)ft_i_read_nbr("Please enter the number that you want to check: ");
	is_nbr_found = ft_check_is_nbr_in_array(p_2d_array, nbr_wanted_to_check);
	ft_print_searching_nbr_result(is_nbr_found);
	c = -1;
	while (++c < 3)
		free(p_2d_array[c]);
	free(p_2d_array);
	return (0);
}


