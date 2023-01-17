#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ABCDEF";

    cout<<s<<endl;
    cout<<s.size()<<endl;

    s.pop_back();
    cout<<s<<endl;

    s.erase(s.begin()+2);
    cout<<s<<endl;

    string s2 = "XYZ";
    cout<<s+s2<<endl;
    cout<<(s+s2)[4]<<endl;

    return 0;
}
