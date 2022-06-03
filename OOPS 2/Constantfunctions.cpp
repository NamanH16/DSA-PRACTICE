// Note: Always keep in mind to mark those functions as constant which aren't making any changes in the properties of an object
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction()
    {
    }
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // int getNumerator()
    //{
    //    return numerator;
    //}

    int getNumerator() const // this function isn't changing anything(just returning), so ideally it should be constant
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    void setNumerator(int n) // Not allowed to be made "const" since it's making changes to the properties of object
    {                        // Not allowed to be called either by our const obj f3
        numerator = n;
    }

    void setDenominator(int d)
    {
        denominator = d;
    }

    void print() const
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

    void add(Fraction const &f2) // address of f2 is same as f1, but thru f2 we won't be able to make any illegal changes
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();
    }

    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction const f3;

    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
    // The compiler won't allow to call any normal function from const obj

    // Only constant functions are allowed to be called by constant objects
    // Constant functions: which doesn't change any properties of current object

    return 0;
}