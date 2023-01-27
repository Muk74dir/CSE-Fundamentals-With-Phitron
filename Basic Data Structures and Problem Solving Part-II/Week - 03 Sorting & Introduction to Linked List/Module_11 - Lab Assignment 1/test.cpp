#include<bits/stdc++.h>
using namespace std;
int count = 0;
vector<int> merge_sort(vector<int>a, int k, int count){
    if(a.size()<=1)return a;
    int mid = a.size()/2;
    vector<int>left, right;

    for(int i=0; i<mid; i++)
        left.push_back(a[i]);
    for(int j=mid; j<a.size(); j++)
        right.push_back(a[j]);

    int left_count = 0, right_count = 0;
    vector<int>sorted_left = merge_sort(left, k, left_count);
    vector<int>sorted_right = merge_sort(right, k, right_count);
    vector<int>sorted_a;

    int idx=0, idx2=0;
    while(idx < sorted_left.size() && idx2 < sorted_right.size()){
        if(sorted_left[idx] + sorted_right[idx2] == k){
            count++;
            idx++;
            idx2++;
        }
        else if(sorted_left[idx] + sorted_right[idx2] < k){
            idx++;
        }
        else{
            idx2++;
        }
    }

    int i = 0, j = 0;
    for(int k = 0; k < a.size(); k++){
        if(i < sorted_left.size() && j < sorted_right.size()){
            if(sorted_left[i] < sorted_right[j]){
                sorted_a.push_back(sorted_left[i]);
                i++;
            }
            else{
                sorted_a.push_back(sorted_right[j]);
                j++;
            }
        }
        else if(i < sorted_left.size()){
            sorted_a.push_back(sorted_left[i]);
            i++;
        }
        else if(j < sorted_right.size()){
            sorted_a.push_back(sorted_right[j]);
            j++;
        }
    }

    return sorted_a;
}
int main()
{
    int n, k;
    cin>>n;
    vector<int>x(n);
    for(int i=0; i<n; i++)
        cin>>x[i];
    cin>>k;
    x = merge_sort(x, k, count);
    cout<<count;
}

