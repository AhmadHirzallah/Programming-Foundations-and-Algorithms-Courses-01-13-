#pragma once
#pragma warning(disable : 4996)

#ifndef DATEUTILS_HPP
# define DATEUTILS_HPP


# include <iostream>
# include <iomanip> 
# include <string>
# include <vector>
# include "StringUtils.hpp"




class	DateUtils
{
	public:

				DateUtils()
				{
					time_t	t = time(0);
					tm		*now = localtime(&t);
					_day = now->tm_mday;
					_month = (now->tm_mon + 1);
					_year = (now->tm_year + 1900);
				}


				DateUtils(std::string str_date)
				{
					std::vector <std::string>	date_vec;

					date_vec = StringUtils::splitByDelim(str_date, "/- ", StringUtils::e_split_type::SINGLE);

					if (date_vec.size() != 3)
						throw std::invalid_argument("Invalid date format");

					this->_day = static_cast<short> (std::stoi(date_vec[0]));
					this->_month = static_cast<short> (std::stoi(date_vec[1]));
					this->_year = (std::stoi(date_vec[2]));

					if (!isValidDate(*this))
						throw std::invalid_argument("Invalid date values");
				}

				
				DateUtils(short day, short month, int year)
				{
					this->_day = day;
					this->_month = month;
					this->_year = year;
				}


				DateUtils(int day_order, int year)
				{
					DateUtils	Date = calcDateByDayOrderInYear(day_order, year);

					this->_year = Date._year;
					this->_month = Date._month;
					this->_day = Date._day;
				}




				DateUtils& operator=(const DateUtils& other)
				{
					if (this != &other)
					{
						this->_day = other._day;
						this->_month = other._month;
						this->_year = other._year;
					}

					return (*this);
				}


				DateUtils& operator=(const std::string& str_date)
				{
					std::vector <std::string>	date_vec = StringUtils::splitByDelim(str_date, "/- ");

					this->_day = static_cast <short> (std::stoi(date_vec[0]));
					this->_month = static_cast <short> (std::stoi(date_vec[1]));
					this->_year = static_cast <int> (std::stoi(date_vec[2]));

					return (*this);
				}


				friend std::ostream &operator<<(std::ostream &os, const DateUtils &obj)
				{
					os << (obj._day < 10 ? "0" : "") << obj._day << "/"
						<< (obj._month < 10 ? "0" : "") << obj._month << "/"
						<< obj._year;

					return (os);
				}





				short	getDay()
				{
					return (this->_day);
				}


				short	getMonth()
				{
					return (this->_month);
				}


				int	getYear()
				{
					return (this->_year);
				}



				void	setDay(short day)
				{
					this->_day = day;
				}


				void	setMonth(short month)
				{
					this->_month = month;
				}


				void	setYear(int year)
				{
					this->_year = year;
				}





				static std::string	DateToString(DateUtils Date)
				{
					return ((std::to_string(Date._day) + "/" + std::to_string(Date._month) + "/" + std::to_string(Date._year)));
				}


				std::string	DateToString()
				{
					return (DateToString(*this));
				}


				void printDate()
				{
					std::cout << DateToString() << std::endl;
				}





				static DateUtils	getSystemDate()
				{
					short day, month;
					int year;

					time_t	t = time(0);
					tm		*now = localtime(&t);

					day = now->tm_mday;
					month = now->tm_mon + 1;
					year = now->tm_year + 1900;

					return (DateUtils(day, month, year));
				}





				static bool	isValidDate(DateUtils Date)
				{
					if (Date.getMonth() < 1 || Date.getMonth() > 12)
						return (false);

					if (Date.getDay() < 1 || Date.getDay() > getDaysNbrInMonth(Date.getMonth(), Date.getYear()))
						return (false);

					return (true);


					// short days_nbr_in_month;

					// if (Date.getDay() < 1 || Date.getDay() > 31)
					// 	return (false);
					
					// if (Date.getMonth() < 1 || Date.getMonth() > 12)
					// 	return (false);

					// if (Date.getMonth() == 2)
					// {
					// 	if (isLeapYear(Date.getYear()))
					// 	{
					// 		if (Date.getDay() > 29)
					// 			return (false);
					// 	}
					// 	else
					// 	{
					// 		if (Date.getDay() > 28)
					// 			return (false);
					// 	}
					// }

					// days_nbr_in_month = getDaysNbrInMonth(Date.getMonth(), Date.getYear());

					// if (Date.getDay() > days_nbr_in_month)
					// 	return (false);

					// return (true);
				}


