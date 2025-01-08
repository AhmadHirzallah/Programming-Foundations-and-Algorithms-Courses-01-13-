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
	friend class clsB; 
};

class	clsB
{
public:
	void	ft_display(clsA A1)
	{
		printf("\n The values of private:  var1 = %d\n", A1._var1);
		printf("\n The values of public:  var2 = %d\n", A1.var2);
		printf("\n The values of protected:  var3 = %d\n", A1.var3);
	}
};

int	main (void)
{
	clsA A1;
	clsB B1;
	B1.ft_display(A1);

}