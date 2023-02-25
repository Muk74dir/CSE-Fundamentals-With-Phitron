#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    //Insert = O(Log N)
    mp["Goru"] = 1;
    mp["Chagol"] = 2;
    mp["Bhera"] = 3;

    //Value of a Key
    cout<<mp["Bhera"]<<endl;// O(Log N)

    cout<<"Printing The Map : "<<endl; // O(N)
    for(auto it : mp)
        cout<<"KEY : "<<it.first<<"--> VALUE : "<<it.second<<endl;
    cout<<endl;

    cout<<"SIZE OF MAP : "<<mp.size()<<endl;
    cout<<endl;




    map<int, int>mp2;
    mp2[40] = 3;
    mp2[34] = 123;
    mp2[20] = 34;
    mp2[100] = 1;

    cout<<"Printing The Map : "<<endl; // O(N)
    for (auto it : mp2)
        cout<<"KEY : "<<it.first<<"--> VALUE : "<<it.second<<endl;
    cout<<endl;
    cout<<"SIZE OF MAP : "<<mp2.size()<<endl;
    return 0;
}
