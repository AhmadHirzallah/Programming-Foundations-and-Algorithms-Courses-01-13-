#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct	s_time_categories
{
	int	*p_i_days;
	int	*p_i_hours;
	int	*p_i_minutes;
	int	*p_i_seconds;
	int	*p_i_entered_seconds;
}	t_s_time_categories;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	*ft_read_positive_nbr(char *message ,char *while_message, int *p_i_nbr);
void	ft_print_all_time_categories(t_s_time_categories *p_s_time_categories);
t_s_time_categories *ft_p_get_time_categories(t_s_time_categories *p_s_time_categories);
t_s_time_categories	*ft_alloc_all_and_read_seconds(t_s_time_categories *p_s_time_categories);

const int	SECONDS_PER_DAY = 24 * 60 * 60;
const int	SECONDS_PER_HOUR = 60 * 60;
const int	SECONDS_PER_MINUTE = 60;

int	main(int argc, char **argv)
{
	t_s_time_categories	*p_s_time_categories;

	p_s_time_categories = (t_s_time_categories *)ft_malloc(1, sizeof(t_s_time_categories));
	if (!p_s_time_categories)
		return (1);
	p_s_time_categories = ft_alloc_all_and_read_seconds(p_s_time_categories);
	p_s_time_categories = ft_p_get_time_categories(p_s_time_categories);
	ft_print_all_time_categories(p_s_time_categories);
	free(p_s_time_categories->p_i_entered_seconds);
	free(p_s_time_categories->p_i_seconds);
	free(p_s_time_categories->p_i_minutes);
	free(p_s_time_categories->p_i_hours);
	free(p_s_time_categories->p_i_days);
	free(p_s_time_categories);
	return(0);
}

void	ft_print_all_time_categories(t_s_time_categories *p_s_time_categories)
{
	printf("\n%02i:%02i:%02i:%02i\n", *p_s_time_categories->p_i_days, *p_s_time_categories->p_i_hours, *p_s_time_categories->p_i_minutes, *p_s_time_categories->p_i_seconds);
}

t_s_time_categories *ft_p_get_time_categories(t_s_time_categories *p_s_time_categories)
{
	int	i_remainder;

	*p_s_time_categories->p_i_days = floor(*p_s_time_categories->p_i_entered_seconds / SECONDS_PER_DAY);
	i_remainder = *p_s_time_categories->p_i_entered_seconds % SECONDS_PER_DAY;
	*p_s_time_categories->p_i_hours = floor(i_remainder / SECONDS_PER_HOUR);
	i_remainder %= SECONDS_PER_HOUR;
	*p_s_time_categories->p_i_minutes = floor(i_remainder / SECONDS_PER_MINUTE);
	i_remainder %= SECONDS_PER_MINUTE;
	*p_s_time_categories->p_i_seconds = i_remainder;
	return (p_s_time_categories);
}

t_s_time_categories	*ft_alloc_all_and_read_seconds(t_s_time_categories *p_s_time_categories)
{
	p_s_time_categories->p_i_days = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_hours = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_minutes = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_seconds = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_entered_seconds = (int *)ft_malloc(1, sizeof(int));
	p_s_time_categories->p_i_entered_seconds = ft_read_positive_nbr("Please enter a positive number:", "Enter the number of seconds", p_s_time_categories->p_i_entered_seconds);
	return (p_s_time_categories);
}

int	*ft_read_positive_nbr(char *message ,char *while_message, int *p_i_nbr)
{
	*p_i_nbr = -1;
		printf("\n%s\n", message);
	while (*p_i_nbr <= 0)
	{
		printf("%s\n", while_message);
		scanf("%i", p_i_nbr);
	}
	return (p_i_nbr);
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


