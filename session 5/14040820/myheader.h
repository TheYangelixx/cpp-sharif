//
// Created by A on 11/11/2025.
//
// if we delete line 5 and 7, nothing really would happen if the header is not included more than two times
#ifndef INC_14040820_MYHEADER_H //this is compiler directive if
// ifndef starts an <if> and this <if> closes in the last line with the code #endif
#define INC_14040820_MYHEADER_H

#include <bits/stdc++.h>
using namespace std;

// وقتی داریم سیگنیچر تعریف میکنیم، میتونیم ترتیب رو هر جوری که دوست داریم بذاریم و حتی در تابعی که در خط بالایی قرار داره از تابع در خط پایینی استفاده کنیم. در حالی که اگر مستقیما تابع را بدون سیگنیچر تعریف کنیم، نمیشود این کار را انجام داد
void printZarb(int x, int y);
int zarb(int x, int y);

const int x = 10; //when we define const, the variable x is equal to 10 forever and ever.

/*when we include header file two times, and the line 3 and 4 and #endif in this file is commented,
the code here will actually be copied and paste twice, and const int x is defined two times,
and that will lead to an error*/

//The function mysSwap can swap two variables of any type
//It uses references to modify the originals
template<typename banana>void mySwap(banana &a, banana &b);
template<typename banana>void mySwap(banana &a, banana &b)
{
    banana temp=a;
    a=b;
    b=temp;
}

#endif //INC_14040820_MYHEADER_H
