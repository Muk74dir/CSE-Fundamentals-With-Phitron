#include<bits/stdc++.h>
using namespace std;

int main()
{                                   // Sieve Complexity : O( nlogn )
    int n;cin>>n;
    vector<int>primes;
    vector<bool>visited(n);
    for(int i=2; i<n; i++){
        for(int j=2; j*i<n; j++)
            visited[j*i] = true;
        if(!visited[i])             // if(visited[i] == false)
            primes.push_back(i);
    }
    cout<<primes.size()<<endl;
    for(int m=0; m<primes.size(); m++)
        cout<<primes[m]<<" ";
    cout<<endl;
    return 0;
}
