#include<stdio.h>

void oton(int n)
{
    if(n==0) return 0;
    oton(n-1);
    printf("%d ", n);
}
int main()
{
    int n;
    scanf("%d", &n);
    oton(n);
    return 0;
}
