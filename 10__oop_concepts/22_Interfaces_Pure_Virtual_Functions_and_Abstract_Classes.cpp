#include <iostream>

using namespace std;

class clsMobile
{
public:
		virtual void	ft_dial(string phone_nbr) = 0;
		virtual void	ft_send_sms(string phone_nbr, string txt) = 0;
		virtual void	ft_take_picture() = 0;
};

class clsIphone : public clsMobile
{
	//	This class signed a contract with clsMobile abstract class   therefore it should implement everything in the abstract class.
public:
		void	ft_dial(string phone_nbr)		override
		{

			cout <<"Dialing " << phone_nbr << " on iphone"; 
		};

		void	ft_send_sms(string phone_nbr, string txt) override
		{
			cout <<"SMS on iphone with phonenumber " << phone_nbr << " and sms is:\n" << txt;
		};

		void	ft_take_picture()override
		{
			cout <<"Picture on iphone";
		};
};

class clsSamsung : public clsMobile
{
public:
		void	ft_dial(string phone_nbr)		override
		{
			cout <<"Dialing " << phone_nbr << " on samsung"; 
		};

		void	ft_send_sms(string phone_nbr, string txt) override
		{
			cout <<"SMS on samsung with phonenumber " << phone_nbr << " and sms is:\n" << txt;
		};

		void	ft_take_picture()override
		{
			cout <<"Picture on samsung";
		};
};


int	main (void)
{
	clsIphone MyIphone;
	
	clsSamsung MySamsung; 
	// You have  to define and overridde the pure virtual function with : [[[[void	ft_send_sms(string phone_nbr, string txt) override]]]]
	// Just Remove the comement

	cout << "1:\n";
	MyIphone.ft_send_sms("0079291391329", "AJAJAJAJJAJAJ");


	cout << "\n\n2:\n";
	MySamsung.ft_take_picture();
	
	return (0);
}