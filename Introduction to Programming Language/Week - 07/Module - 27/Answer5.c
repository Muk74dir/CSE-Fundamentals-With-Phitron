#include <stdio.h>
int i, j;
int sumof_evod(int t, int arr[]);
int main()
{
    int t, n;
    scanf("%d", &t);
    int arr[t];
    for(i=1; i<=t; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d",sumof_evod(t, arr));
}

int sumof_evod(int t, int arr[])
{
    int sum=0;
    for(i=1, j=2;i<=t, j<=t;i+=2, j+=2){
        if(arr[j]%2 == 0 && arr[j]>0)
            sum += arr[j] + j;
        if(arr[i]%2 != 0 && arr[i]>0)
            sum += arr[i] + i;
    }
    return sum;
}
