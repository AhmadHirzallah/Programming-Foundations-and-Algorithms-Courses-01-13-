#pragma once
#pragma warning(disable : 4996)

#ifndef	CLSPERIOD_HPP
# define	CLSPERIOD_HPP


# include <iostream>
# include <string>
# include "StringUtils.hpp"
# include "DateUtils.hpp"

class ClsPeriod : public DateUtils
{

private:

			DateUtils	_StartDate,	_EndDate;
public:

			ClsPeriod(DateUtils StartDate, DateUtils EndDate)
			{
				this->_StartDate = StartDate;
				this->_EndDate = EndDate;
			}




			void	setStartDate(DateUtils &StartDate)
			{
				this->_StartDate = StartDate;
			}


			DateUtils	getStartDate()	const
			{
				return (this->_StartDate);
			}
			



			void	setEndDate(DateUtils &EndDate)
			{
				this->_EndDate = EndDate;
			}


			DateUtils	getEndDate()	const
			{
				return (this->_EndDate);
			}






			static bool isOverlapPeriods(const ClsPeriod &Period1, const ClsPeriod &Period2)
			{
				if (DateUtils::compareDates(Period2.getEndDate(), Period1.getStartDate()) == e_date_compare::BEFORE ||
					DateUtils::compareDates(Period2.getStartDate(), Period1.getEndDate()) == e_date_compare::AFTER)
						return (false);
        		
				return (true);
			}

   


			bool	isOverLapWith(ClsPeriod &Period2)
			{
				return (isOverlapPeriods(*this, Period2));
			}




			void Print()
			{
				std::cout << "Period Start: ";
				getStartDate().printDate();
				std::cout << "Period End: ";
				getEndDate().printDate();
			}

#endif

};

