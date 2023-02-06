#include<bits/stdc++.h>
using namespace std;

int main()
{
    string brac;
    cin>>brac;

    stack<char>st;

    for(int i=0; i<brac.size(); i++){
        char now = brac[i];
        if(now == '(' || now == '{' || now == '['){
            st.push(now);
        }
        else{
            if(st.empty()){
                cout<<"INVALID"<<endl;
                return 0;
            }
            if(st.top() == '(' && now == ')')
                st.pop();
            else if(st.top()=='{' && now == '}')
                st.pop();
            else if(st.top() == '[' && now == ']')
                st.pop();
            else{
                cout<<"INVALID"<<endl;
                return 0;
            }
        }
    }
    if(st.empty())
        cout<<"VALID"<<endl;
    else
        cout<<"INVALID"<<endl;

    return 0;
}
