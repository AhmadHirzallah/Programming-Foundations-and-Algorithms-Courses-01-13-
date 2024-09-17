#include <stdio.h>
#include <stdlib.h>

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

float   ft_calculate_avg_of_3numbers(float *p_f_num1, float *p_f_num2, float *p_f_num3)
{
    return ((*p_f_num1 + *p_f_num2 + *p_f_num3) / 3.0);
}

void    ft_print_average_result(float f_average)
{
    printf("\nThe average is: %.*f\n", 2, f_average);
} 
