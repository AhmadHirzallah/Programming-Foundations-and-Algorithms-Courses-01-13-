#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_result(short *p_result, char *p_str_atm_pin);
short	*ft_p_check_pin(char *p_str_atm_pin, short *p_result);

int	main(int argc, char **argv)
{
	short *p_result;
	char *p_str_atm_pin;

	if(argc != 2)
	{
		printf("Please enter the PIN after file name.\n");
		return (1);
	}
	p_result = (short *)ft_malloc(1, sizeof(short));
	if (!p_str_atm_pin || !p_result)
		return (2);
	p_str_atm_pin = argv[1];
	p_result = ft_p_check_pin(p_str_atm_pin, p_result);
	ft_print_result(p_result, p_str_atm_pin);
	free(p_result);
	return (0);
}

void	ft_print_result(short *p_result, char *p_str_atm_pin)
{
	const float	C_BALANCE = 8000.8;

	if (*p_result)
	{
		printf("\nYour Balance is: (%.2f $)\n", C_BALANCE);
		return ;
	}
	while (!(*p_result))
	{
		printf("Wrong enter bin !\nTry again.\n");
		scanf("%s", p_str_atm_pin);
		p_result = ft_p_check_pin(p_str_atm_pin, p_result);
	}
	printf("\nYour Balance is: (%.2f $)\n", C_BALANCE);
}


short	*ft_p_check_pin(char *p_str_atm_pin, short *p_result)
{
	if (strcmp(p_str_atm_pin, "1234") == 0)
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


