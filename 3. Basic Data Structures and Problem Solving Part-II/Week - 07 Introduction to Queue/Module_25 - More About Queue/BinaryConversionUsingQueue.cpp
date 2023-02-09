#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    queue<string>qu;
    qu.push("1");
    string temp = "";
    for(int i=1; i<=n; i++)
    {
//        cout<<"Binary Representation of "<<i<<" is : "<<qu.front()<<endl;
        temp = qu.front();
        qu.pop();
        qu.push(temp + "0");
        qu.push(temp + "1");
    }
    cout<<"Binary Representation of "<<n<<" is : "<<temp<<endl;
    return 0;
}
