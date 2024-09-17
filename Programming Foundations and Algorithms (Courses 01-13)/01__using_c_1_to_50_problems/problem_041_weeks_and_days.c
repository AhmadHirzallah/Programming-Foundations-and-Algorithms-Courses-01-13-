#include <stdio.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	*ft_read_positive_nbr(int *p_i_nbr_of_hours);
float	*ft_p_f_get_nbr_of_weeks(int *p_i_nbr_of_hours, float   *p_f_nbr_of_weeks);
float	*ft_p_f_get_nbr_of_days(int *p_i_nbr_of_hours, float   *p_f_nbr_of_days);
void	ft_print_result(char *message, float *result);

int	main(int argc, char **argv)
{
	int	*p_i_nbr_of_hours;
	float	*p_f_nbr_of_days;
	float	*p_f_nbr_of_weeks;

	p_i_nbr_of_hours = (int *)ft_malloc(1, sizeof(int));
	p_f_nbr_of_days = (float *)ft_malloc(1, sizeof(float));
	p_f_nbr_of_weeks = (float *)ft_malloc(1, sizeof(float));
	if (!p_i_nbr_of_hours || !p_f_nbr_of_days || !p_f_nbr_of_weeks)
		return (1);
	p_i_nbr_of_hours = ft_read_positive_nbr(p_i_nbr_of_hours);
	p_f_nbr_of_days = ft_p_f_get_nbr_of_days(p_i_nbr_of_hours, p_f_nbr_of_days);
	p_f_nbr_of_weeks = ft_p_f_get_nbr_of_weeks(p_i_nbr_of_hours, p_f_nbr_of_weeks);
	ft_print_result("The number of days is:", p_f_nbr_of_days);
	ft_print_result("The number of weeks is:", p_f_nbr_of_weeks);
	free(p_i_nbr_of_hours);	
	free(p_f_nbr_of_days);	
	free(p_f_nbr_of_weeks);	
	return(0);
}

void	ft_print_result(char *message, float *result)
{
	printf("\n%s\n----->>> (%.3f)\n", message, *result);
}

float	*ft_p_f_get_nbr_of_weeks(int *p_i_nbr_of_hours, float   *p_f_nbr_of_weeks)
{
	*p_f_nbr_of_weeks = (float)*p_i_nbr_of_hours / 24.0 / 7.0;
	return (p_f_nbr_of_weeks);
}

float	*ft_p_f_get_nbr_of_days(int *p_i_nbr_of_hours, float   *p_f_nbr_of_days)
{
	*p_f_nbr_of_days = *p_i_nbr_of_hours / 24.0;
	return (p_f_nbr_of_days);
}

int	*ft_read_positive_nbr(int *p_i_nbr_of_hours)
{
	*p_i_nbr_of_hours = -1;
	printf("Please enter a positive number:\n");
	while (*p_i_nbr_of_hours <= 0)
		scanf("%i", p_i_nbr_of_hours);
	return (p_i_nbr_of_hours);
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
