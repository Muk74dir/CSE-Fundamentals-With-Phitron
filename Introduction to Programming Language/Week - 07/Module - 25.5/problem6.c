#include<stdio.h>
#include<math.h>
int sum(int* a, int* b, int* c);
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", sum(&a, &b, &c));
    return 0;
}
int sum(int* a, int* b, int* c)
{
    return *a+*b+*c;
}
