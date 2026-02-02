#include <iostream>
using namespace std;

unsigned int factorial(unsigned int n) {
    if (n < 2)
        return 1;
    else
        return n * factorial(n-1);

    // return (n<2) ? 1 : n*factorial(n-1);
}

int bmmLoop(int x, int y) {
    return (x%y) ? bmmLoop(y, x%y) : y;
}

int bmm(int x, int y) {
    // x&&y --> checks if they both are 0
    return (x&&y) ? bmmLoop(y, x) : 0;
}

// char    MoveHorse(int x, int y) {
//     if(x<0 || x>7 || y<0 || y>7 || table[x][y]!=0)	return 0;
//     table[x][y]=++counter;	// شماره حرکت اسب
//     if(counter == 64)		return 1;  // انتهای موفقیت آمیز
//     for(int i=0;i<8;i++)
//         if(MoveHorse(x+t[0][i],y+t[1][i]))
//             return 1;	// حرکت موفق بوده است
//     table[x][y]=0;
//     counter--;
//     return 0;
// }

void hanoi(int n, char src, char help, char dest)
{
    if(n<1) cout<<"Error :  n should be greater than 0";
    if(n==1)   cout<<"move disk 1 from "<<src<<" to "<<dest<<endl;
    else {
        hanoi(n-1,src,dest,help);
        cout<<"move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        hanoi(n-1,help,src,dest);
    }
}

bool promising(int s[], int n, int limit)
{
    if (limit == 0) return true;
    for (int i = 0; i <= limit - 1; i++)
        for (int j = i + 1; j <= limit; j++)
            if ((s[i]>=n)||(s[j]>=n)||(s[i]==s[j]||i-j==s[i]-s[j]||i - j==s[j]-s[i]))
                return false;
    return true;
}

// 2 safhe akhar powerppoint vahdat baraye asb

 int main() {

    /*   FACTORIAL   */
    unsigned int n;
    cout << "n= ";
    cin >> n;
    cout << "n! = " << factorial(n) << endl;
    n=10;
    while (n==factorial(n)/factorial(n-1))
        n++;
    cout  << n;    /*  the output is 13 beacuase factorial(13) will cause an integer overflow  */

    /*  GCD   */

    int x,  y;
    cin >> x >> y;
    cout << "GCD(x, y) = " << bmm(x, y);

    return 0;
 }