#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>st;
    string input;cin>>input;

    for(int i=0; i<input.size(); i++)
    {
        char now = input[i];
        if(now == '(' || now == '{' || now == '['){
            st.push(now);
        }
        else
        {
            if(st.empty()){
                st.push(now);
                break;
            }

            else
            {
                if(now == ')' && st.top() == '('){
                    st.pop();
                }
                else if(now == '}' && st.top() == '{'){
                    st.pop();
                }
                else if(now == ']' && st.top() == '['){
                    st.pop();
                }
                else
                    break;
            }
        }
    }

    if(st.empty())cout<<"YES"; else cout<<"NO";

    return 0;
}
