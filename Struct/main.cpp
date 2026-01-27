#include <iostream>
using namespace std;

union all_types {
    int    t1;
    double t2;
    char   t3;
    float  t4;
};

struct Student {
    int score;
    int num;
};

typedef struct {
    string name;
    int numberl;
} people ;




struct Point {
    int x;
    int y;
};

Point negatePoint(Point& p) {
    return { -p.x, -p.y };
}

void f(int a[2][2], int n , int m) {
    cout << a[n][m];
}

int main() {
    // all_types var1, var4;
    //
    // var4.t1 = 42;        // store an int in var4
    // var1.t1 = var4.t1;   // copy that int into var1
    //
    // cout << var1.t1;     // prints 42

    // struct Student s1;
    // Student s2;
    // s1.score = 1;
    // s2.num = 10;
    //
    // people p1;

    // fun(p2);
    // Point p1 = {1,2};
    // negatePoint(p1).x;
    // cout << negatePoint(p1).x << ", " << negatePoint(p1).y << endl;

    int a [2][2] = {{1,2}, {3,4}};
    int b[2][2] = {0};
    f(a, 1, 1);
    return 0;

}
