// #include <iostream>
// #include <typeinfo>

// this header includes all standard c++ headers. but it doesn't contain any header that a single person has developed.
#include <bits/stdc++.h>
using namespace std;

int main() {
    // the % operator : baghi mande
    int a = 10, b = 7, c;
    c = a % b;
    // alamat c = ghadre motlagh ha ro hesab mikone. baad alamat avali ro baraye c lahaz mikone.
    /*
     a = 10, b = -7
     |a| % |b| = sign(a) c
     */

    /*
    alamate % faghat baraye number haye sahih (int) hast. hala sighned ya unsigned fargh nadare. age double ya float bezarim error mide
     */
    cout << a << "%" << b << "=" << c << endl;

    // auto khodesh type variable ro tashkhis mide
    auto n=2;
    cout << typeid(n).name() << endl;

    /*
     first letter of a variable:
     A..Z a..z _
     other chars of a variable's name:
     A..Z a..z 0..9 _
     */

     /*
      ++i : i++ : i = i+1 : i += 1
      --i : i-- : i = i-1 : i -=1

      difference between ++i and i++:
      ++i : ebteda afzayesh
      i++ : enteha afzayesh
      */
    int x=5, y=6, z;
    z = 2*++a;
    cout << z << endl;
    //  khate 46: z ba meghdare avaliye y mohasebe mishe. yani y hamoon 6 hast. baadesh az y yeki kam mishe ama dar meghdare z tasir nadare.
    z = 3*y--;
    cout << z << endl;

    return 0;
}