				bool	isValid()
				{
					return (isValidDate(*this));
				}





				static bool	isLeapYear(int year)
				{
					return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
				}


				bool	isLeapYear()
				{
					return (isLeapYear(_year));
				}





				static short	getDaysNbrInMonth(short month, int year)
				{
					if (month < 1 || month > 12)
						return (0);

					int	days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

					return ((month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1]);
				}


				short	getDaysNbrInMonth()	const
				{
					return (getDaysNbrInMonth(_month , _year));
				}





				static DateUtils	calcDateByDayOrderInYear(int day_order_in_year, int year)
				{
					DateUtils	Date;
					int				remaining_days = day_order_in_year;
					short			month_days = 0;

					Date._year = year;
					Date._month = 1;
					
					while (true)
					{
						month_days = getDaysNbrInMonth(Date._month, year);

						if (remaining_days > month_days)
						{
							remaining_days -= month_days;
							Date._month++;
						}
						else
						{
							Date.setDay(remaining_days);
							break;
						}
					}

					return (Date);
				}




				static int	getDaysNbrInYear(int year)
				{
					return  isLeapYear(year) ? 366 : 365;
				}


				int	getDaysNbrInYear()
				{
					return (getDaysNbrInYear(_year));
				}




				static int	getHoursNbrOfYear(int year)
				{
					return (getDaysNbrInYear(year) * 24);
				}


				int	getHoursNbrOfYear()
				{
					return (getHoursNbrOfYear(_year));
				}




				static int	getMinutesNbrOfYear(int year)
				{
					return (getHoursNbrOfYear(year) * 60);
				}


				int	getMinutesNbrOfYear()
				{
					return (getMinutesNbrOfYear(_year));
				}




				static int	getSecondsNbrOfYear(int year)
				{
					return (getMinutesNbrOfYear(year) * 60);
				}


				int	getSecondsNbrOfYear()
				{
					return (getSecondsNbrOfYear(_year));
				}






				static short getHoursNbrInMonth(short month, int year)
				{
        			return getDaysNbrInMonth(month, year) * 24;
				}
  

				short getHoursNbrInMonth()
				{
        			return (getHoursNbrInMonth(_month, _year));
				}


				
				
				
				static int getMinutesNbrInMonth(short month, int year)
				{
					return (getHoursNbrInMonth(month, year) * 60);
				}


				int getMinutesNbrInMonth()
				{
					return (getMinutesNbrInMonth(_month, _year));
				}





				static int	getSecondsNbrInMonth(short month, int year)
				{
					return (getMinutesNbrInMonth(month, year) * 60);
				}


				int	getSecondsNbrInMonth()
				{
					return (getSecondsNbrInMonth(_month, _year));
				}




				static short	getDayOfWeekOrder(short day, short month, int year)
				{
					short a = (14 - month) / 12;
					int y = year - a;
					short m = month + (12 * a) - 2;
					// Gregorian: 0: Sun, 1: Mon, 2: Tue, ...etc

					return ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
				}

	
				short	getDayOfWeekOrder()
				{
					return (getDayOfWeekOrder(_day, _month, _year));
				}



