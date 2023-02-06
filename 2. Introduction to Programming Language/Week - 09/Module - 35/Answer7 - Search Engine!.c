#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t, cnt=1;
    scanf("%d", &t);
    while(cnt<=t){
        int n, p;
        scanf("%d", &n);
        int arr[n];
        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &p);
        if(search(n, arr, p) != 0)printf("Case %d: %d\n",cnt, search(n, arr, p));
        else printf("Case %d: Not Found\n", cnt);
        cnt++;
    }
    return 0;
}

int search(int n, int arr[], int p)
{
    for(int i=1; i<=n; i++)
        if(p == arr[i]) return i;
    return 0;
}
