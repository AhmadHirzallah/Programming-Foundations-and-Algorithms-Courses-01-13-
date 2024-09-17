#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_fill_array_with_fibonacci_series(int *array, short entered_nbr)
{
	short	c;

	if (entered_nbr == 0 || entered_nbr == 1)
	{
		array[1] = 1;
		array[0] = 1;
		return ;
	}
	ft_fill_array_with_fibonacci_series(array, entered_nbr - 1);
	array[entered_nbr] = array[entered_nbr - 1] + array[entered_nbr - 2];
}

void	ft_print_the_array_of_fibonacci_series(int *array, short entered_nbr)
{
	short	c;

	c = -1;
	while (++c < entered_nbr)
		printf("(%d) ", array[c]);
	printf("\n");
}

int	main(void)
{
	int	*fibonacci_matrix;
	short	entered_nbr_of_len;

	printf("Please enter the index of last element of fibonacci series: ");
	scanf("%hd", &entered_nbr_of_len);
	fibonacci_matrix = (int *)malloc((int) entered_nbr_of_len * sizeof(int));
	ft_fill_array_with_fibonacci_series(fibonacci_matrix, entered_nbr_of_len);
	ft_print_the_array_of_fibonacci_series(fibonacci_matrix, entered_nbr_of_len);
	free(fibonacci_matrix);
	return (0);
}
