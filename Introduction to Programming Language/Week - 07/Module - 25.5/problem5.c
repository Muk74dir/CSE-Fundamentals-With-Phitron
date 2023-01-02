#include<stdio.h>
int sum(int x);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum(n));
    return 0;
}
int sum(int x)
{
    if(x>0)
        return x + sum(x-1);
}
