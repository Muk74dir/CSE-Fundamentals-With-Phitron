#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream inp;
    inp.open("input.txt");
    ofstream of;
    of.open("output.txt");
    int x, y;
    inp>>x>>y;
    of<<x<<" "<<y;
    return 0;
}
