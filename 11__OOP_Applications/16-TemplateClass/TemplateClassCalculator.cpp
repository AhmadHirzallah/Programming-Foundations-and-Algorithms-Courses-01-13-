#include <iostream>


//      In Vectors;  We used    std::vector <NAME>  //  This NAME is a class;  So vectors uses something called (TemplateClass)

template <class T>
class TemplateClassCalculator
{
private:

            T   _Number1;
            T   _Number2;



public:

        TemplateClassCalculator(T Var1, T Var2)
        {
            _Number1 = Var1;
            _Number2 = Var2;
        }

        void    printResults()
        {
            std::cout << "Numbers:  " << _Number1  << " And:  " << _Number2 << "." << std::endl;
            std::cout << _Number1 << " + " << _Number2  << " = " << Add() << std::endl;
            std::cout << _Number1 << " - " << _Number2  << " = " << Subtract() << std::endl;
            std::cout << _Number1 << " * " << _Number2  << " = " << Multiply() << std::endl;
            std::cout << _Number1 << " / " << _Number2  << " = " << Divid() << std::endl;
        }



        T   Add()
        {
            return _Number1 + _Number2;
        }

        T   Subtract()
        {
            return _Number1 - _Number2;
        }

        T   Multiply()
        {
            return _Number1 * _Number2;
        }

        T   Divid()
        {
            return _Number1 / _Number2;
        }

};



int main ()
{
    TemplateClassCalculator<int> calcInt(2,1);

    calcInt.printResults();

    std::cout << std::endl << std::endl;

    TemplateClassCalculator<double> calcDouble(84123.132,  123213.35166132);

    calcDouble.printResults();
    
    return 0;
}
