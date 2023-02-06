#include<bits/stdc++.h>
using namespace std;
class Person{
public:
    string name;
    Person *Father, *Mother;

    Person(){
        Father = NULL;
        Mother = NULL;
    }

    Person(string name)
    {
        this->name = name;
    }
    Person(string name, string f_name, string m_name)
    {
        this->name = name;
        Father = new Person;
        Father->name = f_name;
        Mother = new Person;
        Mother->name = m_name;
    }

    void print()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Father's Name : "<<Father->name<<endl;
        cout<<"Mother's Name : "<<Mother->name<<endl;;
    }

    ~Person() // Destructor
    {
        if(Father != NULL)
            delete Father;
        if(Mother != NULL)
            delete Mother;
    }
};

int main()
{
    Person p("Muktadir", "Akram", "Morzina");
    p.print();
    return 0;
}
