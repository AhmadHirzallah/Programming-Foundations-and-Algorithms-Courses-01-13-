#include <unistd.h>
#include <stdio.h>
#include <string.h>

void    ft_print_name(int argc, char **argv)
{
	short	i;

	i = 1;
	write(STDOUT_FILENO, "Your name is: ", 14);
	while(i < argc)
	{
		write(STDOUT_FILENO, argv[i], strlen(argv[i]));
		write(STDOUT_FILENO, " ", 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
/*	printf("Your name is: ");
	while (i < argc)
	{
		printf("%s ", argv[i++]);
	}
	printf("\n");
	return ;
*/
}
int	main(int argc, char **argv)
{
 
	ft_print_name(argc, argv);
	return (0);
}
