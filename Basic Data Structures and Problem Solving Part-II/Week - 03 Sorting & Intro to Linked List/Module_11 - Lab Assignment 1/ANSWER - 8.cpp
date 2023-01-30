#include<bits/stdc++.h>
using namespace std;

vector<int>even_generator(vector<int>a){
    vector<int>ans;
    for(int i=0; i<a.size(); i++){
        if(a[i]%2==0){
            ans.push_back(a[i]);
        }
    }
    return ans;
}
int main()
{
    vector<int>x = {5, 4, 2, 8, 10};
    vector<int>ans = even_generator(x);
    for(int j=0; j<ans.size(); j++)
        cout<<ans[j]<<" ";
    return 0;
}
