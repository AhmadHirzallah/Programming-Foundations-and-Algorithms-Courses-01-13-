#include "ClsPeriod.hpp"


int main()
{
    // Initialize periods using clsDate for start and end dates
    ClsPeriod Period1(DateUtils(1, 1, 2022), DateUtils(10, 1, 2022));
    Period1.Print();  // Print the first period

    std::cout << "\n";

    ClsPeriod Period2(DateUtils(3, 1, 2022), DateUtils(5, 1, 2022));
    Period2.Print();  // Print the second period

    // Check if Period1 overlaps with Period2 using non-static method
    std::cout << Period1.isOverLapWith(Period2) << std::endl;
    std::cout << Period2.isOverLapWith(Period1) << std::endl;

    // Check if Period1 overlaps with Period2 using the static method
    std::cout << ClsPeriod::isOverlapPeriods(Period1, Period2) << std::endl;

    return 0;
}

    // // 
    // DateUtils startDate1(1, 1, 2022);
    // DateUtils endDate1(1, 12, 2022);
    // ClsPeriod period1(startDate1, endDate1);

    // DateUtils startDate2(1, 6, 2023);
    // DateUtils endDate2(30, 6 , 2023);
    // ClsPeriod period2(startDate2, endDate2);

    // period1.Print();
    // std::cout << std::endl;
    // period2.Print();
    // std::cout << std::endl;

    // if (period1.isOverLapWith(period2))
    // {
    //     std::cout << "The periods overlap." << std::endl;
    // }
    // else
    // {
    //     std::cout << "The periods do not overlap." << std::endl;
    // }

