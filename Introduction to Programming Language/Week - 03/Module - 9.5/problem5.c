#include<stdio.h>
int main()
{
    int i, j, n, arr[500], t, res=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &t);
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(arr[i] + arr[j] == t){
                res = 1;
                break;
            }
            else{
                res = 0;
            }
        }
        if(res == 1){
            break;
        }
    }

    if(res == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
