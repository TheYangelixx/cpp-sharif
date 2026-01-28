//
// Created by A on 11/11/2025.
//

#ifndef INC_14040820_MYHEADER_H
#define INC_14040820_MYHEADER_H

#include <bits/stdc++.h>

using namespace std;


struct Student{
    string name;
    string family;
    string nCode;
    string stNum;
    float GPA;
    //int data[100000];
    float courseUnits[100];
    float courseScore[100];
    string courseNumber[100];
    int nCourses;

    void calcGPA()
    {
        float s=0, d=0;
        for(int i=0; i<nCourses; i++)
        {
            s+=courseUnits[i]*courseScore[i];
            d+=courseUnits[i];
        }
        if(d!=0)
            GPA=s/d;
        else
            GPA=0;
    }
};


void printZarb(int x, int y);
int zarb(int x, int y);
template<typename T>void mySwap(T &a, T &b);
bool isPrime(long long n);
int series01(unsigned n);
double series02(unsigned n);
double series03(unsigned n);
double series04(double x, unsigned n);
double series05(unsigned n);
double series06(double x, unsigned n);
double mySqrt(double x);
unsigned fibonacci(unsigned n);
unsigned gcd(unsigned a, unsigned b);
unsigned lcm(unsigned a, unsigned b);
bool isArmstrong(unsigned n);
void drawing01(int n);
void drawing02(int n);
void numbers01(int n);
void numbers02(int n);
void numbers03(int n);
void numbers04(int n);
int findMax(const int a[], int size);
void bubbleSort(int a[], int size);
int findSecondRank(int a[], int size);
int gameState(int G[3][3]);
int binarySearch(int x, int a[], int n);
void printStudent(const Student &s);
string strTrim(const string &s);
bool cmpInt(int i, int j);
bool cmpStudentGPA(const Student &s1, const Student &s2);



template<typename T>void printArray(T a[], int size, bool linear=true)
{
    if(linear)
    {
        for(int i=0; i<size; i++)
            cout<<a[i]<<" ";
    }
    else
    {
        for(int i=0; i<size; i++)
            cout<<a[i]<<endl;
    }

}

template<typename T>void mySwap(T &a, T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
#endif //INC_14040820_MYHEADER_H
