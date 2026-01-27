#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    string s1, s2="yasna", s3[5], s4;
    s1 = "hello ee";
    s3[4] = '$';
    s2[0] = 'b';
    cout << "please enter s4: ";
    getline(cin, s4);

    cout<< "s1: " << s1 << endl << endl;

    cout<< "s2: " << s2 << endl;
    cout << "s2: " << &s2 << endl;
    cout << "s2: " << s2[3] << endl;
    cout << "s2: " << &s2[3] << endl; //na     ajibe ke address neshoon nemide
    cout << "s2: " << *&s2[3] << endl << endl; //n

    cout<< "s3: " << s3 << endl; //s3 is an array. so this line prints the address of the first index of s3
    cout<< "s3: " << &s3[0] << endl; //this line does the exact thing that the previous line does
    // this loop prints the string s3
    for (int i = 0; i < 5; i++) {
        cout << s3[i];
    }
    cout << endl << endl;

    cout<< "s4: " << s4 << endl <<endl;

    /*********************************************************************************************/

    string sentence = "I am a EE student in Sharif";
    sentence[1] = sentence[4] = sentence[6] = sentence[9] = sentence[17] = sentence[20] = 9;
    cout << "with tab (9): " << sentence << endl;

    sentence[1] = sentence[4] = sentence[6] = sentence[9] = sentence[17] = sentence[20] = 13;
    cout << "with carriage return(13): " << sentence << endl;

    sentence[1] = sentence[4] = sentence[6] = sentence[9] = sentence[17] = sentence[20] = 10;
    cout << "with line feed (10): " << sentence << endl;

    sentence[1] = sentence[4] = sentence[6] = sentence[9] = sentence[17] = sentence[20] = 0;
    cout << "with zero(0): " << sentence << endl <<endl;

    /*********************************************************************************************/

    string sen1, sen2, sen3;
    char lf=0, sen4[]=" I'm Yasna";
    sen1 = "Hello";
    sen2 = "World";
    sen3 = "!";
    string res = sen1 + lf + sen2 + lf + sen3 + sen4;
    cout << res << endl << endl;

    /*********************************************************************************************/

    string sent1="This is the 1st line";
    string sent2="This is the 2nd line";
    string s = sent1 + " " + sent2;
    cout << "length: " << s.length() << endl; //number of chars
    cout << "sizeof(s): " << sizeof(s) << endl; //memory allocation
    cout << "size: " << s.size() << endl; //number of chars

    /*********************************************************************************************/

    bool b1, b2, b3, b4;

    b1 = sent1 > sent2; // 0 (false)
    sent1[1]++;
    b2 = sent1 > sent2; // 1 (true)

    /*********************************************************************************************/

    string substract = sent1.substr(2, 5); // az khode inja___ be tedad ___ joda kon
    cout<< substract << endl;
    cout << sent1.substr(2, 8) <<endl; // vaghti in kara ro anjam midim, khode jomle dast nakhorde  MIMANAD
    cout << sent1<<endl;

    sent1.insert(5, "INSERTED "); // dar index 5 in string ra ezafe mikonad & baghi ra shift midahad dar edame
    cout << "inserted res: " << sent1 << endl;

    sent1.erase(2,6); // az khode inja ___ be faseleye ___ mirizad door
    cout << "erased res: " <<sent1 << endl;

    cout << "find {line} at: " << sent1.find("line") << endl; // avalin index ke be aval kalame miresad
    cout << "find {tt} at: " << sent1.find("tt") << " npos  num" << endl << endl; // peida nakone npos num ide

    /*********************************************************************************************/

    /* we need sstream for here */

    int x = 12345;
    string str;
    str = "num is " + to_string(x+2);
    // string number = "5678";
    // int n = to_integer<???????>(number);
    cout << str << endl;
    stringstream ss;
    ss << "ss--> This is x*x " << x*x << endl;
    cout << "cout-->This is x*x " << x*x << endl;

    string st1, st2, st3;
    cout << "benevis: ";
    ss >> st1 >> st2 >> st3 >> x;

    cin >> st1 >> st2 >> st3 >> x;
    cout << st1 << st2 << st3 << endl;
    cout << "x: " << x;

    /*********************************************************************************************/

    string summer="jnkcAdABCDEFGHkcnkeABCkhde";
    size_t ind;
    // ind = summer.find("ABC", 6);  /*az in position be baad check kon*/
    // ind = summer.find_first_of("ABCj"); //az position 5 be baad?. harkodom ro peida kone mige behem. mohem nisht poste ham bashan ya na
    // ind = summer.find_first_not_of("jnkcAd"); // hich kodoome in harf ha toosh nabashe
    // ind = summer.find_last_of("ABC");
    // ind = summer.find_last_of("ABC");   /*age behesh    ind = summer.find_last_of("ABC",1);    begim, npos neshoon mide. ama age masal 10000 behesh bedim, dorost neshoon mide*/
    ind = summer.find_last_not_of("ABC");

    // summer.replace(ind, 10, "XYZ"); //n1: number of chars to be  changed. age beshesh bishtar az toole string bedim ta akhar, pak mikone baghiye ro
    cout << ind << endl;
    // cout << summer << endl;

    return 0;
}