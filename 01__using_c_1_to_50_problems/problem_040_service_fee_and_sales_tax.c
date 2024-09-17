#include <stdio.h>
#include <stdlib.h>


const float	SERVICES_FREE = 1.1;
const float	SALES_TAX = 1.16;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_result(char *message, float *result);
float	*ft_calculate_total_bill(float   *p_f_bill_value, float   *p_f_total_bill);
float	*ft_p_f_read_positive_nbr(char *message, float *p_f_bill_value);

int	main(void)
{
	float	*p_f_bill_value;
	float	*p_f_total_bill;

	p_f_bill_value = (float *)ft_malloc(1, sizeof(float));
	p_f_total_bill = (float *)ft_malloc(1, sizeof(float));
	if (!p_f_bill_value || !p_f_total_bill)
		return (1);
	p_f_bill_value = ft_p_f_read_positive_nbr("Please enter the Bill value:", p_f_bill_value);
	p_f_total_bill = ft_calculate_total_bill(p_f_bill_value, p_f_total_bill);
	ft_print_result("The Total Bill result is:", p_f_total_bill);
	free(p_f_bill_value);
	free(p_f_total_bill);
	return (0);
}

void	ft_print_result(char *message, float *result)
{
	printf("%s\n-----> (%.3f)\n", message, *result);
}

float	*ft_calculate_total_bill(float   *p_f_bill_value, float   *p_f_total_bill)
{
	*p_f_total_bill = *p_f_bill_value;
	*p_f_total_bill = *p_f_total_bill * SERVICES_FREE;
	*p_f_total_bill = *p_f_total_bill * SALES_TAX;
	return (p_f_total_bill);
}

float	*ft_p_f_read_positive_nbr(char *message, float *p_f_bill_value)
{
	printf("%s\n", message);
	scanf("%f", p_f_bill_value);
	while (*p_f_bill_value <= 0)
		scanf("%f", p_f_bill_value);
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
