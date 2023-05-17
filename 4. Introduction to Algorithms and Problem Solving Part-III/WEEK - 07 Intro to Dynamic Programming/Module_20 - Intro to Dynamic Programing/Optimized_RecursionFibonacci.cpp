#include<bits/stdc++.h>
using namespace std;

long long arr[101];
long long fib(int x){            // Time Complexity : O(n); Before it was O(2^n)
    if(x <= 2) return 1;         //=============================================
    if(arr[x] == 0){
        arr[x] = fib(x-1) + fib(x-2);
    }
    return arr[x];
}

int main()
{
    cout<<fib(3)<<endl;
    cout<<fib(5)<<endl;
    cout<<fib(50)<<endl;

    return 0;
}
