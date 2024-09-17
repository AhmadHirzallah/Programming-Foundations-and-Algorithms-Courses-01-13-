#include <stdio.h>

int	ft_read_number();
float	ft_calculate_half_number(int i_number);
void	ft_print_half_number_result(int i_number);

int	main(void)
{
	ft_print_half_number_result(ft_read_number());
}

int	ft_read_number()
{
	int	i_number;
	printf("Please enter a number: ");
	scanf("%i", &i_number);
	return (i_number);
}

float	ft_calculate_half_number(int i_number)
{
	return ((float)i_number / 2.0);
}

void	ft_print_half_number_result(int i_number)
{
	printf("Half of %i is: %f\n", i_number, ft_calculate_half_number(i_number));
}
