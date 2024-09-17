#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESULT_LENGTH 300 

long	ft_get_nbr()
{
    long	l_entered_nbr;

    printf("%s", "Please enter a Number: ");
    if (scanf("%ld", &l_entered_nbr) != 1)
    {
        printf("Error: Invalid input\n");
        return -1;
    }
    return (l_entered_nbr);
}

char	*ft_get_ones_text(int nbr)
{
    char	*ones_arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    return (strdup(ones_arr[nbr]));
}

char	*ft_get_tens_text(long nbr)
{
    char	*tens_arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    return (strdup(tens_arr[nbr / 10]));
}

char	*ft_str_get_text_of_nbr(long nbr)
{
    char	*result = malloc(sizeof(char) * (MAX_RESULT_LENGTH + 1));

    if (!result)
        return (NULL);

    if (nbr == 0)
        strcpy(result, "Zero");
    else if (nbr >= 1 && nbr <= 19)
        strcpy(result, ft_get_ones_text(nbr));
    else if (nbr >= 20 && nbr <= 99)
    {
        strcpy(result, ft_get_tens_text(nbr));
        if (nbr % 10 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_get_ones_text(nbr % 10));
        }
    }
    else if (nbr >= 100 && nbr <= 199)
    {
        strcpy(result, "One Hundred");
        if (nbr % 100 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 100));
        }
    }
    else if (nbr >= 200 && nbr <= 999)
    {
        char	*hundreds;

		hundreds = ft_str_get_text_of_nbr(nbr / 100);
        strcpy(result, hundreds);
        free(hundreds);
        strcat(result, " Hundreds");
        if (nbr % 100 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 100));
        }
    }
    else if (nbr >= 1000 && nbr <= 1999)
    {
        strcpy(result, "One Thousand");
        if (nbr % 1000 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 1000));
        }
    }
    else if (nbr >= 2000 && nbr <= 999999)
    {
        char	*thousands = ft_str_get_text_of_nbr(nbr / 1000);

        strcpy(result, thousands);
        free(thousands);
        strcat(result, " Thousands");
        if (nbr % 1000 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 1000));
        }
    }
    else if (nbr >= 1000000 && nbr <= 1999999)
    {
        strcpy(result, "One Million");
        if (nbr % 1000000 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 1000000));
        }
    }
    else if (nbr > 1999999 && nbr <= 999999999)
    {
        char	*millions = ft_str_get_text_of_nbr(nbr / 1000000);

        strcpy(result, millions);
        free(millions);
        strcat(result, " Millions");
        if (nbr % 1000000 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 1000000));
        }
    }
    else if (nbr >= 1000000000 && nbr <= 1999999999)
    {
        strcpy(result, "One Billion");
        if (nbr % 1000000000 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 1000000000));
        }
    }
    else if (nbr > 1999999999 && nbr <= 999999999999)
    {
        char	*billions = ft_str_get_text_of_nbr(nbr / 1000000000);

        strcpy(result, billions);
        free(billions);
        strcat(result, " Billions");
        if (nbr % 1000000000 != 0)
        {
            strcat(result, " ");
            strcat(result, ft_str_get_text_of_nbr(nbr % 1000000000));
        }
    }
    else
    {
        free(result);
        return (NULL);
    }

    return (result);
}

int main(void)
{
    long	entered_nbr;
    char	*str_number_as_text;

	entered_nbr = ft_get_nbr();
    if (entered_nbr == -1)
        return (1);

	str_number_as_text = ft_str_get_text_of_nbr(entered_nbr);
    if (str_number_as_text)
    {
        printf("%s\n\n", str_number_as_text);
        free(str_number_as_text);
    }
    else
    {
        printf("Number out of range or memory allocation failed.\n\n");
        return (2);
    }

    return (0);
}
