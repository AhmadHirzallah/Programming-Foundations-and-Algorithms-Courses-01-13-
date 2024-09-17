/*Ask user to enter his Age and Driver License; Then print Hired if his age is greater than 21 and he has a driver license; otherwise Print Rejected*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct t_s_driver_info
{
	int	i_age;
	bool	b_has_driving_license;
}	t_s_driver_info;

t_s_driver_info	ft_read_driver_info();
bool	ft_is_accepted(t_s_driver_info info);
void	ft_get_and_print_hiring_result(t_s_driver_info info);

int	main (void)
{
	ft_get_and_print_hiring_result(ft_read_driver_info());
	return (0);
}

t_s_driver_info	ft_read_driver_info()
{
	t_s_driver_info	info;
	int	i_has_license;


	printf("Please enter your age: ");
	scanf("%d", &info.i_age);
	printf("Please tell if you have a license: ((0 for No)/(Any non-zero number for Yes)): ");
	scanf("%d", &i_has_license);
	info.b_has_driving_license = (bool)i_has_license;
	return (info);
}


bool	ft_is_accepted(t_s_driver_info info)
{
	return (info.i_age > 21 && info.b_has_driving_license);
}


void	ft_get_and_print_hiring_result(t_s_driver_info info)
{
	if (ft_is_accepted(info))
		printf("\nCongratulations, Hired\n");
	else
		printf("\nUnfortunately, Rejected\n");
}
