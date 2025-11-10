#include <iostream>
using namespace std;

// scope = حوزه ی تعریف متغیر
int zarb(int a = 5, int b = 6) {

    return a * b;
}

// void means it doesn't return any output
void printZarb(int a = 1, int b = 1) {
    cout << zarb(a, b) << endl;
}

// makes you with dealing with the problem of run time of the program. it actually copy and paste the whole function code to the  place where you wrote the name of the function, in reality it doesn't just CALL the function
inline int zarb2(int a, int b) {
    return a * b;
}

void print(int a) {
    cout << a << endl;
    a = 0;
}

int main() {
    //  Modular programming (برنامه نویسی پیمانه ای)
    /*
     اشتباهات حداکثر یک بار لازم است تصحیح شود
     یک بار کد می نویسیم، هر چقدر بخوایم استفاده میکنیم

     example for having a input but not showing any uotput --> sleep(n) || printf()
     input no, output yes --> rand()
     inout yes, output yes --> sin(x), sqrt(X)
     input no, output no --> clrscr()
     */
    int x=5, y=8, t;
    t = zarb(x, y); //the exact defenition of having an output
    cout << zarb(x,y) << endl;
    cout << t << endl;
    printZarb(x, y);
    cout << zarb2(x, y) << endl;

    int m = 10;
    print(m);
    p


    return 0;
}