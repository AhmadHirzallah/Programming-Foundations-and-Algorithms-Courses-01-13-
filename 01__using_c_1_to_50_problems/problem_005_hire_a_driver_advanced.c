 /*Ask user to enter his Age and Driver License; Then print Hired if his age is greater than 21 and he has a driver license; But if he has a connection he will be Hired immedietly;  otherwise Print Rejected*/
#include <stdlib.h>
#include <stdio.h>

typedef struct t_s_driver_info
{
	unsigned short	age;
	short	has_driving_licens;
	short	has_recommendation;
}	t_s_driver_info;

t_s_driver_info ft_read_driver_info();
short	ft_is_hired(t_s_driver_info info);
void	ft_print_hiring_result(short result);

int	main(void)
{
	t_s_driver_info info;

	info = ft_read_driver_info();
	ft_print_hiring_result(ft_is_hired(info));	
}

t_s_driver_info ft_read_driver_info()
{
	t_s_driver_info	info;
	int	i_has_license;

	printf("Please enter your age: ");
	scanf("%hu", &info.age);
	printf("Please tell if you have a license (enter 0 if (No) and any other number for (Yes)): ");
	scanf("%hi", &info.has_driving_licens);
	printf("Please enter if this person has a recommendation (enter 0 if (No) and any other number for (Yes)): ");
	scanf("%hi", &info.has_recommendation);
	return (info);
}

short	ft_is_hired(t_s_driver_info info)
{
	if (info.has_recommendation)
		return (1);
	else
		return (info.age > 21 && info.has_driving_licens);
}

void	ft_print_hiring_result(short result)
{
	if(result)
		printf("Congratulations; you are hired\n");
	else
		printf("Sorry; you are rejected\n");
}
