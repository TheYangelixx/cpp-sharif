#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

bool myCmp(int i, int j)
{
    return i<j;
}

/* the functions used in invoke1 or invoke2 shouldn't necesserally be defined above the invoke functions*/
int invoke1(int x, int y, int(f)(int, int)=nullptr)
{
    if(f!=nullptr)
        return f(x,y);
    return -1;
}

/* invoke2 function need #include <functional> in order to work. but invoke1 doesn't */
int invoke2(int x, int y, const function<int(int,int)>& f=nullptr)
{
    if(f!=nullptr)
        return f(x,y);
    return -1;
}

int add(int x, int y)
{
    return x+y;
}

int multiply(int x, int y)
{
    return x*y;
}


bool cmpInt(int i, int j)
{
    return i>=j;
}

int main() {

    /* algorithm */
    cout << "   ALGORITHM   " << endl;
    int myInts[]= {3,7,2,5,6,4,1};
    int n=sizeof(myInts)/sizeof(myInts[0]);

    cout<<"max="<< max_element(myInts, myInts+n)<<endl; /* prints the address of the max element*/
    cout<<"max="<< *max_element(myInts, myInts+n)<<endl;
    cout<<"min="<< *min_element(myInts, myInts+n)<<endl;
    cout<<"max="<< *max_element(myInts, myInts+n, myCmp)<<endl;
    cout<<"min="<< *min_element(myInts, myInts+n, myCmp)<<endl<<endl;

    /*******************************************************/

    /* functional */
    cout << "   FUNCTIONAL  " << endl;
    cout<<invoke2(10,20,add)<<endl;
    cout<<invoke2(10,20,multiply)<<endl;
    cout<<invoke2(10,20,nullptr)<<endl;
    cout<<invoke2(10,20)<<endl;
    // cout<<invoke2(10,20,cmpInt)<<endl;    //compiler error. chon goftim output int hast dar taarife invoke?

    return 0;
}