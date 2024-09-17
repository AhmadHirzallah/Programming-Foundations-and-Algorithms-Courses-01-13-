#include <iostream>
#include <string>

using namespace std;

string	ft_number_to_text(long number) {
    if (number == 0) {
        return "";
    }
    if (number >= 1 && number <= 19) {
        string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                         "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        return (arr[number] + " ");
    }
    if (number >= 20 && number <= 99) {
        string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        return (arr[number / 10] + " " + ft_number_to_text(number % 10));
    }
    if (number >= 100 && number <= 199) {
        return ("One Hundred " + ft_number_to_text(number % 100));
    }
    if (number >= 200 && number <= 999) {
        return (ft_number_to_text(number / 100) + "Hundreds " + ft_number_to_text(number % 100));
    }
    if (number >= 1000 && number <= 1999) {
        return ("One Thousand " + ft_number_to_text(number % 1000));
    }
    if (number >= 2000 && number <= 999999) {
        return (ft_number_to_text(number / 1000) + "Thousands " + ft_number_to_text(number % 1000));
    }
    if (number >= 1000000 && number <= 1999999) {
        return ("One Million " + ft_number_to_text(number % 1000000));
    }
    if (number >= 2000000 && number <= 999999999) {
        return (ft_number_to_text(number / 1000000) + "Millions " + ft_number_to_text(number % 1000000));
    }
    if (number >= 1000000000 && number <= 1999999999) {
        return ("One Billion " + ft_number_to_text(number % 1000000000));
    } else {
        return (ft_number_to_text(number / 1000000000) + "Billions " + ft_number_to_text(number % 1000000000));
    }
}

long	ft_read_nbr() {
    long	number;

    cout << "\nEnter a number: ";
    cin >> number;
    return (number);
}

int main() {
    long	number;

	number = ft_read_nbr();
    cout << ft_number_to_text(number) << endl;
    return (0);
}
