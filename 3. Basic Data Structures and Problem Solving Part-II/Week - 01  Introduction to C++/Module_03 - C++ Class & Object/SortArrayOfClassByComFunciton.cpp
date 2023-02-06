#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int age;
    int id;

    Student()
    {
    }
    Student(string name, int age, int id)
    {
        this->name = name;
        this->age = age;
        this->id = id;
    }

    void print_details(){
        cout<<name<<" "<<age<<" "<<id<<endl;

    }
};

bool com(Student a, Student b)
{
    //when a less than b
    return a.age < b.age; // not <=
}

int main()
{

    vector<Student>s;
    for(int i=0; i<10; i++)
        s.push_back(Student("Muktadir", 30-i, 45+i));

    for(int j=0; j<10; j++)
        s[j].print_details();
    cout<<endl;

    sort(s.begin(), s.end(), com);

    cout<<"After Sorting"<<endl;
    cout<<endl;

    for(int j=0; j<10; j++)
        s[j].print_details();
    return 0;
}
