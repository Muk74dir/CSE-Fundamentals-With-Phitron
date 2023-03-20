#include<bits/stdc++.h>
using namespace std;

bool is_palin(string str)
{
    if(str == "" || str.size() == 1){
        return true;
    }
    string sub = str.substr(1, str.size()-2);
    return is_palin(sub) && ( str[0] == str.back() );
}

int main()
{
    string str;cin>>str;
    cout<<( is_palin(str) ? "YES" : "NO" )<<endl;
    return 0;
}