				static std::string	getDayShortName(short day_of_week_order)
				{
					std::string arr_days_names[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
					
					return arr_days_names[day_of_week_order];
				}
				
				
				static std::string	getDayShortName(short day, short month, int year)
				{
					return (getDayShortName(getDayOfWeekOrder(day, month, year)));
				}


				std::string getDayShortName() const
				{
					return (getDayShortName(getDayOfWeekOrder(_day, _month, _year)));
				}




				static std::string	getMonthShortName(short month_number)
				{
					std::string	months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
					
					return (months[month_number - 1]);
				}
				
				
				std::string	getMonthShortName()
				{
					return (getMonthShortName(this->getMonth()));
				}




				// PrintMonthCalendar methods
				static void	printMonthCalendar(short month, int year)
				{
					int current = getDayOfWeekOrder(1, month, year);
					int number_of_days = getDaysNbrInMonth(month, year);
					
					// Print the month name and day headers
					std::cout << "\n  _______________" << getMonthShortName(month) << "_______________\n\n";
					std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
					
					// Print leading spaces
					for (int i = 0; i < current; i++)
						std::cout << "     ";
					// Print days of the month
					for (int j = 1; j <= number_of_days; j++)
					{
						std::cout << std::setw(5) << j;
						if (++current == 7)
						{
							current = 0;
							std::cout << "\n";
						}
					}
					
					std::cout << "\n  _________________________________\n";
				}
				
				
				void	printMonthCalendar() const
				{
					printMonthCalendar(_month, _year);
				}
				
				
				
				
				// PrintYearCalendar methods
				static void	printYearCalendar(int year)
				{
					std::cout << "\n  _________________________________\n\n";
					std::cout << "           Calendar - " << year << "\n";
					std::cout << "  _________________________________\n";
					for (int i = 1; i <= 12; i++)
						printMonthCalendar(i, year);
				}
				
				
				void	printYearCalendar()
				{
					printYearCalendar(this->getYear());
				}




				// DaysFromTheBeginningOfTheYear methods
				static short daysFromTheBeginningOfTheYear(short day, short month, int year)
				{
					short total_days = 0;
					
					for (int i = 1; i < month; i++)
						total_days += getDaysNbrInMonth(i, year);
					
					total_days += day;
				
					return (total_days);
				}
				
				
				short daysFromTheBeginningOfTheYear() const
				{
					return (daysFromTheBeginningOfTheYear(_day, _month, _year));
				}




				void addDays(short days)
				{
					short remaining_days;
					short month_days;

					remaining_days = days + daysFromTheBeginningOfTheYear(_day, _month, _year);
					month_days = 0;

					_month = 1;
					while (true)
					{
						month_days = getDaysNbrInMonth(_month, _year);

						if (remaining_days > month_days)
						{
							remaining_days -= month_days;
							_month++;

							if (_month > 12)
							{
								_month = 1;
								_year++;
							}
						}
						else
						{
							_day = remaining_days;
							break;
						}
					}
				}


				static bool	isDate1BeforeDate2(DateUtils Date1, DateUtils Date2)
				{
					return (Date1.getYear() < Date2.getYear()) ? true : 
						((Date1.getYear() == Date2.getYear()) ? 
						(Date1.getMonth() < Date2.getMonth() ? true : 
						(Date1.getMonth() == Date2.getMonth() ? Date1.getDay() < Date2.getDay() : false)) : false);
				}

				bool	isDateBeforeDate2(DateUtils Date2)
				{
					return (isDate1BeforeDate2(*this, Date2));
				}





				static bool	isDate1EqualDate2(DateUtils Date1, DateUtils Date2)
				{
					return (Date1.getYear() == Date2.getYear()) ? 
						((Date1.getMonth() == Date2.getMonth()) ? 
						((Date1.getDay() == Date2.getDay()) ? true : false) : false) : false;
				}


				bool isDateEqualDate2(DateUtils Date2)
				{
					return (isDate1EqualDate2(*this, Date2));
				}





				static bool	isLastDayInMonth(DateUtils Date)
				{
					return (Date.getDay() == getDaysNbrInMonth(Date.getMonth(), Date.getYear()));
				}


				bool	isLastDayInMonth()
				{
					return (isLastDayInMonth(*this));
				}





				static bool	isLastMonthInYear(short month)
				{
					return (month == 12);
				}





				static DateUtils	addOneDay(DateUtils Date)
				{
					if (isLastDayInMonth(Date))
					{
						if (isLastMonthInYear(Date.getMonth()))
						{
							Date.setDay(1);
							Date.setMonth(1);
							Date.setYear(Date.getYear() + 1);
						}
						else
						{
							Date.setDay(1);
							Date.setMonth(Date.getMonth() + 1);
						}
					}
					else
						Date.setDay(Date.getDay() + 1);

					return (Date);
				}


				void	addOneDay()
				{
					*this = addOneDay(*this);
				}





				static void swapDates(DateUtils &Date1, DateUtils &Date2)
				{
					DateUtils	TempDate;

					TempDate = Date1;
					Date1 = Date2;
					Date2 = TempDate;
				}


				void swapDates(DateUtils &Date2)
				{
					swapDates(*this, Date2);

					// DateUtils	TempDate;

					// TempDate = Date1;
					// Date1 = *this;
					// *this = TempDate;
				}





				static int calculateDifferenceInDays(DateUtils Date1, DateUtils Date2, bool include_end_day = false)
				{
					int days_difference = 0;
					short swap_flag_value = 1;

					if (!isDate1BeforeDate2(Date1, Date2))
					{
						swapDates(Date1, Date2);
						swap_flag_value = -1;
					}

					while (isDate1BeforeDate2(Date1, Date2))
					{
						days_difference++;
						Date1 = addOneDay(Date1);
					}

					return (include_end_day ? (days_difference++ * swap_flag_value) : (days_difference * swap_flag_value));
				}


				int calculateDifferenceInDays(DateUtils Date2, bool include_end_day = false)
				{
					return (calculateDifferenceInDays(*this, Date2, include_end_day));
				}




				static short calculateMyAgeInDays(DateUtils DateOfBirth)
				{
					return (calculateDifferenceInDays(DateOfBirth, DateUtils::getSystemDate(), true));
				}




				static DateUtils	increaseDateByOneWeek(DateUtils &Date)
				{
					for (int i = 1; i <= 7; i++)
						Date = addOneDay(Date);

					return (Date);
				}


				void	increaseDateByOneWeek()
				{
					increaseDateByOneWeek(*this);
				}




				static DateUtils	increaseDateByXWeeks(short weeks, DateUtils &Date)
				{
					for (short i = 1; i <= weeks; i++)
						Date = increaseDateByOneWeek(Date);
					
					return (Date);
				}


				void	increaseDateByXWeeks(short weeks)
				{
					increaseDateByXWeeks(weeks, *this);
				}




				static DateUtils	increaseDateByOneMonth(DateUtils &Date)
				{
					if (Date.getMonth() == 12)
					{
						Date.setMonth(1);
						Date.setYear(Date.getYear() + 1);
					}
					else
						Date.setMonth(Date.getMonth() + 1);


					short nbr_of_days_in_month = getDaysNbrInMonth(Date.getMonth(), Date.getYear());

					if (Date.getDay() > nbr_of_days_in_month)
						Date.setDay(nbr_of_days_in_month);

					return (Date);
				}


				void	increaseDateByOneMonth()
				{
					increaseDateByOneMonth(*this);
				}




				static DateUtils	increaseDateByXDays(short days, DateUtils &Date)
				{
					for (short i = 1; i <= days; i++)
						Date = addOneDay(Date);
					return Date;
				}


				void	increaseDateByXDays(short days)
				{
					increaseDateByXDays(days, *this);
				}




				static DateUtils	increaseDateByXMonths(short months, DateUtils &Date)
				{
					for (short i = 1; i <= months; i++)
						Date = increaseDateByOneMonth(Date);

					return (Date);
				}

				void	increaseDateByXMonths(short months)
				{
					increaseDateByXMonths(months, *this);
				}




				static DateUtils	increaseDateByOneYear(DateUtils &Date)
				{
					Date.setYear(Date.getYear() + 1);
					
					return (Date);
				}


				void increaseDateByOneYear()
				{
					increaseDateByOneYear(*this);
				}




				static DateUtils	increaseDateByXYears(int years, DateUtils &Date)
				{
					Date.setYear(Date.getYear() + years);

					return (Date);
				}


				void	increaseDateByXYears(int years)
				{
					increaseDateByXYears(years, *this);
				}




				static DateUtils	increaseDateByOneDecade(DateUtils &Date)
				{
					Date.setYear(Date.getYear() + 10);

					return (Date);
				}


				void	increaseDateByOneDecade()
				{
					increaseDateByOneDecade(*this);
				}




				static DateUtils	increaseDateByXDecades(short decades, DateUtils &Date)
				{
					Date.setYear(Date.getYear() + decades * 10);

					return (Date);
				}


				void	increaseDateByXDecades(short decades)
				{
					increaseDateByXDecades(decades, *this);
				}




				static DateUtils	increaseDateByOneCentury(DateUtils &Date)
				{
					Date.setYear(Date.getYear() + 100);

					return (Date);
				}


				void	increaseDateByOneCentury()
				{
					increaseDateByOneCentury(*this);
				}




				static DateUtils	increaseDateByOneMillennium(DateUtils &Date)
				{
					Date.setYear(Date.getYear() + 1000);

					return (Date);
				}


				void	increaseDateByOneMillennium()
				{
					increaseDateByOneMillennium(*this);
				}




				static DateUtils	decreaseDateByOneDay(DateUtils Date)
				{
					if (Date.getDay() == 1)
					{
						if (Date.getMonth() == 1)
						{
							Date.setMonth(12);
							Date.setDay(31);
							Date.setYear(Date.getYear() - 1);
						}
						else
						{
							Date.setMonth(Date.getMonth() - 1);
							Date.setDay(getDaysNbrInMonth(Date.getMonth(), Date.getYear()));
						}
					}
					else
						Date.setDay(Date.getDay() - 1);

					return (Date);
				}


				void	decreaseDateByOneDay()
				{
					decreaseDateByOneDay(*this);
				}




				static DateUtils	decreaseDateByOneWeek(DateUtils &Date)
				{
					for (int i = 1; i <= 7; i++)
						Date = decreaseDateByOneDay(Date);

					return (Date);
				}


				void	decreaseDateByOneWeek()
				{
					decreaseDateByOneWeek(*this);
				}




				static DateUtils	decreaseDateByXWeeks(short weeks, DateUtils &Date)
				{
					for (short i = 1; i <= weeks; i++)
						Date = decreaseDateByOneWeek(Date);

					return (Date);
				}


				void	decreaseDateByXWeeks(short weeks)
				{
					decreaseDateByXWeeks(weeks, *this);
				}




				static DateUtils	decreaseDateByOneMonth(DateUtils &Date)
				{
					if (Date.getMonth() == 1)
					{
						Date.setMonth(12);
						Date.setYear(Date.getYear() - 1);
					}
					else
						Date.setMonth(Date.getMonth() - 1);

					// Last check: day in Date should not exceed max days in the current month
					short numberOfDaysInCurrentMonth = getDaysNbrInMonth(Date.getMonth(), Date.getYear());

					if (Date.getDay() > numberOfDaysInCurrentMonth)
						Date.setDay(numberOfDaysInCurrentMonth);

					return (Date);
				}


				void	decreaseDateByOneMonth()
				{
					decreaseDateByOneMonth(*this);
				}




				static DateUtils	decreaseDateByXDays(short days, DateUtils &Date)
				{
					for (short i = 1; i <= days; i++)
						Date = decreaseDateByOneDay(Date);

					return (Date);
				}


				void	decreaseDateByXDays(short days)
				{
					decreaseDateByXDays(days, *this);
				}




				static DateUtils	decreaseDateByXMonths(short months, DateUtils &Date)
				{
					for (short i = 1; i <= months; i++)
						Date = decreaseDateByOneMonth(Date);
					
					return (Date);
				}


				void	decreaseDateByXMonths(short months)
				{
					decreaseDateByXMonths(months, *this);
				}




				static DateUtils	decreaseDateByOneYear(DateUtils &Date)
				{
					Date.setYear(Date.getYear() - 1);

					return (Date);
				}


				void	decreaseDateByOneYear()
				{
					decreaseDateByOneYear(*this);
				}




				static DateUtils	decreaseDateByXYears(int years, DateUtils &Date)
				{
					Date.setYear(Date.getYear() - years);

					return (Date);
				}


				void	decreaseDateByXYears(int years)
				{
					decreaseDateByXYears(years, *this);
				}




				static DateUtils	decreaseDateByOneDecade(DateUtils &Date)
				{
					Date.setYear(Date.getYear() - 10);

					return (Date);
				}


				void	decreaseDateByOneDecade()
				{
					decreaseDateByOneDecade(*this);
				}




				static DateUtils	decreaseDateByXDecades(short decades, DateUtils &Date)
				{
					Date.setYear(Date.getYear() - decades * 10);

					return (Date);
				}


				void	decreaseDateByXDecades(short decades)
				{
					decreaseDateByXDecades(decades, *this);
				}




				static DateUtils	decreaseDateByOneCentury(DateUtils &Date)
				{
					Date.setYear(Date.getYear() - 100);
					
					return (Date);
				}

				void decreaseDateByOneCentury()
				{
					decreaseDateByOneCentury(*this);
				}




				static DateUtils	decreaseDateByOneMillennium(DateUtils &Date)
				{
					Date.setYear(Date.getYear() - 1000);

					return (Date);
				}


				void	decreaseDateByOneMillennium()
				{
					decreaseDateByOneMillennium(*this);
				}




				static short	isEndOfWeek(DateUtils Date)
				{
					return (getDayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear()) == 6);		//6 = Saturday
				}


