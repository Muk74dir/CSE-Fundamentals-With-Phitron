#include<bits/stdc++.h>
using namespace std;

int main()                              // Time Complexity : O(log n) Memory Complexity : O(n)
{
    int n, k;cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>k;
    int low = 0, high = n-1;
    bool flag = 0;
    while(low<=high){
        int mid = (low+high)/2;

        if(a[mid]==k){
            flag = 1;
            break;
        }
        else if(a[mid]>k){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    if(flag==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}

/*
n
sorted arry
2 3 4 5 6 9 7 10 11 15 16 18 19 24 25 26
k

*/


