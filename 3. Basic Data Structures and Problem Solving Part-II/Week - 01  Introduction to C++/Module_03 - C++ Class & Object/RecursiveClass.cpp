#include<bits/stdc++.h>
using namespace std;
class Person{
public:
    string name;
    Person *Father, *Mother;

    void print()
    {
        cout<<"Name : "<<name<<"\n"<<"Father's Name : "<<Father->name<<"\n"<<"Mother's Name : "<<Mother->name;
    }
};

int main()
{
    Person info;
    info.Father = new Person;
    info.Mother = new Person;
    info.name = "Muktadir";
    info.Father->name = "Akram";
    info.Mother->name = "Morzina";
    info.print();
    return 0;
}
