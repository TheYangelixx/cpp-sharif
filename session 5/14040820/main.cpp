#include "myheader.h"

//global variables: their default value is 0
int t;

void f()
{
    t++;
}

void g()
{
    static int k=5;
    k++;
    cout<<k<<endl;
}

int main()
{

    // local viraiables: variables defined in only main
    int t;
    cout << t++ <<endl;   /* we have two t variables. t global and t local. when we redefine t in the main function,
                            it will do the operations on local t. the variable that is nearer to it.  */
    // if we want to work with global t:
    cout << ::t << endl;

    int a=10, b=7;
//    printZarb(a,b);
    mySwap(a, b);

//    int t=20;
//    cout<<t<<endl;
//    t++;
//    cout<<t<<endl;
//    f();f();f();f();f();f();
//    cout<<t<<endl;
//    cout<<::t<<endl;

//    g();g();g();g();g();g();

    int m = 65;
    char c=65;  //azki code
    cout<<"m="<<m<<", c="<<c<<endl;
    c='B';
    cout<<int(c)<<endl;
    c='0';
    cout<<int(c)<<endl;


    return 0;
}
