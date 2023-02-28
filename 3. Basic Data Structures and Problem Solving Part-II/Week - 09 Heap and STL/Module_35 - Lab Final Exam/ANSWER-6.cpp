#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    deque<int>tq;
    int t;cin>>t;
    int temp;
    for(int i=0; i<t; i++)
    {
        cin>>temp;
        if(dq.empty()){
            dq.push_back(temp);
        }

        else if(dq.back() < temp){
            dq.push_back(temp);
        }

        else if(dq.back() > temp){
            while(dq.back() > temp){
                tq.push_back(dq.back());
                dq.pop_back();
            }
            dq.push_back(temp);
        }
    }

    for(int i=0; i<tq.size(); i++){
        dq.push_back(tq.front());
    }


    for(int i=0; i<dq.size(); i++){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }


    return 0;
}
