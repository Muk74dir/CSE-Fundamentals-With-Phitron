#include<bits/stdc++.h>
using namespace std;

int bi_search(vector<int>a, int n){
    int cnt=0;
    int mid = a.size()/2;
    int low=0, high=a.size()-1;
    while(low<=high){
        mid = (low+high)/2;
        if(n<a[mid]){
            high = mid-1;
        }
        else if(n>a[mid]){
            low = mid + 1;
        }
        else if(n==a[mid]){
            low = mid+1;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int t;cin>>t;
    vector<int>x(t);
    for(int i=0; i<t; i++)
        cin>>x[i];
    int k;cin>>k;
    sort(x.begin(), x.end());
    if(bi_search(x, k)>1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
