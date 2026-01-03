#include <iostream>
#include <vector>
using namespace std;

int main() {

    // defining a vector
    vector<int> v1={1,2,3,4};
    vector<int> v2{6, 7, 8, 9, 10};
    vector<int> vector3(5, 12); //beriz 5 ta 12 ro to vector3


    v1[2] = 300;
    v1.at(3) = 400; // {1,2,300,400}

    int x = 55;
    v2.assign(4,x); //kolan harchi bood ro pak mikone. be tedad 4 ta az adad 55 mirize to v2

    vector3.push_back(89); // be akharin khane ezafe mikone
    v1.pop_back(); // deletes the last index

    // printing a vector
    cout << "vector3 is: ";
    for (int i = 0; i < vector3.size(); i++) {
        cout << vector3[i] << " ,";
    }

    cout << endl << "vector2 is: ";
    for (int num : v2) {
        cout << num << " ,";
    }

    cout << endl << "vector1 is: ";
    for (int num : v1) {
        cout << num << " ,";
    }

    /****************************************/

    double arr[]={1.0, 2.0, 3.0};
    double *pt = arr + sizeof(arr)/sizeof(double); //pointer to the end of array

    vector<double> v4(arr,pt); //. az inja ___ ta inja ___ : This creates a vector<double> using the range [arr, pt), i.e., the entire array.
    vector<double> v5(v4); //copies everything in v4 to v5

    for(double &num: v4) num*=2; //Each element in the vector is multiplied by 2

    cout << endl << "vector4 is: ";
    for (double num : v4)  cout << num << " ,";

    cout << endl << "vector5 is: ";
    for (double num : v5)  cout << num << " ,";

    /****************************************/

    cout << endl<< "address of pointer: " << v5.data(); //address of pointer of the first index
    cout << endl<< "value of the address: " << *v5.data(); //first index

    double *p = v5.data();
    /* p[3] = 4.0; */  // !!!    NO   !!!  hichi jeloye vector5 is chap nemishe
    p[1] = 4.0;
    cout << endl << "vector5 is: ";
    for (double num : v5)  cout << num << " ,";

    /****************************************/

    vector<int> v6 = {20, 21, 22, 23, 24,25,26,27,28,29,30};
    v6.assign(v6.begin()+2,v6.begin()+5); // az [first, last) ro bar midare va dar vaghe trim mikone
    cout << endl << "vector6 is: ";
    for (double num : v6)  cout << num << " ,";
    // assign do model meghdar dehi mishe. dar tarife vector ham hamintor 3 ta nahve dashtim

    // insert kardan
    v6.insert(v6.begin(), 44); // dar position ke behesh midim ezafe mikone
    v6.emplace(v6.begin()+2); // 0 ra insert mikone
    v6.emplace(v6.begin()+3, 77);
    v6.insert( v6.begin()+4 , 4 , 300); // position, tedad, adad

    int array[] = {700, 800, 900, 1000};
    v6.insert(v6.end()-1, array+1, array+3); // copying array to vector. array+1 points to 800 and array+3 points to 1000. so [) and it copies 800 , 900

    vector<int> v7 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    v6.insert(v6.cbegin()+2,v7.begin()+5,v7.begin()+7); //copying a vector to another vector

    //erase
    v6.erase(v6.end());
    v6.erase(v6.begin(), v6.begin()+2);

    v7.swap(v6); //v7  & v6 ro kamel swap mikone

    cout << endl << "vector6 is: ";
    for (double num : v6)  cout << num << " ,";

    cout << endl << "vector7 is: ";
    for (double num : v7)  cout << num << " ,";

    v7.clear(); // pak kardane kamel

    /****************************************/

    // size & capacity

    vector<double> v8 = {1,2,3,4,5,6,7,8,9};
    cout<< "Size of vec8 = "<<v8.size()<<endl;  // tedad anasor vagheie ra neshan midahad
    cout<< "Capacity of vec8 = "<<v8.capacity()<<endl;

    v8.pop_back();
    cout<< "Size of vec8 = "<<v8.size()<<endl;
    cout<< "Capacity of vec8 = "<<v8.capacity()<<endl; // hafeze ii ke vector kolan ja dare va ta jaie ke chizi ezafe konim, nemire hafeze ye dige begire

    v8.push_back(3000);
    v8.push_back(4000);

    cout<< "Capacity of vec8 = "<<v8.capacity()<<endl;

    cout<< "begin of vec8 = "<<v8.begin().base()<<endl; // addresse khooneye aval vector
    cout<< "front of vec8 = "<<v8.front()<<endl; // avalin value dar vector
    cout<< "back of vec8 = "<<v8.back()<<endl; // akarin value dar vector

    cout << "vector 8 is: ";
    for (double num : v8)
        cout << num << ", ";

    /****************************************/

    vector<int> v9 = {1, 2, 3};
    vector<int> v10{60, 70, 80, 90, 100};
    std::copy(v9.begin(), v9.end(),v10.begin()); // jaygozin mikone dar index haye morde nazar

    cout << endl << "vector9 is: ";
    for (int num : v9) cout << num << "  ";
    cout << "\nvector10 is: ";
    for ( int num : v10)
        cout << num << "  ";
    return 0;
}