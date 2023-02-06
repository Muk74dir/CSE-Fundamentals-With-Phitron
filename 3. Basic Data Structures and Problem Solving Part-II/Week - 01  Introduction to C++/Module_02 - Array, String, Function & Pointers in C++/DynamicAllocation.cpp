#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int *ptr = new int [x];
    cout<<ptr<<endl;
    int *y = &x;
    cout<<*y<<endl;
    for(int i=0; i<x; i++)
        cin>>ptr[i];
    for(int j=0; j<x; j++)
        cout<<ptr[j]<<" ";
    cout<<endl;
    for(int j=0; j<x; j++)
        cout<<*(ptr+j)<<" ";
    delete[] ptr;
    return 0;
}
