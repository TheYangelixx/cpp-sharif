#include <iostream>
#include <map>
using namespace std;

int main() {

    /* defining map */
    map<string, int> mp;  //  string --> kelid     int --> meghdar       engar mesle dictionary dar python hast

    // mohem nist key meghdar midim. map khodesh moratab sazi anjam mide. masalan inja bar hasbe alphabete kelid(string)
    mp["one"]=1;
    mp["two"]=2;
    mp["three"]=3;
    mp["four"]=4;
    mp.insert(pair<string,int>("five", 5)); // ino be map ezafe mikone. agar type ha ke dar <> tarif kardim barabare type haye asli dar taarife map nabashad, error mide
    mp["eleven"]=11;
    cout<< "size=" <<mp.size()<<endl; // tedad ozv ha

    /* printing a map */
    for(const auto& i:mp)       // age const / & nazarim chi mishe?
    {
        cout<<i.first<<":"<<i.second<<endl;
    }
    cout << endl;
    /*************************************************************************/

    /* searching in a map */

    auto it=mp.begin(); // points to the first pair in the map and mp.end() points ONE PAST the last pair in the %map
    /* cout << typeid(*it).name() << endl; ----->  St4pairIKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE  */
    while(it!=mp.end())   // chon mp.end() point mikone be yeki baade akharin zoje map, in halghe ta akhare map ro mire
    {
        cout<<"Key="<< it->first;
        cout<<", Value="<< it->second << endl;
        it++;
    }
    cout << endl;

    string str="eleven";
    /* find function be harf small and capital hasase */
    if(mp.find(str)!=mp.end()) // ta akhar rafti, didi nist
        cout<<"Found: key="<<str<<"-> value="<<mp[str]<<endl<<endl;  //map[key] = value
    else
        cout<<str<<": Not found as a key\n\n";

    /* khat haye 32 ta 35 ro mishe in shekli ham nevesht (47 --> 55) */
    // auto ind=mp.begin();
    // for (int i=0; i< mp.size(); i++) {
    //     if (ind->first == str) {
    //         cout<<"Found: key="<<str<<"-> value="<<mp[str]<<endl;
    //         break;
    //     }
    //     else
    //         cout<<str<<": Not found as a key\n";
    // }

    /*************************************************************************/

    /* deleting sth from a map */
    it = mp.find("two");
    if(it!=mp.end())
        mp.erase(it);
    cout<<"size="<<mp.size()<<endl;


    /* clear everything*/
    cout << sizeof(mp) << endl;  // 48
    mp.clear(); // deletes everything
    cout<<"size after mp.clear()="<<mp.size()<<endl;
    cout << sizeof(mp) << endl; // 48 hamchenan baade clear kardan
    if(mp.empty())
    {
        cout<<"The map is empty\n\n";
    }

    return 0;
}