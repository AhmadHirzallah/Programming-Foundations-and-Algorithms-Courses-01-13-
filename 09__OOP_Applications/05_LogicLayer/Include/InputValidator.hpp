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
			static bool IsNumberBetween_Var(T number, T from, T to)
			{
				return (number >= from && number <= to);
			}


			static std::string readString(std::string display = "Please enter: ")
			{
				std::string EnteredStr;

				std::cout << display;				// Display the prompt
				if (std::cin.peek() == '\n')		// Clear input buffer to avoid leftover input issues
				{
					std::cin.clear(); // Clear any error flags
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				std::getline(std::cin, EnteredStr);			// Read the full line

				return (EnteredStr);
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




// Function to read an integer

			static int readNumberInt(const std::string& promptMessage = "Please enter number: ") {
				int number;
				std::cout << promptMessage;
				while (!(std::cin >> number)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input, try again: ";
				}
				return number;
			}

			// Function to read a short integer
			static short readNumberShort(const std::string& promptMessage = "Please enter number: ") {
				short number;
				std::cout << promptMessage;
				while (!(std::cin >> number)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input, try again: ";
				}
				return number;
			}

			// Function to read a long integer
			static long readNumberLong(const std::string& promptMessage = "Please enter number: ") {
				long number;
				std::cout << promptMessage;
				while (!(std::cin >> number)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input, try again: ";
				}
				return number;
			}

			// Function to read a float
			static float readNumberFloat(const std::string& promptMessage = "Please enter number: ") {
				float number;
				std::cout << promptMessage;
				while (!(std::cin >> number)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input, try again: ";
				}
				return number;
			}

			// Function to read a double
			static double readNumberDouble(const std::string& promptMessage = "Please enter number: ") {
				double number;
				std::cout << promptMessage;
				while (!(std::cin >> number)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input, try again: ";
				}
				return number;
			}

			// Function to read a ranged integer
			static int readRangedNumberInt(int from, int to, const std::string& promptMessage = "Please enter number: ") {
				int number = readNumberInt(promptMessage); // Get the number from the user
				while (!IsNumberBetween_Var(number, from, to)) {
					std::cout << "Number not in range, try again: ";
					number = readNumberInt(promptMessage);
				}
				return number;
			}

			// Function to read a ranged short integer
			static short readRangedNumberShort(short from, short to, const std::string& promptMessage = "Please enter number: ") {
				short number = readNumberShort(promptMessage);
				while (!IsNumberBetween_Var(number, from, to)) {
					std::cout << "Number not in range, try again: ";
					number = readNumberShort(promptMessage);
				}
				return number;
			}

			// Function to read a ranged long integer
			static long readRangedNumberLong(long from, long to, const std::string& promptMessage = "Please enter number: ") {
				long number = readNumberLong(promptMessage);
				while (!IsNumberBetween_Var(number, from, to)) {
					std::cout << "Number not in range, try again: ";
					number = readNumberLong(promptMessage);
				}
				return number;
			}

			// Function to read a ranged float
			static float readRangedNumberFloat(float from, float to, const std::string& promptMessage = "Please enter number: ") {
				float number = readNumberFloat(promptMessage);
				while (!IsNumberBetween_Var(number, from, to)) {
					std::cout << "Number not in range, try again: ";
					number = readNumberFloat(promptMessage);
				}
				return number;
			}

			// Function to read a ranged double
			static double readRangedNumberDouble(double from, double to =  std::numeric_limits<double>::max(), const std::string& promptMessage = "Please enter number: ") {
				double number = readNumberDouble(promptMessage);
				while (!IsNumberBetween_Var(number, from, to)) {
					std::cout << "Number not in range, try again: ";
					number = readNumberDouble(promptMessage);
				}
				return number;
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

			// 	while (!IsNumberBetween_Var(number, from, to))
			// 	{
			// 		std::cout << error_message;
			// 		number = readIntNumber();
			// 	}

			// 	return (number);
			// }


			// static double	readDblNumberBetween(double from, double to, std::string error_message = "Number is not within range, enter again:\n")
			// {
			// 	double number = readDblNumber();

			// 	while (!IsNumberBetween_Var(number, from, to))
			// 	{
			// 		std::cout << error_message;
			// 		number = readDblNumber();
			// 	}

			// 	return (number);
			// }
*/


/*
				// static bool	IsNumberBetween_Var(short number, short from, short to)
				// {
				// 	return (number >= from && number <= to);
				// }

				// static bool	IsNumberBetween_Var(int number, int from, int to)
				// {
				// 	return (number >= from && number <= to);
				// }

				// static bool	IsNumberBetween_Var(float number, float from, float to)
				// {
				// 	return (number >= from && number <= to);
				// }

				// static bool	IsNumberBetween_Var(double number, double from, double to)
				// {
				// 	return (number >= from && number <= to);
				// }
			
			*/












/*

			// Template variadic function to read numbers (supports int, double, etc.)
			template	<typename T>

			static T readNumber_Var(std::string error_message = "Invalid entered number, enter again\n")
			{
				T number;

				do			// Ask for input at least once
				{
					std::cout << "Please enter: ";
					std::cin >> number;  // Try to read a number into 'number'

					if (std::cin.fail())		// If reading the number failed (because input was not a number), clear the error and prompt again
					{
						std::cin.clear();  // Clear the error flag
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
						std::cout << error_message;  // Show error message
					}
				}
				while (std::cin.fail());		// Repeat the loop as long as the input is not valid

				return (number);
			}


			// Template variadic function to read numbers within a specific range
			template <typename T>

			static T readNumberBetween_Var(std::string display = "Please enter:", 
											T from = std::numeric_limits<T>::lowest(),
											T to = std::numeric_limits<T>::max())	
			{
				std::cout << display;
				T number = readNumber_Var<T>();  // Call the generic readNumber function to get the input
				
				while (!(IsNumberBetween_Var_Var(number, from, to)))	// Check if the number is within the given range
				{
					std::cout << "Number is not within range; please enter number again:\n";
					number = readNumber_Var<T>("Invalid entered number's type; please enter number again\n");  // Re-prompt for input
				}

				return (number);
			}

*/