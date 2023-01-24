#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;                         //Time Complexity : O(n^2)
    vector<int>a(n);                      //Memory Complexity : O(n)
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int j=0; j<n-1; j++){
        bool ext = true;
        for(int k=0; k<n-1-j; k++){
            if(a[k]>a[k+1]){
                swap(a[k], a[k+1]);
                ext = false;
            }
        }
        if(ext)
            break;
        cout<<"STEP "<<j<<" : ";
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"After Sorting"<<endl;
    for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
    return 0;
}
