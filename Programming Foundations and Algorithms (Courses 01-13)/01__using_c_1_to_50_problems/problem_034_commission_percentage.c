#include <stdio.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
float	ft_get_commission_percentage(float   *p_f_total_sales);

int	main(int argc, char **argv)
{
	float	*p_f_total_sales;
	float	*p_f_commision_perc;
	float	*p_f_total_commission;
	if (argc != 2)
	{
		printf("Please enter only the total sales; (1 argument after file name).\n");
		return (1);
	}
	p_f_total_sales = (float *)ft_malloc(1, sizeof(float));
	p_f_commision_perc	= (float *)ft_malloc(1, sizeof(float));
	p_f_total_commission	= (float *)ft_malloc(1, sizeof(float));
	if (!p_f_total_sales || !p_f_commision_perc || !p_f_total_commission)
		return (2);
	*p_f_total_sales = atof(argv[1]);
	*p_f_commision_perc = ft_get_commission_percentage(p_f_total_sales);
	*p_f_total_commission = *p_f_total_sales * *p_f_commision_perc;
	printf("Commision Percentage is: %.3f\nTotal Commission is: %.3f\n",  *p_f_commision_perc, *p_f_total_commission);
	free(p_f_total_sales);
	free(p_f_commision_perc);
	free(p_f_total_commission);
	return (0);
}

float	ft_get_commission_percentage(float   *p_f_total_sales)
{
	if (*p_f_total_sales > 1000000)
		return (0.01);
	else if (*p_f_total_sales > 500000 && *p_f_total_sales <= 1000000)
		return (0.02);
	else if (*p_f_total_sales > 100000 && *p_f_total_sales <= 500000)
		return (0.03);
	else if (*p_f_total_sales > 50000 && *p_f_total_sales <= 100000)
		return (0.05);
	else 
		return (0.00);
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
