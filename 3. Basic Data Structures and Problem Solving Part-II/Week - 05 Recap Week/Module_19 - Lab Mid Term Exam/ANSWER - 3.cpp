#include<bits/stdc++.h>
using namespace std;

vector<int> quick_sort (vector<int> a){

    if(a.size()<=1) return a;
    int pivot = rand()%(a.size());
    vector<int>left, right;

    for(int i=0; i<a.size(); i++){
        if(pivot==i)
            continue;
        else if(a[i]>=a[pivot])
            left.push_back(a[i]);
        else if(a[i]<a[pivot])
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



int main(){

    int t;cin>>t;
    vector<int>x(t);
    for(int i=0; i<t; i++)
        cin>>x[i];
    x = quick_sort(x);
    for(int j : x)
        cout<<j<<" ";
    return 0;
}

