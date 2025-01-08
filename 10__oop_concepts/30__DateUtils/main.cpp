#include <iostream>
#include "DateUtils.hpp"

int main() {
    try {
        DateUtils date1("10/12/2023");
        DateUtils date2(15, 10, 2024);

        // Test: Output Dates
        std::cout << "Date1: " << date1 << std::endl;
        std::cout << "Date2: " << date2 << std::endl;

        // Test: Add Days
        date1.addDays(1);
        std::cout << "Date1 after adding 1 day: " << date1 << std::endl;

        // Test: Calculate Day of the Week
        std::cout << "Day of the week for Date1: " << date1.getDayShortName() << std::endl;

        // Test: Print Month Calendar
        date2.printMonthCalendar();

        // Test: Increase Date by One Month
        date2.increaseDateByOneMonth();
        std::cout << "Date2 after increasing one month: " << date2 << std::endl;

        // Test: Calculate Days Until End of Year
        std::cout << "Days until the end of the year for Date1: " << date1.daysUntilTheEndOfYear() << std::endl;

        // Test: Business Days Calculation
        std::cout << "Business days between Date1 and Date2: " << date1.calculateBusinessDays(date2) << std::endl;

        // Test: Swap Dates
        DateUtils::swapDates(date1, date2);
        std::cout << "Date1 after swap: " << date1 << ", Date2 after swap: " << date2 << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}