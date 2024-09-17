#include <stdio.h>
#include <stdlib.h>

typedef enum e_months_of_year
{
	jan = 1,
	feb = 2,
	march = 3,
	apr = 4,
	may = 5,
	june = 6,
	july = 7,
	aug = 8,
	sep = 9,
	oct = 10,
	nov = 11,
	dec = 12
}	t_e_months_of_year;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
t_e_months_of_year	ft_e_read_month(t_e_months_of_year  *p_e_month_is);
void	ft_print_month_result(t_e_months_of_year *p_e_month_is);


int	main(int argc, char	**argv)
{
	t_e_months_of_year	*p_e_month_is;
	short	entered_month;

	p_e_month_is = ft_malloc(1, sizeof(t_e_months_of_year));
	if (!p_e_month_is)
		return (1);
	*p_e_month_is = ft_e_read_month(p_e_month_is);
	ft_print_month_result(p_e_month_is);
	free(p_e_month_is);
	return (0);
}

void	ft_print_month_result(t_e_months_of_year *p_e_month_is)
{
	if (*p_e_month_is == jan)
		printf("\nYour month is: January\n");
	else if (*p_e_month_is == feb)
		printf("\nYour month is: February\n");
	else if (*p_e_month_is == march)
		printf("\nYour month is: March\n");
	else if (*p_e_month_is == apr)
		printf("\nYour month is: April\n");
	else if (*p_e_month_is == may)
		printf("\nYour month is: May\n");
	else if (*p_e_month_is == june)
		printf("\nYour month is: June\n");
	else if (*p_e_month_is == july)
		printf("\nYour month is: July\n");
	else if (*p_e_month_is == aug)
		printf("\nYour month is: August\n");
	else if (*p_e_month_is == sep)
		printf("\nYour month is: September\n");
	else if (*p_e_month_is == oct)
		printf("\nYour month is: October\n");
	else if (*p_e_month_is == nov)
		printf("\nYour month is: Novermber\n");
	else if (*p_e_month_is == dec)
		printf("\nYour month is: December\n");
	else
		printf("\nWrong else error.\n");
}

t_e_months_of_year	ft_e_read_month(t_e_months_of_year  *p_e_month_is)
{
	unsigned short	entered_month;
	printf("Please enter monther number\n\"1)January, 2)February, 3)March, 4)April, 5)May, 6)June, 7)July, 8)August, 9)September, 10)October, 11)November, 12)December\":\n");
	scanf("%hu", &entered_month);
	while (entered_month < 1 || entered_month > 12)
	{
		printf("Wrong entered; please enter the number of the month again:\n");
		scanf("%hu", &entered_month);
	}
	*p_e_month_is = (t_e_months_of_year)entered_month;
	return (*p_e_month_is);
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

