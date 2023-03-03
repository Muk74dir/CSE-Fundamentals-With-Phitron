#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    deque<int>input;
    deque<int>ans;
    for(int i=0; i<t; i++)
    {
        int temp;cin>>temp;
        input.push_back(temp);
    }
    while(!input.empty()){
        if(input.front() < input.back()){
            ans.push_back(input.front());
            input.pop_front();
        }
        else
        {
            ans.push_back(input.back());
            input.pop_back();
        }
    }

    for(int j=0; j<t; j++){
        cout<<ans.front()<<" ";
        ans.pop_front();
    }

    return 0;
}
