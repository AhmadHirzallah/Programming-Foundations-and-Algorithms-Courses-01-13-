#include <stdio.h>
#include <stdlib.h>

int	ft_validate_nbr_in_range(double entered_number, int from, int to);
void    *ft_p_v_malloc(int i_items_number, int i_item_size);
void	ft_print_age_result(int *i_age);
void	ft_read_age(int *i_age, short from, short to);

int	main(void)
{

	int	*i_age;
	int	from;
	int	to;

	printf("Please enter age range:\nFrom: ");
	scanf("%i", &from);
	printf("To: ");
	scanf("%i", &to);

	i_age = (int *)ft_p_v_malloc(1, sizeof(int));
	if (i_age == NULL)
		return (1);
	ft_read_age(i_age, from, to);
	ft_print_age_result(i_age);
	free(i_age);
	return (0);
}

void	ft_print_age_result(int *i_age)
{
	printf("The age is %i and it is Valid\n", *i_age);
}

void    *ft_p_v_malloc(int i_items_number, int i_item_size)
{
    void    *p_v;

    p_v = (void *)malloc(i_items_number * i_item_size);
    if (!p_v)
        return (NULL);

    return (p_v);
}

void	ft_read_age(int *i_age, short from, short to)
{
	printf("Please enter your age: ");
	scanf("%i", i_age);
	if (ft_validate_nbr_in_range(*i_age, from, to))
		return ;
	else 
	{
		printf("Invalid Age !!\n");
		ft_read_age(i_age, from, to);
	}
			
}

int	ft_validate_nbr_in_range(double entered_number, int from, int to)
{
	return (entered_number >= from && entered_number <= to);
}
