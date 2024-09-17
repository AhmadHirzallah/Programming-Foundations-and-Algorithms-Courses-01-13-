#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
short	*ft_p_check_is_perfect_nbr(int	*p_i_entered_nbr);
void	ft_print_perfect_nbr_result(int  *p_i_entered_nbr);

int	main(int argc, char **argv)
{
	int	*p_i_entered_nbr;
	if (argc != 2)
	{
		printf("Please enter a one argument line command after file name; Which is the number you want to check.\n");
		return (1);
	}
	p_i_entered_nbr = (int *)ft_malloc(1, sizeof(int));
	if (!p_i_entered_nbr)
		return (2);
	*p_i_entered_nbr = atoi(argv[1]);
	ft_print_perfect_nbr_result(p_i_entered_nbr);
	free(p_i_entered_nbr);
	return (0);
}

void	ft_print_perfect_nbr_result(int  *p_i_entered_nbr)
{
	short *p_result;

	p_result = ft_p_check_is_perfect_nbr(p_i_entered_nbr);
	if (*p_result)
		printf("(%d) is a perfect number.\n", *p_i_entered_nbr);
	else if (!(*p_result))
		printf("(%d) ISN'T a perfect number.\n", *p_i_entered_nbr);
	free(p_result);
}

short	*ft_p_check_is_perfect_nbr(int	*p_i_entered_nbr)
{
	short	*p_result;
	int	i_sum;
	short	counter;

	p_result = (short *)ft_malloc(1, sizeof(short));
	if (!p_result)
		return (NULL);
	i_sum = 0;
	counter = 0;
	while (++counter < *p_i_entered_nbr)
	{
		if ((*p_i_entered_nbr) % counter == 0)
			i_sum += counter;
	}
	if ((*p_i_entered_nbr) == i_sum)
		*p_result = 1;
	else
		*p_result = 0;
	return (p_result);
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
