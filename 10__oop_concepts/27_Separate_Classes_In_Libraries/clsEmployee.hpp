#pragma once
#ifndef CLSPEMPLOYEE_HPP
# define CLSPEMPLOYEE_HPP

# include <iostream>
# include "clsPerson.hpp"

using namespace std;

class   clsEmployee : public clsPerson// this means that there is subclass/derived called employee that inherits the person super/base class 
{
    // employee class inherits from person class
    private:

                string  _title;
                string  _department;
                double  _salary;

    public:

                void	set_title(string new_title)
				{
					_title = new_title;
				}

				string	title()
				{
					return (_title);
				}

                void	set_salary(double salary)
				{
					_salary = salary;
				}

				double	salary()
				{
					return (_salary);
				}

                void	set_department(string department)
				{
					_department = department;
				}

				string	department()
				{
					return (_department);
				}

                void	ft_print_employee_info()
				{
                    ft_print_person_info();
					printf("Title: %s\n", title().c_str());
					printf("Department: %s\n", department().c_str());
					printf("Salary: %.2f\n", salary());
					printf("\n");
				}
};

#endif