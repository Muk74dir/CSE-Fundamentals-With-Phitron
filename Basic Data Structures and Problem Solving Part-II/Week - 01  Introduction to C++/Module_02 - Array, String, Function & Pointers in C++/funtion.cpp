#include<bits/stdc++.h>
using namespace std;
void swap_copy(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    cout<<x<<" "<<y<<endl;
}
void swap_main(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout<<a<<" "<<b<<endl;
}

int main()
{
    int x, y;
    cin>>x>>y;
    cout<<"Changing only in function"<<endl;
    swap_copy(x, y);
    cout<<x<<" "<<y<<endl;

    cout<<"Changing in main function also"<<endl;
    swap_main(x, y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
