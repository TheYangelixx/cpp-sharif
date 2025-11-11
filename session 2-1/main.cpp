#include <iostream>
using namespace std;

int main() {
    cout << "solving an equation" << endl;
    long int a,b;
    double x;
    cout << "a: " << endl;
    cin >> a;
    cout << "b: " << endl;
    cin >> b;
    // cin >> a,b;
    x = -b/double(a);

    /*
     casting (قالب گیری)
     imagine we have two integer variables, but we want the output to be a double
     in this case, we use the method of CASTING
     int a, b;
     double x;
     x = double(-b/a)
     with this method, we can temporarily change the type of -b/a
     */
    /*
    c++ is sequential (ترتیبی)
    if we print x, before defining the [double x = -b/a], a random number will show up. beacuse x just has a random place in memory.
    */

    /*
     x = -b/a
     LHS = RHS (left/right hand side)
     variable type =the more general variable type of b and a
     example:
     b: double, a: int --> x = double
     b: long long, a: long --> x = long long
    */
    cout << "answer: " << x << endl;
    return 0;
}

/*
 different kinds of variables:
 1. int
 2. string
 3. float / double
دقت کدوم بیشتره؟
هر کدوم اینا چه رینجی دارن؟

 signed / unsigned
 short / long / long long

 1 byte = 8 bit
 حجم هر کدوم؟
 char --> 8 bits
 long int --> 8byte
 */

