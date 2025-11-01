#include <iostream>
using namespace std;

int main() {
    cout << "calculating the average num of three numbers" << endl;
    int a, b, c;
    double m;
    cin >> a >> b >> c;
    m = (a+b+c) / 3.0;
    // we change the type of the number 3 to double, so that the more general var type be a double --> m type : double. the number of float numbers isn't limited
    // m = (double(a) +b+c) / 3
    // m = (a+b+c+0.0) / 3

    // for limiting float numbers:
    m *= 100;
    m = int(m) ;
    // or m = int(m*100)
    m /= 100;
    cout << m;
    return 0;
}