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

    // Pre-increment operator : First increment, then use
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();

        return *this;
    }

    // Post-increment operator: first use and then increment
    Fraction operator++(int) // in Post increment operator,'int' is passed in order to differentiate it from pre-increment operator
    {
        Fraction Fnew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        Fnew.simplify();
        return Fnew;
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction f3 = f1++; //nesting not allowed

    f1.print();
    f3.print();

    return 0;
}
