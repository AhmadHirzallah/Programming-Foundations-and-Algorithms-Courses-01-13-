#include <stdio.h>

typedef enum	e_pass_fail
{
	pass = 1,
	fail = 2
} e_pass_fail;

int	ft_read_mark();
e_pass_fail	ft_e_check_mark(int i_entered_mark);
void	ft_print_mark_result(int i_entered_mark);

int	main (void)
{
	ft_print_mark_result(ft_read_mark());
}

int	ft_read_mark()
{
	int	i_entered_mark;

	printf("Please enter your mark: ");
	scanf("%i", &i_entered_mark);
	return (i_entered_mark);
}

e_pass_fail	ft_e_check_mark(int i_entered_mark)
{
	if (i_entered_mark >= 50)
		return (pass);
	else
		return (fail);
}

void	ft_print_mark_result(int i_entered_mark)
{
	if (ft_e_check_mark(i_entered_mark) == pass)
		printf("Congratulations; you passed!\n");
	else if (ft_e_check_mark(i_entered_mark) == fail)
		printf("Unfortunately; you failed :(\n");
}
