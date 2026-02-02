#include <iostream> //header files. they are <compiler directives>
using namespace std; //iostream --> std --> cout, cin...
//reserve words (keywords): the orange words

int main() { //the output is an integer number. that's why we use "int" main
    string name;
    cin >> name;
    cout <<  name << " is green" << endl; //or: std::cout / std::endl
    return 0; //exit successfully. we can return any num we want
}

/*
 different kinds of bugs:
 1. compiler bug
 2. runtime error
 3. logical error
 */