#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_grade_result(char    grade_symbol);
char	ft_get_grade_symbol(short *p_student_grade);

int	main(int argc, char **argv)
{
	short	*p_student_grade;
	char	grade_symbol;

	p_student_grade = (short *)ft_malloc(1, sizeof(short));
	if (!p_student_grade)
		return (1);
	*p_student_grade = (short)atoi(argv[1]);
	if (!isdigit(argv[1][0]))
    {
        printf("Error! Invalid input. Please enter a numeric value between 0 and 100.\n");
        return 2;
    }
	grade_symbol = ft_get_grade_symbol(p_student_grade);
	ft_print_grade_result(grade_symbol);
	return (0);
}

void	ft_print_grade_result(char    grade_symbol)
{
	if (grade_symbol == 'Z')
	{
		printf("Error! Wrong grade entered!\n");
		return ;
	}
	printf("The grade is: %c\n", grade_symbol);
}

char	ft_get_grade_symbol(short *p_student_grade)
{
	if (*p_student_grade >= 90 && *p_student_grade <= 100)
		return ('A');
	else if (*p_student_grade >= 80 && *p_student_grade <= 89)
		return ('B');
	else if (*p_student_grade >= 70 && *p_student_grade <= 79)
		return ('C');
	else if (*p_student_grade >= 60 && *p_student_grade <= 69)
		return ('D');
	else if (*p_student_grade >= 50 && *p_student_grade <= 59)
		return ('E');
	else if (*p_student_grade >= 0 && *p_student_grade <= 49)
		return ('F');
	else 
		return ('Z');
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
