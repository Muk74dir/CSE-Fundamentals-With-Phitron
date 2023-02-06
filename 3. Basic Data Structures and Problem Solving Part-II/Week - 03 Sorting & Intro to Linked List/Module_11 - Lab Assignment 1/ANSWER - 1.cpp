#include<bits/stdc++.h>
using namespace std;

vector<int> quick_sort(vector<int> a){
    int pivot = a.size()/2;
    if(a.size()<= 1)
        return a;

    vector<int>left, right;

    for(int i=0; i<a.size(); i++){
        if(i==pivot)
            continue;
        else if(a[i]<=a[pivot])
            left.push_back(a[i]);
        else
            right.push_back(a[i]);
    }

    vector<int>sorted_left = quick_sort(left);
    vector<int>sorted_right = quick_sort(right);
    vector<int>sorted_a;

    for(int i=0; i<sorted_left.size(); i++)
        sorted_a.push_back(sorted_left[i]);

    sorted_a.push_back(a[pivot]);

    for(int j=0; j<sorted_right.size(); j++)
        sorted_a.push_back(sorted_right[j]);

    return sorted_a;
}

int main()
{
    int t;cin>>t;
    vector<int>x(t);
    for(int i=0; i<t; i++)
        cin>>x[i];
    x = quick_sort(x);
    for(int j=t-1; j>=0; j--)
        cout<<x[j]<<" ";
    return 0;
}

