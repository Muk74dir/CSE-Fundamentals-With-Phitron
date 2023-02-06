#include<stdio.h>

int sumoflast(int i, int t, int arr[])
{
    if (i==t) return 0;
    int s = sumoflast(i+1, t, arr);
    return s + (arr[i]%10);
}
int main()
{
    int t;
    scanf("%d", &t);
    int arr[t];
    for(int i=0; i<t; i++)
        scanf("%d", &arr[i]);
    printf("%d", sumoflast(0, t, arr));
    return 0;
}
