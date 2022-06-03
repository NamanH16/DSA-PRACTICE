// Suppose there're 3 integers: a,b,c
// Now, c = a + b is allowed since '+' operator is defined only for integers
// Now, for instance there is a class Fraction which has 3 objects: f1,f2,f3
// But f3 = f1 + f2 NOT ALLOWED since '+' operator isn't defined
// the overloading of operator in order to make it usable by user-defined classes is called operator overloading
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

    Fraction add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        //numerator = num;
        //denominator = lcm;
        Fraction Fnew(num, lcm);
        Fnew.simplify();
        return Fnew;
    }

    // Operator Overloading
    Fraction operator+(Fraction const &f2) const // const, since it's not making any changes to its own properties
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        //numerator = num;
        //denominator = lcm;
        Fraction Fnew(num, lcm);
        Fnew.simplify();
        return Fnew;
    }

    Fraction operator*(Fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        Fraction Fnew(n, d);

        Fnew.simplify();

        return Fnew;
    }

    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 + f2;
    Fraction f5 = f1 * f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();

    if (f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }

    return 0;
}