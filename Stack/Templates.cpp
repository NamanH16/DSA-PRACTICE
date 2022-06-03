#include <iostream>
using namespace std;

/* Suppose I want to use this class for doubles and chars. So do I just replace int by double/char?
No! Here's where TEMPLATES come to action!!
class Pair
{
    int x;
    int y;

public:
    void setX(int x)
    {                        // CODE 1
        this->x = x;         // CODE 1 FOR DISPLAY PURPOSE ONLY
    }
    int getX()
    {
        return x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getY()
    {
        return y;
    }
};
*/

/*
template <typename T>

class Pair
{
    T x; // Here, T is a temporary data type
    T y;

public:
    void setX(T x)
    {
        this->x = x;          // CODE 2
    }                         // WHILE UNLOCKING MAIN 2, COMMENT THE OTHERS 
    T getX()
    {
        return x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    T getY()
    {
        return y;
    }
};
*/

// Now what if I want x and y to be both different data types
template <typename T, typename V>

class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    V getY()
    {
        return y;
    }
};

int main()
{
    // A triplet can also be made using Pair class only
    Pair<Pair<int, int>, int> p2;
    p2.setY(10);
    Pair<int, int> p3;
    p3.setX(20);
    p3.setY(55);

    p2.setX(p3);

    cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;

    /*    Pair<int, double> p1;
    p1.setX(10);
    p1.setY(12.333);

    cout << p1.getX() << " " << p1.getY() << endl;
  */

    /*
    Pair<int> p1; // when we create an object, a whole copy of class is made.
    p1.setX(10);  //So,it's important that we specify the data type along with the object
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(14.9);
    p2.setY(20.8);
                                                                                         // MAIN 2
    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<char> p3;
    p3.setX('a');
    p3.setY('x');

    cout << p3.getX() << " " << p3.getY() << endl;
*/
    return 0;
}