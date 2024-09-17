#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_print_name(char *p_name)
{
	//write(STDOUT_FILENO, "Your name is: ", 14);
	//write(STDOUT_FILENO, p_name, strlen(p_name));
	//write(STDOUT_FILENO, "\n", 1);
	printf("Your name is: %s\n", p_name);
}
int	main(int argc, char **argv)
{

	ft_print_name("Ahmad Omar");
	return (0);
}
