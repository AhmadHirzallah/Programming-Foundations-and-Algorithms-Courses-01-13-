#include <stdio.h>
#include <stdlib.h>

void	ft_read_2numbers(float *p_f_nbr1, float *p_f_nbr2);
float	*ft_get_max_of2numbers(float *p_f_nbr1, float *p_f_nbr2);
void	ft_print_max_number_result(float	*p_f_result);

int	main (void)
{
	float	*p_f_number1;
	float	*p_f_number2;

	p_f_number1 = (float *)malloc(sizeof(float));
	p_f_number2 = (float *)malloc(sizeof(float));
	if (p_f_number1 == NULL || p_f_number2 == NULL)
	{
		printf("Memory Allocation Failed !!!");
		return (1);
	}
	ft_read_2numbers(p_f_number1, p_f_number2);
	ft_print_max_number_result(ft_get_max_of2numbers(p_f_number1, p_f_number2));
	free(p_f_number1);
	free(p_f_number2);
	return (0);
}

void	ft_print_max_number_result(float	*p_f_result)
{
	printf("The maximum number is: %.*f\n", 3, *p_f_result);
}

void	ft_read_2numbers(float *p_f_nbr1, float *p_f_nbr2)
{
		printf("Please enter the 1'st number: ");
		scanf("%f", p_f_nbr1);
		printf("Please enter the 2'nd number: ");
		scanf("%f", p_f_nbr2);
}

float	*ft_get_max_of2numbers(float *p_f_nbr1, float *p_f_nbr2)
{
	if (*p_f_nbr1 > *p_f_nbr2)
		return (p_f_nbr1);
	else
		return (p_f_nbr2);
}
