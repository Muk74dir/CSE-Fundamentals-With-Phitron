#include<stdio.h>
int tothepow (int n, int m)
{
    if(m==0) return 1;
    return n * tothepow(n, m-1);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = tothepow(n, m);
    printf("%d", ans);
    return 0;
}
