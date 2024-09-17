#include <stdio.h>
#include <stdlib.h>

typedef enum t_e_pass_fail
{
	pass = 1,
	fail
} t_e_pass_fail;

void    ft_print_average_result(float f_average);
void    ft_read3numbers(float *p_f_num1, float *p_f_num2, float *p_f_num3);
float   ft_calculate_avg_of_3numbers(float *p_f_num1, float *p_f_num2, float *p_f_num3);

int main(void)
{
    float   *p_f_num1;
    float   *p_f_num2;
    float   *p_f_num3;

    p_f_num1 = (float *)malloc(sizeof(float));
    p_f_num2 = (float *)malloc(sizeof(float));
    p_f_num3 = (float *)malloc(sizeof(float));
    ft_read3numbers(p_f_num1, p_f_num2, p_f_num3);
    ft_print_average_result(ft_calculate_avg_of_3numbers(p_f_num1, p_f_num2, p_f_num3));
}

void    ft_read3numbers(float *p_f_num1, float *p_f_num2, float *p_f_num3)
{
    printf("Please enter the 1'st number: ");
    scanf("%f", p_f_num1);
    printf("Please enter the 2'nd number: ");
    scanf("%f", p_f_num2);
    printf("Please enter the 3'rd number: ");
    scanf("%f", p_f_num3);
}

float   ft_calculate_avg_of_3numbers(float *p_f_num1, float *p_f_num2, float *p_f_num3){
    return ((*p_f_num1 + *p_f_num2 + *p_f_num3) / 3.0);
}

t_e_pass_fail	ft_check_average(float f_avg)
{
	if (f_avg >= 50)
		return (pass);
	else
		return (fail);
}

void    ft_print_average_result(float f_average)
{
    printf("\nThe average is: %.*f\n", 2, f_average);
	if (ft_check_average(f_average) == pass)
		printf("Congratulations; you passed!\n");
	else
		printf("Unfortunately; you failed!\n");

}
