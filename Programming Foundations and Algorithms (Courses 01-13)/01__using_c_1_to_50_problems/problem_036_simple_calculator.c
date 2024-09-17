#include <stdio.h>
#include <stdlib.h>

typedef struct	t_s_nbrs
{
	float	*p_f_nbr1;
	float	*p_f_nbr2;
}	t_s_nbrs;

typedef enum	t_e_operations
{
	addition = '+',
	subtraction = '-',
	multiplication = '*',
	division = '/'
}	t_e_operations;


void    *ft_malloc(int i_number_of_elements, int i_element_size);
t_s_nbrs	*ft_read_2nbrs(t_s_nbrs *p_s_nbrs);
t_e_operations	ft_e_read_operation();
float	*ft_calculation_result(t_e_operations *p_e_operations, t_s_nbrs *p_s_nbrs, float   *p_f_result);

int	main(void)
{
	t_e_operations *p_e_operations;
	t_s_nbrs *p_s_nbrs;
	float	*p_f_result;

	p_e_operations = (t_e_operations *)ft_malloc(1, sizeof(t_e_operations));
	p_s_nbrs = (t_s_nbrs *)ft_malloc(1, sizeof(t_s_nbrs));
	p_f_result = (float *)ft_malloc(1, sizeof(float));
	if (!p_e_operations || !p_s_nbrs || !p_f_result)
		return (1);
	p_s_nbrs = ft_read_2nbrs(p_s_nbrs);
	*p_e_operations = ft_e_read_operation();
	p_f_result = ft_calculation_result(p_e_operations, p_s_nbrs, p_f_result);
	printf("\nThe Result:\n\"%.2f  %c  %.2f  =  %.2f\"\n", *p_s_nbrs->p_f_nbr1, (char)*p_e_operations, *p_s_nbrs->p_f_nbr2, *p_f_result);
	free(p_e_operations);
	free(p_s_nbrs);
	free(p_s_nbrs->p_f_nbr1);
	free(p_s_nbrs->p_f_nbr2);
	free(p_f_result);
	return (0);
}

float	*ft_calculation_result(t_e_operations *p_e_operations, t_s_nbrs *p_s_nbrs, float   *p_f_result)
{
	if (*p_e_operations == addition)
		*p_f_result = *p_s_nbrs->p_f_nbr1 + *p_s_nbrs->p_f_nbr2;
	else if (*p_e_operations == subtraction)
		*p_f_result = *p_s_nbrs->p_f_nbr1 - *p_s_nbrs->p_f_nbr2;
	else if (*p_e_operations == multiplication)
		*p_f_result = *p_s_nbrs->p_f_nbr1 * *p_s_nbrs->p_f_nbr2;
	else if (*p_e_operations == division)
		*p_f_result = *p_s_nbrs->p_f_nbr1 / *p_s_nbrs->p_f_nbr2;
	else
		return (NULL);
}

t_s_nbrs	*ft_read_2nbrs(t_s_nbrs *p_s_nbrs)
{
	p_s_nbrs->p_f_nbr1 = (float *)ft_malloc(1, sizeof(float));
    p_s_nbrs->p_f_nbr2 = (float *)ft_malloc(1, sizeof(float));

    if (!p_s_nbrs->p_f_nbr1 || !p_s_nbrs->p_f_nbr2) 
		return (NULL);
	printf("Please enter the 1's Number:\n");
	scanf("%f", p_s_nbrs->p_f_nbr1);
	printf("Please enter the 2'nd Number:\n");
	scanf("%f", p_s_nbrs->p_f_nbr2);

	return (p_s_nbrs);
}

t_e_operations	ft_e_read_operation()
{
	char	c_operation;

	c_operation = '+';
	printf("Please enter the operation: ((** Avaiable Operations are: +, -, *, /)):\n");
	scanf("%s", &c_operation);
	return ((t_e_operations)c_operation);
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
