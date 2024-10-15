#include <iostream>

using namespace std;


class	clsA
{
private:
	int	_var1;

protected:
	int	var3;
public:
	int	var2;
	clsA()
	{
		_var1 = 10;
		var2 = 20;
		var3 = 30;
	}
	friend int	ft_calc_sum(clsA A1);
	friend int	ft_calc_sum(clsA A1, clsA A2);
	friend class	clsB;
};

class	clsB
{
private:
	int	_var1;

protected:
	int	var3;
public:
	int	var2;
	clsB()
	{
		_var1 = 10;
		var2 = 20;
		var3 = 30;
	}
	void	ft_function(clsA A1)
	{
		cout << (A1.var2 + A1._var1 + A1.var3)  << endl;
	}
};

//Friend Function
int	ft_calc_sum(clsA A1)
{
	return (A1._var1 + A1.var2 + A1.var3);
}

int	ft_calc_sum(clsA A1, clsA A2)
{
	return ((A1._var1 + A1.var2 + A1.var3)\
				+ (A2._var1 + A2.var2 + A2.var3));
}



int	main (void)
{
	clsA	A1;
	clsA	A2;
	clsB	B1;
	
	cout << "Sum is: " << ft_calc_sum(A1) << endl;
	cout << "Sum is: " << ft_calc_sum(A1, A2) << endl;
	cout << "Class Friend Function: " ;
	B1.ft_function(A1);

}