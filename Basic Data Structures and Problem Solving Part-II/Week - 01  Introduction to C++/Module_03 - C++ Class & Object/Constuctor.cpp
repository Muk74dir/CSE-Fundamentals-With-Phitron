#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int age;
    int id;
    Student(string name, int age, int id)
    {
        this->name = name;
        this->age = age;
        this->id = id;
    }
    void print()
    {
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<id<<endl;
    }


};



int main()
{
    Student s("Muktadir", 22, 22101147);
    s.print();
    return 0;
}
