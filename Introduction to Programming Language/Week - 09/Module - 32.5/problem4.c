#include<stdio.h>

void ntoo(int n)
{
    if(n==0) return 0;
    printf("%d ", n);
    ntoo(n-1);
}
int main()
{
    int n;
    scanf("%d", &n);
    ntoo(n);
    return 0;
}
