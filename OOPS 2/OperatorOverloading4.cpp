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

    Fraction &operator+=(Fraction const &f2) //if we don't return by reference in fraction,we won't be able to have f
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();

        return *this;
    }
};

int main()
{
    Fraction f1(10, 3);
    Fraction f2(5, 2);

    (f1 += f2) += f2;
    // for (f1 += f2), the system would recieve its ans in a temperary buffer, but we don't want that,
    // we want to recieve our ans in f1 itself(Hence the "&" after Fraction in line 37)

    f1.print();
    f2.print();

    return 0;
}
