#include <stdlib.h>
#include <stdio.h>

typedef struct s_loan_payment
{
	int	*p_nbr_of_months;
	float	*p_f_loan_amount;
	float	*p_f_monthly_payment;
}	t_s_loan_payment;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
t_s_loan_payment	*ft_read_loan_amount__and__monthly_payment(t_s_loan_payment    *p_s_about_loan);
t_s_loan_payment	*ft_p_get_months_to_settle_loan(t_s_loan_payment    *p_s_about_loan);
void	ft_print_result(t_s_loan_payment    *p_s_about_loan);
float	*ft_read_positive_nbr(char *tell ,float	*p_entered_nbr);

int	main(void)
{
	t_s_loan_payment	*p_s_about_loan;

	p_s_about_loan = (t_s_loan_payment *)ft_malloc(1, sizeof(t_s_loan_payment));
	if (!p_s_about_loan)
		return (1);
	p_s_about_loan = ft_read_loan_amount__and__monthly_payment(p_s_about_loan);
	p_s_about_loan = ft_p_get_months_to_settle_loan(p_s_about_loan);
	ft_print_result(p_s_about_loan);
	free(p_s_about_loan);
	free(p_s_about_loan->p_nbr_of_months);
	free(p_s_about_loan->p_f_loan_amount);
	free(p_s_about_loan->p_f_monthly_payment);
	return (0);
}

void	ft_print_result(t_s_loan_payment    *p_s_about_loan)
{
	printf("\nThe Number of months to settle the Loan (%.3f $)  with (%.3f $) Monthly Payments is : (%02i Months)\n", *(p_s_about_loan->p_f_loan_amount), *(p_s_about_loan->p_f_monthly_payment), *(p_s_about_loan->p_nbr_of_months));
}

t_s_loan_payment	*ft_read_loan_amount__and__monthly_payment(t_s_loan_payment    *p_s_about_loan)
{
	p_s_about_loan->p_nbr_of_months = (int *)ft_malloc(1, sizeof(int));
	p_s_about_loan->p_f_loan_amount = (float *)ft_malloc(1, sizeof(float));
	p_s_about_loan->p_f_monthly_payment = (float *)ft_malloc(1, sizeof(float));
	if (!p_s_about_loan->p_nbr_of_months || !p_s_about_loan->p_f_loan_amount ||  !p_s_about_loan->p_f_monthly_payment)
		return (NULL);
	(p_s_about_loan->p_f_loan_amount) = ft_read_positive_nbr("Enter the loan amount:", p_s_about_loan->p_f_loan_amount);
	(p_s_about_loan->p_f_monthly_payment) = ft_read_positive_nbr("Enter the monthly payment amount:", p_s_about_loan->p_f_monthly_payment);
	return (p_s_about_loan);
}

t_s_loan_payment	*ft_p_get_months_to_settle_loan(t_s_loan_payment    *p_s_about_loan)
{
	*(p_s_about_loan->p_nbr_of_months) = (*(p_s_about_loan->p_f_loan_amount) / *(p_s_about_loan->p_f_monthly_payment));
	return (p_s_about_loan);
}

float	*ft_read_positive_nbr(char *tell ,float	*p_entered_nbr)
{
	printf("Please enter a positive number:\n%s\n", tell);
	scanf("%f", p_entered_nbr);
	while (*p_entered_nbr < 0)
	{
		printf("Wrong entered number; please enter the number again:\n");
		scanf("%f", p_entered_nbr);
	}
	return (p_entered_nbr);
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
