#include<bits/stdc++.h>
using namespace std;

vector<string>merge_sort(vector<string>temp)
{
    if(temp.size() <= 1)return temp;

    int mid = temp.size()/2;
    vector<string>left;
    vector<string>right;
    for(int i = 0; i<mid; i++)
        left.push_back(temp[i]);
    for(int j = mid; j<temp.size(); j++)
        right.push_back(temp[j]);

    vector<string>sorted_left = merge_sort(left);
    vector<string>sorted_right = merge_sort(right);
    vector<string>sorted_temp;

    int ind1 = 0;
    int ind2 = 0;

    for(int k=0; k<temp.size(); k++)
    {
        if(ind1 == sorted_left.size()){
            sorted_temp.push_back(sorted_right[ind2]);
            ind2++;
        }

        else if(ind2 == sorted_right.size()){
            sorted_temp.push_back(sorted_left[ind1]);
            ind1++;
        }

        else if(sorted_left[ind1] <= sorted_right[ind2]){
            sorted_temp.push_back(sorted_left[ind1]);
            ind1++;
        }
        else if(sorted_right[ind2] < sorted_left[ind1]){
            sorted_temp.push_back(sorted_right[ind2]);
            ind2++;
        }

    }

    return sorted_temp;
}




int main()
{
    int t;cin>>t;
    vector<string>input(t);
    for(int i=0; i<t; i++){
        cin>>input[i];
    }
    vector<string> ans= merge_sort(input);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";


    cout<<endl;
    return 0;
}
