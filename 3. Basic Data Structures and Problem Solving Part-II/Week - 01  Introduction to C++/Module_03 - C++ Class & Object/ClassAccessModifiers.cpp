#include<bits/stdc++.h>
using namespace std;
class Student{
public:
    string name;
protected:
    int age;
protected://if its private no one can access or set this variable.
    int id;
};
class Admin: Student{
public:
    void set(string s, int n, int i){
        name = s;
        age = n;
        id = i;
    }
    void print(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<id;
    }
};


int main()
{
    Admin s;
    s.set("Muktadir", 22, 22101147);
    s.print();
    return 0;
}
