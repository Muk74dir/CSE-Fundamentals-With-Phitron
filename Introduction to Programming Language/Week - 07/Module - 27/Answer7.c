#include<stdio.h>
void swaper(int* p, int l,int r);
int main()
{
    int n, t, l, r;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &t);
    for(int j=0; j<t; j++){
        scanf("%d %d", &l, &r);
        swaper(arr, l-1, r-1);
    }
    for(int i=0; i<n; i++)
            printf("%d ", arr[i]);
    return 0;
}

void swaper(int* p, int l, int r)
{
    int* pl = p+l;
    int* pr = p+r;
    int temp;
    temp = *pr;
    *pr = *pl;
    *pl = temp;
}
