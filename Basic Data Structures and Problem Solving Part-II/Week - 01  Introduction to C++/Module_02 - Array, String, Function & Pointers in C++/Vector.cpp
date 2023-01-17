#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    for(int i=0; i<5; i++)
        vec.push_back(i);
    for(int j = 0; j<5; j++)
        cout<<vec[j]<<" ";
    cout<<endl;

    vec.insert(vec.begin()+4, 99);
    for(int j = 0; j<vec.size(); j++)
        cout<<vec[j]<<" ";
    cout<<endl;

    vec.erase(vec.begin()+0);
    for(int j = 0; j<vec.size(); j++)
        cout<<vec[j]<<" ";
    cout<<endl;

    vec.pop_back();
    vec.pop_back();
    for(int j = 0; j<vec.size(); j++)
        cout<<vec[j]<<" ";
    cout<<endl;

    vec.resize(10);
    for(int j = 0; j<vec.size(); j++)
        cout<<vec[j]<<" ";
    cout<<endl;

    vec.resize(2);
    for(int j = 0; j<vec.size(); j++)
        cout<<vec[j]<<" ";

    return 0;
}
