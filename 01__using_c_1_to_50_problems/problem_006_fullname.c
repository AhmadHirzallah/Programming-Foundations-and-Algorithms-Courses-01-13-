#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct	t_s_fullname
{
	char	*p_firstname;
	char	*p_lastname;
}	t_s_fullname;


t_s_fullname ft_read_fullname(t_s_fullname *p_fullname);
char	*ft_p_get_fullname(t_s_fullname *p_s_fullname);

int	main(void)
{
	t_s_fullname *p_s_fullname;
	char	*p_fullname;
	p_s_fullname = (t_s_fullname *)malloc(sizeof(t_s_fullname));
	if (p_s_fullname == NULL)
	{
			printf("Memory allocation failed\n");
			return (1);
	}
	p_s_fullname->p_firstname = (char *)malloc(20 * sizeof(char));
	p_s_fullname->p_lastname = (char *)malloc(20 * sizeof(char));
	if (p_s_fullname->p_firstname == NULL || p_s_fullname->p_lastname == NULL)
	{
		printf("Memory allocation failed\n");
		free(p_s_fullname);
		return (1);
	}
	ft_read_fullname(p_s_fullname);
	p_fullname = ft_p_get_fullname(p_s_fullname);
	printf("Full name is: %s\n", p_fullname);
	free(p_fullname);
	free(p_s_fullname->p_firstname);
	free(p_s_fullname->p_lastname);
	free(p_s_fullname);

	return (0);
}


t_s_fullname ft_read_fullname(t_s_fullname *p_fullname)
{
	printf("Please enter your first name: ");
	scanf("%19s", p_fullname->p_firstname);
	printf("Please enter your last name: ");
	scanf("%19s", p_fullname->p_lastname);
	return (*p_fullname);
}

char	*ft_p_get_fullname(t_s_fullname *p_s_fullname)
{
	char	*p_fullname;
	short	length;

	length = strlen(p_s_fullname->p_firstname) + strlen(p_s_fullname->p_lastname) + 2;
	p_fullname = (char *)malloc(length * sizeof(char));
	if (p_s_fullname == NULL)
	{
		printf("Memory allocation failed.\n");
		return (NULL);
	}
	strcpy(p_fullname, p_s_fullname->p_firstname);
	strcat(p_fullname, " ");
	strcat(p_fullname, p_s_fullname->p_lastname);

	return (p_fullname);
}
