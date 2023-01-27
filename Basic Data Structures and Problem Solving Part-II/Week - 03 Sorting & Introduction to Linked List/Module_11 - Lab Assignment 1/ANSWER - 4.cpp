#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t1;cin>>t1;
    vector<int>sub(t1);
    for(int i=0; i<t1; i++)
        cin>>sub[i];

    int t2;cin>>t2;
    vector<int>uni(t2);
    for(int j=0; j<t2; j++)
        cin>>uni[j];

    int ind=0, cnt=0;
    for(int k=0; k<t2; k++){
        if(sub[ind] == uni[k] && ind<=sub.size()){
            cnt++;
            ind++;
        }
        else
            ind++;
    }
    if(cnt==sub.size())
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
    return 0;
}