				short	isEndOfWeek()
				{
					return (isEndOfWeek(*this));
				}




				static bool	isWeekEnd(DateUtils Date)
				{
					// Weekends are Fri and Sat
					short dayIndex = getDayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear());

					return (dayIndex == 5 || dayIndex == 6);
				}


				bool	isWeekEnd()
				{
					return isWeekEnd(*this);
				}




				static bool	isBusinessDay(DateUtils Date)
				{
					// Weekends are Sun, Mon, Tue, Wed, and Thu
					return (!isWeekEnd(Date));
				}


				bool	isBusinessDay()
				{
					return (isBusinessDay(*this));
				}




				static short	daysUntilTheEndOfWeek(DateUtils Date)
				{
					return (6 - getDayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear()));
				}

				short	daysUntilTheEndOfWeek()
				{
					return (daysUntilTheEndOfWeek(*this));
				}




				static short	daysUntilTheEndOfMonth(DateUtils Date)
				{
					DateUtils	EndOfMonthDate;

					EndOfMonthDate.setDay(getDaysNbrInMonth(Date.getMonth(), Date.getYear()));
					EndOfMonthDate.setMonth(Date.getMonth());
					EndOfMonthDate.setYear(Date.getYear());

					return (calculateDifferenceInDays(Date, EndOfMonthDate, true));
				}


				short	daysUntilTheEndOfMonth()
				{
					return (daysUntilTheEndOfMonth(*this));
				}




				static short	daysUntilTheEndOfYear(DateUtils Date)
				{
					DateUtils EndOfYearDate;

					EndOfYearDate.setDay(31);
					EndOfYearDate.setMonth(12);
					EndOfYearDate.setYear(Date.getYear());

					return (calculateDifferenceInDays(Date, EndOfYearDate, true));
				}

				short	daysUntilTheEndOfYear()
				{
					return (daysUntilTheEndOfYear(*this));
				}






				// Added this method to calculate business days between 2 Dates
				static short	calculateBusinessDays(DateUtils DateFrom, DateUtils DateTo)
				{
					short days = 0;
					while (isDate1BeforeDate2(DateFrom, DateTo))
					{
						if (isBusinessDay(DateFrom))
							days++;

						DateFrom = addOneDay(DateFrom);
					}

					return (days);
				}


				short	calculateBusinessDays(DateUtils DateTo)
				{
					return (calculateBusinessDays(*this, DateTo));
				}




				static short	calculateVacationDays(DateUtils DateFrom, DateUtils DateTo)
				{
					return (calculateBusinessDays(DateFrom, DateTo));
				}


				short	calculateVacationDays(DateUtils DateTo)
				{
					return (calculateVacationDays(*this, DateTo));
				}




				// Above method is enough, no need for an additional method for the object
				static DateUtils	calculateVacationReturnDate(DateUtils DateFrom, short vacation_days)
				{
					short weekend_counter = 0;

					for (short i = 1; i <= vacation_days; i++)
					{
						if (isWeekEnd(DateFrom))
							weekend_counter++;

						DateFrom = addOneDay(DateFrom);
					}

					// To add weekends 
					for (short i = 1; i <= weekend_counter; i++)
						DateFrom = addOneDay(DateFrom);

					return (DateFrom);
				}




				static bool	isDate1AfterDate2(DateUtils Date1, DateUtils Date2)
				{
					return (!isDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
				}


				bool	isDateAfterDate2(DateUtils Date2)
				{
					return isDate1AfterDate2(*this, Date2);
				}






				enum	e_date_compare { BEFORE = -1, EQUAL = 0, AFTER = 1 };


				static e_date_compare	compareDates(DateUtils Date1, DateUtils Date2)
				{
					if (isDate1BeforeDate2(Date1, Date2))
						return (e_date_compare::BEFORE);

					if (isDate1EqualDate2(Date1, Date2))
						return (e_date_compare::EQUAL);

					return (e_date_compare::AFTER);
				}


				e_date_compare	compareDates(DateUtils Date2)
				{
					return (compareDates(*this, Date2));
				}




	private:

				short	_day = 1;
				short	_month = 1;
				int			_year = 1900;


};


#endif