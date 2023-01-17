#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=5, b=3;
    swap(a, b);
    cout<<a<<" "<<b;
    cout<<endl;
    cout<<min(a, b)<<endl;
    cout<<max(a, b)<<endl;

    vector<int>vec = {2,4,5, 6, 3, 1, 7, 12, 3, 5};
    cout<<min({2,4,5, 6, 3, 1, 7, 12, 3, 5})<<endl;

    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;

    sort(vec.begin(), vec.begin()+6);
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;

    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";

    return 0;
}
