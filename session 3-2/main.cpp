#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define sum(a, b) a+b
#define yasna(a, b) (a+b)

int main() {
    int a=5, b=2;
    cout << MAX << endl;
    cout << sum(a, b)*sum(a, b) << endl;
    cout << yasna(a, b)*yasna(a, b) << endl;
    cout << sum(string("Yasna "), string("Kamran")) << endl;
    /*
     *more efficient way:
     x = (a+b+c) * (a+b+c)   NO

     x = a+b+c               YES
     x *= x
     */

    //Ternary operator
    /*
     a ? b : c ? d : e ? f : g
     if a then b
     else c then d
     else e then f
     else g
     */

    int q=18, p=15;
    int c = q > p ? q : p;
    cout << "the bigger num is: " << c << endl;
    int k = 123456789;
    cout << setw(5) << k <<endl;
    cout << setfill('*') <<endl;
    //?

    double m;
    m = 2.8416783e3;
    cout << m << endl;

    cout << setfill('*') <<endl;

    cout << scientific << m << endl;

    cout << setprecision(3) << endl; //adad maani dar ro dar nazar migire
    cout << fixed << setprecision(3) << endl; //3 ragham aashar baad az momayez. gerd mikone. ama age bekhaym ghaat konim, bayad az ravesh zarb dar 100 va baad taghsim bar 100 estefade konim.
    cout << m << endl;

    cout << setw(7) << m <<endl;

    cout.unsetf(ios::floatfield); // oon fixed o ina ro reset mikone
    cout << m << endl;

    cout << hex <<m <<endl; //num dar mabnaye 16
    cout << oct <<m <<endl; //num dar mabnaye 8
    cout << dec <<m <<endl; //num dar mabnaye 10
    cout << bitset<8>(m) <<endl;
    m = 0x20;
    cout << m << endl;



    return 0;
}