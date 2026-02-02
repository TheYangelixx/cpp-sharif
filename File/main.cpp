#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // OPENING A FILE

    // 1
    ifstream in("in.txt");  // read
    // 2
    ofstream out;             // write
    out.open("out.txt");

    /*
     how to give the address of a file?
     ..\\foulder_name\\file_name
     .. : go one folder aghab
     */
    /****************************************/

    // FINDING OUT IF A FILE HAS OPENED OR NOT

    if (!in.is_open())  { cout << "File not found1" << endl; return 1; }
    if (!in)            { cerr << "File not opened2" << endl; return 1; }
    if (out.fail())     { cout << "File not opened3" << endl; return 1;}

    /*
     cout --> normal output
     cerr --> error without buffer
    */

    if (in.good())
        cout << "stream is OK" << endl;
    /* in.good() == Na eof     na bad    na fail   */
    /*
    in.eof();   be akhare file reside?   -->  in.clear();   (pak kardane vaziate error)
    in.fail();  errore format/amaliat
    in.bad();   errore jedi (example: errore shakt afzari)
    */

    /****************************************/

    // READING A FILE

    // khandane word by word

    cout << "WORDS: ";
    string word;
    while (in >> word)
        cout << word << ' ';

    // khandene line by line
    in.clear();        // resets error flags
    in.seekg(0);    // goes to the first
    /* if we don't write line 49 and 50, then we can't "cout" the lines of the file */
    cout << endl << "LINES: " << endl;
    string line;
    while (getline(in, line))
        cout << line << endl;

    /****************************************/

    // WRITING IN A FILE
    // harchi toosh boode pak mikone & chizaii ke mikhad minevise
    out << "Hello\n"; //out is the name of the file
    out << 123 << " " << 3.14 << "\n";

    /****************************************/

    // FILE MODES
    ofstream yasna("yasna.txt", ios::app);

    /*
    ios::in	    read
    ios::out	write
    ios::app	adding to the end of the file
    ios::trunc	deleting the content
    ios::binary	binary
    ios::ate	going to end of the file after opening
    */

    // tarkibi
    fstream f("file.bin", ios::in | ios::out | ios::binary);

    /****************************************/

    // BINARY

    // writing binary
    int a = 123, x=321;

    ofstream bina("bina.bin", ios::binary);
    bina.write(reinterpret_cast<char*>(&a), sizeof(a));
    bina.write((char*)x, sizeof(x));  // be andaze ye sieof(x) benevis. this function has two inputs: 1. a pointer to a char | 2. andaze be byte
    bina.close();

    // reading binary
    int b;
    ifstream binar("bina.bin", ios::binary);
    binar.read(reinterpret_cast<char*>(&b), sizeof(b));

    /****************************************/

    // MOVING IN FILES

    // for reading
    in.seekg(0);                   // go to the first of the file
    in.seekg(10);                  // go to the 10th byte
    in.seekg(0, ios::end); // go to the end of the file
    in.seekg(2*sizeof(string), ios::cur);  // harkat nesbat be mahale aknoon
    in.seekg(-1); // agab miravad

    in.seekg(5); // az bytee 5th bekhan
    char c;
    in.get(c);
    cout << "char is: " << c;

    // for writing
    out.seekp(5);

    /****************************************/

    // making files with different names
    string fileName = "newFile";
    for (int i = 1; i<4; i++) {
        fileName += to_string(i);
        ofstream kk(fileName+".txt");
    }

    // CLOSING THE FILES
    in.close(); out.close(); binar.close(); binar.close(); f.close(); yasna.close();

    return 0;
}