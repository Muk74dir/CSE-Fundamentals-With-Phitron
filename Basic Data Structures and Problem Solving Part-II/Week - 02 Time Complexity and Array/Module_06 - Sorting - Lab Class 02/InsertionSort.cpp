#include<bits/stdc++.h>
using namespace std;

int main()                          //Time Complexity : O(n^2)
{                                   //Memory Complexity : O(n)
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int j=0; j<n; j++){         // [3 4 1 2 7 6 1]
        int val = a[j];             //  3
        int ind = j;                // 0
        for(int k=j+1; k<n; k++){
            if(val > a[k]){
                val = a[k];
                ind = k;
            }
            int temp = a[ind];
            a[ind] = a[j];
            a[j] = temp;
        }
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}
