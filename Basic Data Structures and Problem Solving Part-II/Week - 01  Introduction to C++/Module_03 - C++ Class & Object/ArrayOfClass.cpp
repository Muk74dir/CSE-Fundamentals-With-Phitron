#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int id;
    int age;

    Student(){}

    Student(string name, int id, int age)
    {
        this->name = name;
        this->id = id;
        this->age = age;
    }

    void print_info()
    {
        cout<<name<<id<<age<<endl;
    }

};

int main()
{
    Student s[10];
    for(int i=0; i<10; i++)
        s[i] = Student("Muktadir", i, 45+i);
    for(int j=0; j<10; j++)
        s[j].print_info();

    return 0;
}
