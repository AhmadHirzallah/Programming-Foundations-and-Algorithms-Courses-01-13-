#include <stdio.h>
#include <stdlib.h>

void	*ft_p_v_malloc(int	i_elements_count, int i_element_size);
void	ft_print_factorial_result(int	*p_i_factorial, char* message);
int	*ft_p_i_caclulate_factorial(int *p_i_entered_nbr);

int	main(int argc, char **argv)
{
	int	*p_i_entered_nbr;
	int *p_i_factorial;

	p_i_entered_nbr = (int *)ft_p_v_malloc(1, sizeof(int));
	if (!p_i_entered_nbr)
		return (1);
	if (argc != 3)
	{
		printf("Please enter the number then enter the message that you want before displaying the result and Thanks :) \n");
		return (2);
	}
	*p_i_entered_nbr = atoi(argv[1]);
	p_i_factorial = ft_p_i_caclulate_factorial(p_i_entered_nbr);
	ft_print_factorial_result(p_i_factorial, argv[2]);
	free(p_i_entered_nbr);
	free(p_i_factorial);

	return (0);
}

void	ft_print_factorial_result(int	*p_i_factorial, char* message)
{
	printf("%s %i\n", message,*p_i_factorial);
}

int	*ft_p_i_caclulate_factorial(int *p_i_entered_nbr)
{
	int	*p_i_factorial;

	p_i_factorial = (int *)ft_p_v_malloc(1, sizeof(int));
	if (!p_i_factorial)
		return (NULL);
	*p_i_factorial = 1;
	while (*p_i_entered_nbr != 1)
	{
		*p_i_factorial *= (*p_i_entered_nbr);
		(*p_i_entered_nbr)--;
	}
	return (p_i_factorial);
}

void	*ft_p_v_malloc(int	i_elements_count, int i_element_size)
{
	void	*p_v;

	p_v = (void *)malloc(i_elements_count * i_element_size);
	if (!p_v)
	{
		printf("Memory Allocation Failed.\n");
		return (NULL);
	}
	return (p_v);
}
