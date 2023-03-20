#include<bits/stdc++.h>
using namespace std;

//Fibonacci By Recursion

int fibo(int ind)
{
    if(ind==0)return 0;
    if(ind==1)return 1;
    return fibo(ind-2) + fibo(ind-1);
}
int main()
{
    int ind;cin>>ind;       //[input = index]
    cout<<fibo(ind)<<endl;  //[output = value of that index in fibonacci series]
    return 0;
}
