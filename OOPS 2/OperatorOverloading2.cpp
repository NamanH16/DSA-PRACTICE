#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    /*  This is an incorrect method. earlier we thougth that we don't have to return anything 
        but if I try to store it another fraction,it'll give a compilation error
    
    void operator++()
    {
        numerator = numerator + denominator;
        simplify();
    }
*/
    // Pre-increment operator : First increment, then use
    Fraction &operator++() //++ is a unary operator so no value required to be passed
    {
        numerator = numerator + denominator;
        simplify();

        return *this; // "this" is actually a pointer which has the address of obj f1.
                      // Since we're making changes to f1 only , let's just return that
                      //we dereferenced this, because we don't want the address
                      //but the whole block of f1 containg numerator and denominator
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.print();
    // ++f1;
    //f1.print();

    Fraction f3 = ++(++f1); // nesting
    f1.print();
    f3.print();

    return 0;
}
