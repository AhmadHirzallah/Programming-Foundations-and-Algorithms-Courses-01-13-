#include <stdio.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int *ft_p_get_power_result(int *i_entered_nbr,short chosen_power);
void    ft_print_pow_result(int *p_i_entered_number, short chosen_power,int *p_result);

int main(int argc, char **argv)
{
    int *p_i_entered_number;
    int   *p_result;
	short	chosen_power;

    if (argc != 3)
    {
        printf("Input error; please enter the number as 1's argument after filename and the power as 2'nd argument.\n");
        return (1);
    }
    p_i_entered_number = (int *)ft_malloc(1, sizeof(int));
    if (!p_i_entered_number)
        return (2);
    *p_i_entered_number = atoi(argv[1]);
    chosen_power = (short)atoi(argv[2]);
    p_result = ft_p_get_power_result(p_i_entered_number, chosen_power);
    ft_print_pow_result(p_i_entered_number, chosen_power, p_result);
    free(p_i_entered_number);
    free(p_result);
    return (0);
}

void    ft_print_pow_result(int *p_i_entered_number, short chosen_power,int *p_result)
{
    p_result = ft_p_get_power_result(p_i_entered_number, chosen_power);
    printf("The result of %i to the power %i is: (%i)\n", *p_i_entered_number, chosen_power, *p_result);
    free(p_result);
}

int *ft_p_get_power_result(int *i_entered_nbr,short chosen_power)
{
    short   *p_sh;
    int *p_result;

    p_result = (int *)ft_malloc(1, sizeof(int));
	if (!p_result)
		return (NULL);
	if (chosen_power == 0)
	{
		*p_result = 1;
		return (p_result);
	}
    p_sh = (short *)ft_malloc(1, sizeof(short));
	if (!p_sh)
		return (NULL);
    *p_sh = 0;
    *p_result = 1;
    while ((*p_sh)++ < chosen_power)
        *p_result *= *i_entered_nbr;
    free(p_sh);
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
