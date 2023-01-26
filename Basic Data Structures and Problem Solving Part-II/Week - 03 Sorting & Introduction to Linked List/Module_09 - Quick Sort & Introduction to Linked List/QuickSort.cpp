#include<bits/stdc++.h>
using namespace std;

vector<int> quick_sort(vector<int> a){
    if(a.size()<=1)                 //Time Complexity = O(N logN) USUALLY
        return a;                   //Worst Case = O(n^2), Best Case = O(N logN)
    int pivot = rand()%(a.size());  //a.size()/2 OR a.size()-1;
    vector<int>left, right;
    for(int i=0; i<a.size(); i++){
        if(i==pivot)
            continue;
        else if(a[i]<= a[pivot])
            left.push_back(a[i]);
        else if(a[i] > a[pivot])
            right.push_back(a[i]);
    }
    vector<int>sorted_left = quick_sort(left);
    vector<int>sorted_right = quick_sort(right);

    vector<int>sorted_a;
    for(int j=0; j<sorted_left.size(); j++)
        sorted_a.push_back(sorted_left[j]);

    sorted_a.push_back(a[pivot]);

    for(int k=0; k<sorted_right.size(); k++)
        sorted_a.push_back(sorted_right[k]);

    return sorted_a;
}
int main()
{
    vector<int>x = {2, 3, 1, 3, 5, 6, 3, 12, 4, 2, 4,};
    vector<int>ans = quick_sort(x);
    for(int i=0; i<x.size(); i++)
        cout<<ans[i]<<" ";
}
