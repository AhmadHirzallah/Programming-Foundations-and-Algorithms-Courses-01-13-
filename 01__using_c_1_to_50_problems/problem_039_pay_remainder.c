#include <stdio.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
float	*ft_p_f_read_number(char *message, float *p_f_nbr);
float	*ft_p_f_get_remainder(float *p_f_total_bill, float *p_f_cash_paid, float   *p_f_remainder);
void	ft_print_result(float   *p_f_remainder);

int	main (void)
{
	float	*p_f_total_bill;
	float	*p_f_cash_paid;
	float	*p_f_remainder;

	p_f_total_bill = (float *)ft_malloc(1, sizeof(float));
	p_f_cash_paid = (float *)ft_malloc(1, sizeof(float));
	p_f_remainder = (float *)ft_malloc(1, sizeof(float));
	if (!p_f_total_bill || !p_f_cash_paid || !p_f_remainder)
		return (1);
	p_f_total_bill = ft_p_f_read_number("Please enter the total bill:", p_f_total_bill);
	p_f_cash_paid =	ft_p_f_read_number("Please enter the cash that you paid:", p_f_cash_paid);
	p_f_remainder = ft_p_f_get_remainder(p_f_total_bill, p_f_cash_paid, p_f_remainder);
	ft_print_result(p_f_remainder);
	free(p_f_total_bill);
	free(p_f_cash_paid);
	free(p_f_remainder);
	return (0);
}

void	ft_print_result(float   *p_f_remainder)
{
	if (*p_f_remainder >= 0)
		printf("You have to pay: %.3f$\n", *p_f_remainder);
	else if (*p_f_remainder < 0)
		printf("You will have back: %.3f$\n", (-1 * (*p_f_remainder)));
}

float	*ft_p_f_get_remainder(float *p_f_total_bill, float *p_f_cash_paid, float   *p_f_remainder)
{
	*p_f_remainder = *p_f_total_bill - *p_f_cash_paid;
	return (p_f_remainder);
}

float	*ft_p_f_read_number(char *message, float *p_f_nbr)
{
	printf("%s\n", message);
	scanf("%f", p_f_nbr);
	return (p_f_nbr);
}


void    *ft_malloc(int i_number_of_elements, int i_element_size)
{
    void    *p_v;

    p_v = (void *)malloc(i_number_of_elements * i_element_size);
    if (!p_v)
    {
        printf("Unfortunatelly; Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}
