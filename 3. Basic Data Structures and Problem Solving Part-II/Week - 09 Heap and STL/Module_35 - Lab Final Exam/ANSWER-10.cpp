#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    set<int>st;
    int temp;
    for(int i = 0; i<t; i++){
        cin>>temp;
        st.insert(temp);
    }

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>temp;
        st.insert(temp);
    }

    for(auto it = st.begin(); it!= st.end(); it++){
        cout<<*it<<" ";
    }

    return 0;
}
