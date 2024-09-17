#include <stdio.h>
#include <stdlib.h>

void	ft_read_2numbers(float *p_f_1, float *p_f_2);
void	ft_print_numbers(float *p_f_1, float *p_f_2);
void	ft_swap_2numbers(float *p_f_1, float *p_f_2);

int	main(void)
{
	float	*p_f_1;
	float	*p_f_2;

	p_f_1 = (float *)malloc(sizeof(float));
	p_f_2 = (float *)malloc(sizeof(float));
	if (p_f_1 == NULL || p_f_2 == NULL)
	{
		printf("ERROR! Memory Allocation Failed\n");
		return (1);
	}
	ft_read_2numbers(p_f_1, p_f_2);
	ft_print_numbers(p_f_1, p_f_2);
	ft_swap_2numbers(p_f_1, p_f_2);
	ft_print_numbers(p_f_1, p_f_2);
	free (p_f_1);
	free (p_f_2);
}

void	ft_read_2numbers(float *p_f_1, float *p_f_2)
{
	printf("Please enter the 1'st number: ");
	scanf("%f", p_f_1);
	printf("Please enter the 2'nd number: ");
	scanf("%f", p_f_2);
}

void	ft_swap_2numbers(float *p_f_1, float *p_f_2)
{
	float	f_tmp;

	f_tmp = *p_f_1;
	*p_f_1 = *p_f_2;
	*p_f_2 = f_tmp;
}

void	ft_print_numbers(float *p_f_1, float *p_f_2)
{
	printf("\n\nThe first number is: %.*f", 2, *p_f_1);
	printf("\nThe second number is: %.*f\n", 2, *p_f_2);
}
