#pragma once

#ifndef	INPUTVALIDATOR_HPP
# define INPUTVALIDATOR_HPP



# include "iostream"
# include "string"
# include "array"
# include "limits"
# include "DateUtils.hpp"
// # include "StringUtils.hpp"
// # include "CoreUtilities.hpp"

class	InputValidator
{
	public:
			
			// Template function to check if a number is between two bounds
			/* adding an additional type constraint to ensure the templates work only for arithmetic types (e.g., int, double). This prevents invalid types from being passed accidentally.*/
			// requires std::is_arithmetic_v<T>

			template	<typename T>
			
			static bool isNumberBetween_Var(T number, T from, T to)
			{
				return (number >= from && number <= to);
			}



			// Template variadic function to read numbers (supports int, double, etc.)
			template	<typename T>

			static T readNumber_Var(std::string error_message = "Invalid entered number, enter again\n")
			{
				T number;

				while (!(std::cin >> number))
				{
					std::cin.clear();  // Clear the error flag on cin
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining characters in the buffer
					std::cout << error_message;
				}

				return (number);
			}


			// Template variadic function to read numbers within a specific range
			template <typename T>

			static T readNumberBetween_Var(T from, T to, std::string error_message = "Number is not within range, enter again:\n")
			{
				T number = readNumber_Var<T>();  // Call the generic readNumber function to get the input

				// Check if the number is within the given range

				while (!(isNumberBetween_Var(number, from, to)))
				{
					std::cout << error_message;
					number = readNumber_Var<T>();  // Re-prompt for input
				}

				return (number);
			}


			static bool	isDateBetween(DateUtils Date, DateUtils From, DateUtils To)
			{
				DateUtils	DateBefore,	DateAfter;

				DateBefore = From;
				DateAfter = To;

				// Date >= from && Date <= to
				if (!(DateUtils::isDate1BeforeDate2(DateBefore, DateAfter)))
					DateUtils::swapDates(DateBefore, DateAfter);
				
				if (((DateUtils::isDate1AfterDate2(Date, DateBefore)) || (DateUtils::isDate1EqualDate2(Date, DateBefore)))
					&& ((DateUtils::isDate1BeforeDate2(Date, DateAfter)) || (DateUtils::isDate1EqualDate2(Date, DateAfter))))
						return (true);
				
				return (false);
			}




			static bool	isValidDate(DateUtils Date)
			{
				return (DateUtils::isValidDate(Date));
			}
	
};


#endif


/*
			// static int	readIntNumber(std::string error_message = "Invalid entered number, enter again\n")
			// {
			// 	int number;

			// 	while (!(std::cin >> number))
			// 	{
			// 		std::cin.clear();
			// 		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// 		std::cout << error_message;
			// 	}

			// 	return (number);
			// }

			// static double	readDblNumber(std::string error_message = "Invalid number, enter again\n")
			// {
			// 	double number;

			// 	while (!(std::cin >> number))
			// 	{
			// 		std::cin.clear();
			// 		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// 		std::cout << error_message;
			// 	}

			// 	return (number);
			// }
*/


/*
			// static int	readIntNumberBetween(int from, int to, std::string error_message = "Number is not within range, enter again:\n")
			// {
			// 	int number = readIntNumber();

			// 	while (!isNumberBetween(number, from, to))
			// 	{
			// 		std::cout << error_message;
			// 		number = readIntNumber();
			// 	}

			// 	return (number);
			// }


			// static double	readDblNumberBetween(double from, double to, std::string error_message = "Number is not within range, enter again:\n")
			// {
			// 	double number = readDblNumber();

			// 	while (!isNumberBetween(number, from, to))
			// 	{
			// 		std::cout << error_message;
			// 		number = readDblNumber();
			// 	}

			// 	return (number);
			// }
*/


/*
				// static bool	isNumberBetween(short number, short from, short to)
				// {
				// 	return (number >= from && number <= to);
				// }

				// static bool	isNumberBetween(int number, int from, int to)
				// {
				// 	return (number >= from && number <= to);
				// }

				// static bool	isNumberBetween(float number, float from, float to)
				// {
				// 	return (number >= from && number <= to);
				// }

				// static bool	isNumberBetween(double number, double from, double to)
				// {
				// 	return (number >= from && number <= to);
				// }
			
			*/