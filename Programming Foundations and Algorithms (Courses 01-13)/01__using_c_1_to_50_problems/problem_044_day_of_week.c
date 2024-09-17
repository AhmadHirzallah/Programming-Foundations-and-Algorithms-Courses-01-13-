#include <stdio.h>
#include <stdlib.h>

typedef enum e_days
{
	sunday = 1,
	monday = 2,
	tuesday = 3,
	wednesday = 4,
	thursday = 5,
	friday = 6,
	saturday = 7
}	t_e_days;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_day_result(t_e_days    *p_e_day_is);
t_e_days	ft_e_read_day(t_e_days *p_e_day_is);


int	main(int argc, char	**argv)
{
	t_e_days	*p_e_day_is;
	short	entered_day;

	p_e_day_is = ft_malloc(1, sizeof(t_e_days));
	if (!p_e_day_is)
		return (1);
	*p_e_day_is = ft_e_read_day(p_e_day_is);
	ft_print_day_result(p_e_day_is);
	free(p_e_day_is);
	return (0);
}

void	ft_print_day_result(t_e_days    *p_e_day_is)
{
	if (*p_e_day_is == sunday)
		printf("\nYour day is: Sunday\n");
	else if (*p_e_day_is == monday)
		printf("\nYour day is: Monday\n");
	else if (*p_e_day_is == tuesday)
		printf("\nYour day is: Tuesday\n");
	else if (*p_e_day_is == wednesday)
		printf("\nYour day is: Wednesday\n");
	else if (*p_e_day_is == thursday)
		printf("\nYour day is: Thursday\n");
	else if (*p_e_day_is == saturday)
		printf("\nYour day is: Saturday\n");
	else if (*p_e_day_is == friday)
		printf("\nYour day is: Friday\n");
	else
		 printf("\nWrong else error.\n");
}

t_e_days	ft_e_read_day(t_e_days *p_e_day_is)
{
	unsigned short	entered_day;
	printf("Please enter day number \"1)Sunday, 2)Monday, 3)Tuesday, 4)Wednesday, 5)Thursday, 6)Friday, 7)Saturday\" :\n");
	scanf("%hu", &entered_day);
	while (entered_day < 1 || entered_day > 7)
	{
		printf("Wrong entered; please enter the number of the day again:\n");
		scanf("%hu", &entered_day);
	}
	*p_e_day_is = (t_e_days)entered_day;
	return (*p_e_day_is);
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
