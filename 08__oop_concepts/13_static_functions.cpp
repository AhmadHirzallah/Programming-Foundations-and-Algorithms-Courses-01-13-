#include <iostream>

using namespace std;

class   cls_a
{
    public:
            static int  func1()
            {
                return (999);
            }

            int func2()
            {
                return (20);
            }
};

int main (void)
{
    cout << cls_a::func1() << endl;
    //cout << cls_a::func2() << endl; ERROR ; NON STATIC FUNC.
    cls_a   obj1;

    cout << obj1.func1() << endl;
    cout << obj1.func2() << endl;
}