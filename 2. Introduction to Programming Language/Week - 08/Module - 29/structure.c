#include<stdio.h>

struct Student{
    int age;
    int roll;
    char name[50];
    float weight;

};

struct StudentArr{
    float weight; // sizeof(float) > sizeof(int);
    int roll;
};

int main()
{
    struct Student s = {12,"Muktadir", 24, 65.5};
    printf("%d %s %d %.2f\n", s.roll, s.name, s.age, s.weight);

    struct Student s2 = {.roll = 22, .weight = 66.4, .age = 23, .name = "Muk74dir"}; // designated
    printf("%d %s %d %.2f\n", s2.roll, s2.name, s2.age, s2.weight);

    struct StudentArr s3[10];
    for(int i=0; i<5; i++){
        s3[i].roll = 12+i;
        s3[i].weight = 45.4 + 0.9*i;
    }
    for(int i=0; i<5; i++){
        printf("%d %f\n", s3[i].roll, s3[i].weight);
    }

    return 0;
}
