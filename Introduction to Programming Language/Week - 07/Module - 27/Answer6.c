#include<stdio.h>
int i, j;
int div3(int x);
int div5(int x);
int main()
{
    int t, cnt=0;
    scanf("%d", &t);
    int arr[t];
    for(i=0; i<t; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<t; i++){
        if(div3(arr[i])==1 || div5(arr[i])==1)
            cnt++;
        else
            continue;
    }
    if(cnt==0)
        printf("%d", -1);
    else
        printf("%d", cnt);

    return 0;
}

int div3(int x)
{
    if(x%3==0)
        return 1;
    else
        return -1;
}

int div5(x)
{
    if(x%5==0)
        return 1;
    else
        return -1;
}
