#include <stdio.h>
#include <stdlib.h>

typedef struct	s_time_categories
{
	int	*p_i_days;
	int	*p_i_hours;
	int	*p_i_minutes;
	int	*p_i_seconds;
	float	*p_f_total_seconds;
}	t_s_time_categories;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
t_s_time_categories *ft_get_total_seconds(t_s_time_categories *p_s_time_categories);
int	*ft_read_positive_nbr(char *message ,char *while_message, int *p_i_nbr_of_hours);
void	ft_print_result(char *message, float *f_result);
t_s_time_categories	*ft_read_struct_data(t_s_time_categories *p_s_time_categories);

int	main(int argc, char **argv)
{
	t_s_time_categories	*p_s_time_categories;

	p_s_time_categories = (t_s_time_categories *)ft_malloc(1, sizeof(t_s_time_categories));
	if (!p_s_time_categories)
		return (1);
	p_s_time_categories = ft_read_struct_data(p_s_time_categories);
	p_s_time_categories = ft_get_total_seconds(p_s_time_categories);
	ft_print_result("The total seconds are:", p_s_time_categories->p_f_total_seconds);

	free(p_s_time_categories->p_f_total_seconds);
	free(p_s_time_categories->p_i_seconds);
	free(p_s_time_categories->p_i_minutes);
	free(p_s_time_categories->p_i_hours);
	free(p_s_time_categories->p_i_days);
	free(p_s_time_categories);
	return(0);
}

void	ft_print_result(char *message, float *f_result)
{
	printf("\n%s\n----->>> (%.2f)\n", message, *f_result);
}

t_s_time_categories *ft_get_total_seconds(t_s_time_categories *p_s_time_categories)
{
	*p_s_time_categories->p_f_total_seconds += *p_s_time_categories->p_i_seconds;
	*p_s_time_categories->p_f_total_seconds += 60 *  *p_s_time_categories->p_i_minutes;
	*p_s_time_categories->p_f_total_seconds += 60 * 60 * *p_s_time_categories->p_i_hours;
	*p_s_time_categories->p_f_total_seconds += 24 * 60 * 60 * *p_s_time_categories->p_i_days;
	return (p_s_time_categories);
}

t_s_time_categories	*ft_read_struct_data(t_s_time_categories *p_s_time_categories)
{
	p_s_time_categories->p_i_days = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_hours = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_minutes = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_seconds = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_f_total_seconds = (float *)ft_malloc(1, sizeof(float));
	*p_s_time_categories->p_f_total_seconds = 0.0;
	p_s_time_categories->p_i_days = ft_read_positive_nbr("\nPlease enter these fields:\n", "Enter the number of days:", p_s_time_categories->p_i_days);
	p_s_time_categories->p_i_hours = ft_read_positive_nbr("", "Enter the number of hours:", p_s_time_categories->p_i_hours);
	p_s_time_categories->p_i_minutes = ft_read_positive_nbr("", "Enter the number of minutes:", p_s_time_categories->p_i_minutes);
	p_s_time_categories->p_i_seconds = ft_read_positive_nbr("", "Enter the number of seconds:", p_s_time_categories->p_i_seconds);
	return (p_s_time_categories);
}

int	*ft_read_positive_nbr(char *message ,char *while_message, int *p_i_nbr_of_hours)
{
	*p_i_nbr_of_hours = -1;
		printf("\n%s\n", message);
	while (*p_i_nbr_of_hours <= 0)
	{
		printf("%s\n", while_message);
		scanf("%i", p_i_nbr_of_hours);
	}
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

