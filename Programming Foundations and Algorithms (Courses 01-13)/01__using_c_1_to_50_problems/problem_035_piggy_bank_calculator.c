#include <stdio.h>
#include <stdlib.h>

typedef struct	t_s_piggy_bank_content
{
	int	*p_i_pennies;
	int	*p_i_nickels;
	int	*p_i_quarters;
	int	*p_i_dollars;
	int	*p_i_dimes;
}	t_s_piggy_bank_content;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
t_s_piggy_bank_content	*ft_p_read_piggy_bank_content(t_s_piggy_bank_content  *p_s_piggy_bank_contents);
float	*ft_p_f_get_total_pennies(t_s_piggy_bank_content  *p_s_piggy_bank_contents, float   *p_f_total_pennies);

int	main(void)
{
	float	*p_f_total_pennies;
	t_s_piggy_bank_content	*p_s_piggy_bank_contents;
	
	p_s_piggy_bank_contents = (t_s_piggy_bank_content *)ft_malloc(1, sizeof(t_s_piggy_bank_content));
	p_f_total_pennies = (float *)ft_malloc(1, sizeof(float));
	if (!p_s_piggy_bank_contents || !p_f_total_pennies)
		return (1);

	p_s_piggy_bank_contents = ft_p_read_piggy_bank_content(p_s_piggy_bank_contents);
    if (!p_s_piggy_bank_contents->p_i_pennies || !p_s_piggy_bank_contents->p_i_nickels ||
        !p_s_piggy_bank_contents->p_i_quarters || !p_s_piggy_bank_contents->p_i_dollars ||
        !p_s_piggy_bank_contents->p_i_dimes)
		return (2);
	p_f_total_pennies = ft_p_f_get_total_pennies(p_s_piggy_bank_contents, p_f_total_pennies);
	printf("\n~~~~~~~~~~~~~~~\nTotal Pennies = %.3f Pennies.\n", *p_f_total_pennies);
	printf("\n\nTotal Dollars = %.3f Dollars.\n", (*p_f_total_pennies / 100.0));
	free(p_f_total_pennies);
	free(p_s_piggy_bank_contents->p_i_pennies);
	free(p_s_piggy_bank_contents->p_i_nickels);
	free(p_s_piggy_bank_contents->p_i_dimes);
	free(p_s_piggy_bank_contents->p_i_quarters);
	free(p_s_piggy_bank_contents->p_i_dollars);
	free(p_s_piggy_bank_contents);
	return (0);
}

float	*ft_p_f_get_total_pennies(t_s_piggy_bank_content  *p_s_piggy_bank_contents, float   *p_f_total_pennies)
{
	*p_f_total_pennies = 0;
	*p_f_total_pennies += 1 * *(p_s_piggy_bank_contents->p_i_pennies);
	*p_f_total_pennies += 5 * *(p_s_piggy_bank_contents->p_i_nickels);
	*p_f_total_pennies += 25 * *(p_s_piggy_bank_contents->p_i_quarters);
	*p_f_total_pennies += 100 * *(p_s_piggy_bank_contents->p_i_dollars);
	*p_f_total_pennies += 10 * *(p_s_piggy_bank_contents->p_i_dimes);
	return (p_f_total_pennies);
}

t_s_piggy_bank_content	*ft_p_read_piggy_bank_content(t_s_piggy_bank_content  *p_s_piggy_bank_contents)
{
	p_s_piggy_bank_contents->p_i_pennies = (int *)ft_malloc(1, sizeof(int));
    p_s_piggy_bank_contents->p_i_nickels = (int *)ft_malloc(1, sizeof(int));
    p_s_piggy_bank_contents->p_i_quarters = (int *)ft_malloc(1, sizeof(int));
    p_s_piggy_bank_contents->p_i_dollars = (int *)ft_malloc(1, sizeof(int));
    p_s_piggy_bank_contents->p_i_dimes = (int *)ft_malloc(1, sizeof(int));
	printf("Please enter number of pennies: \n");
	scanf("%i", p_s_piggy_bank_contents->p_i_pennies);
	printf("Please enter number of nickels: \n");
	scanf("%i", p_s_piggy_bank_contents->p_i_nickels);
	printf("Please enter number of dimes: \n");
	scanf("%i", p_s_piggy_bank_contents->p_i_dimes);
	printf("Please enter number of quarters: \n");
	scanf("%i", p_s_piggy_bank_contents->p_i_quarters);
	printf("Please enter number of dollars: \n");
	scanf("%i", p_s_piggy_bank_contents->p_i_dollars);
	return (p_s_piggy_bank_contents);
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
