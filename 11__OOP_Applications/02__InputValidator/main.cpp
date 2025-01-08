#include "InputValidator.hpp"
#include "iostream"

int main()
{
    // Test number reading
    std::cout << "Testing integer input:\n";
    int intNumber = InputValidator::readNumberBetween_Var<int>(1, 100, "Please enter a number between 1 and 100:\n");
    std::cout << "You entered a valid integer: " << intNumber << "\n";

    std::cout << "\nTesting double input:\n";
    double doubleNumber = InputValidator::readNumberBetween_Var<double>(0.5, 10.5, "Please enter a number between 0.5 and 10.5:\n");
    std::cout << "You entered a valid double: " << doubleNumber << "\n";

    // Test isNumberBetween with a valid input
    bool isBetween = InputValidator::isNumberBetween_Var<int>(5, 1, 10);
    std::cout << "\nIs 5 between 1 and 10? " << (isBetween ? "Yes" : "No") << "\n";

    // Test Date comparison (assuming DateUtils has required methods)
    DateUtils date1("27/1/2020"), date2("29/1/2020"), date3(29,12,2024);  // You would need to initialize them properly
    // Set some example dates using DateUtils setters

    // date1 = some date, date2 = start date, date3 = end date
    std::cout << "\nTesting date range check:\n";
    if (InputValidator::isDateBetween(date1, date2, date3))
    {
        std::cout << "The date is within the range.\n";
    }
    else
    {
        std::cout << "The date is outside the range.\n";
    }

    return 0;
}
