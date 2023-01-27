#include<bits/stdc++.h>
using namespace std;

int cnt=0, n, k;
vector<int>merge_sort(vector<int>a){
    if(a.size()<=1)return a;
    int mid = a.size()/2;
    vector<int>left, right;
    for(int i=0; i<mid; i++)
        left.push_back(a[i]);
    for(int j=mid; j<a.size(); j++)
        right.push_back(a[j]);
    vector<int>sorted_left = merge_sort(left);
    vector<int>sorted_right = merge_sort(right);
    vector<int>sorted_a;

    int idx=0, idx2=0;
    for(int i=0; i<a.size(); i++){
        if(sorted_left.size() == idx){
            sorted_a.push_back(sorted_right[idx2]);
            idx2++;
        }
        else if(sorted_right.size() == idx2){
            sorted_a.push_back(sorted_left[idx]);
            idx++;
        }
        else if(sorted_left[idx] <= sorted_right[idx2]){
            sorted_a.push_back(sorted_left[idx]);
            idx++;
        }
        else if(sorted_right[idx2] < sorted_left[idx]){
            sorted_a.push_back(sorted_right[idx2]);
            idx2++;
        }
    }
    if(sorted_a.size() == n){
        int l=0, r=n-1;
        while(l<r){
            if(sorted_a[l]+sorted_a[r]<k)
                l++;
            else if(sorted_a[l]+sorted_a[r]>k)
                r--;
            else if(sorted_a[l]+sorted_a[r]==k){
                cnt++;
                l++;
                r--;
            }
            if(l==r)break;
        }
    }
    return sorted_a;
}
int main()
{
    cin>>n;
    vector<int>x(n);
    for(int i=0; i<n; i++)
        cin>>x[i];
    cin>>k;
    merge_sort(x);
    cout<<cnt<<endl;
    return 0;
}
