#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int roll;
    int id;

    void printd()
    {
        cout<<name<<" "<<roll<<" "<<id<<endl;
    }

};


int main()
{
    Student s1;
    s1.name = "Muktadir";
    s1.roll = 25;
    s1.id = 22101147;
    s1.printd();
    Student s2;
    s2.name = "Mostafizur";
    s2.roll = 26;
    s2.id = 23101145;
    s2.printd();

    return 0;
}
