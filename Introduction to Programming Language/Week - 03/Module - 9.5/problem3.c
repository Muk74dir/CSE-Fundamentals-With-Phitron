#include<stdio.h>
int main()
{
    int i, j, n, res=0;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++){
        if(arr[0] != arr[i]){
            res = 1;
        }
        else{
            res = 0;
        }
    }
    if(res==1)
        printf("NO");
    else
        printf("YES");

    return 0;
}
