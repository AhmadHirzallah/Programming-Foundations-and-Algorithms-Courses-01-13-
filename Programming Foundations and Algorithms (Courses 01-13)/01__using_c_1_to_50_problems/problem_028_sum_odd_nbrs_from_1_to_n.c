#include <stdio.h>
#include <stdlib.h>

typedef enum t_e_odd_even
{
	odd,
	even
} t_e_odd_even;

void    *ft_p_v_malloc(int i_elements_number, int i_element_size);
t_e_odd_even ft_e_check_odd_or_even(int i_entered_n);
void	ft_print_odd_sum_result(int *p_i_odd_sum);
int	ft_p_sum_odd_nbrs_from_1_to_n(int i_entered_n);

int main(int argc, char **argv)
{
	int	*p_i_odd_sum;

    if (argc != 2)
    {
        printf("ERROOOOOOOOOOOOOOR !!\nEnter n value after file name (ONLY)\n");
        return (1);
    }
	p_i_odd_sum = (int *)ft_p_v_malloc(1, sizeof(int));
	if(!p_i_odd_sum)
		return (2);
	*p_i_odd_sum = ft_p_sum_odd_nbrs_from_1_to_n(atoi(argv[1]));
	ft_print_odd_sum_result(p_i_odd_sum);
	free(p_i_odd_sum);
	return (0);
}

void	ft_print_odd_sum_result(int *p_i_odd_sum)
{
	printf("The summation of the odd numbers is: %i\n", *p_i_odd_sum);
}

t_e_odd_even ft_e_check_odd_or_even(int i_entered_n)
{
	if (i_entered_n % 2 == 1)
		return (odd);
	else
		return (even);
}

int	ft_p_sum_odd_nbrs_from_1_to_n(int i_entered_n)
{
    int i_tmp;
	int	i_sum;

    i_tmp = 0;
	i_sum = 0;
    while (++i_tmp <= i_entered_n)
	{
		if (ft_e_check_odd_or_even(i_tmp) == odd)
			i_sum += i_tmp;
	}
	return (i_sum);

}
void    *ft_p_v_malloc(int i_elements_number, int i_element_size)
{
    void    *p_v;

    p_v = (void *)malloc(i_elements_number * i_element_size);
    if (p_v == NULL)
    {
        printf("ERROR! Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}
