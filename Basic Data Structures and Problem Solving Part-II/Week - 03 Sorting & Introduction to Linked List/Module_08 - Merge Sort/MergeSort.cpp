#include<bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int>a){

    //base case :
    if(a.size()<=1)                     //Time Complexity : O (N logN)
        return a;

    int mid = a.size()/2;
    vector<int>left;
    vector<int>right;
    for(int i=0; i<mid; i++)
        left.push_back(a[i]);
    for(int j=mid; j<a.size(); j++)
        right.push_back(a[j]);
    vector<int>sorted_left = merge_sort(left);
    vector<int>sorted_right = merge_sort(right);
    vector<int>sorted_a;
    int ind1 = 0;
    int ind2 = 0;
    for(int k=0; k<a.size(); k++){

        if(ind1 == sorted_left.size()){
            sorted_a.push_back(sorted_right[ind2]);
            ind2++;
        }

        else if(ind2 == sorted_right.size()){
            sorted_a.push_back(sorted_left[ind1]);
            ind1++;
        }

        else if(sorted_left[ind1]<sorted_right[ind2]){
            sorted_a.push_back(sorted_left[ind1]);
            ind1++;
        }
        else if(sorted_right[ind2] < sorted_left[ind1]){
            sorted_a.push_back(sorted_right[ind2]);
            ind2++;
        }

    }
    return sorted_a;
}

int main()
{
    vector<int> x = {1, 2, 6, 3};
    vector<int>ans = merge_sort(x);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}
