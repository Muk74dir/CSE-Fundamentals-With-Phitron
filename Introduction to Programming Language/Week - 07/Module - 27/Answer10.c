#include<stdio.h>
#include<math.h>

int svn_findr(int* p);

int main()
{
    int t, cnt= 0;
    scanf("%d", &t);
    int arr[t];
    for(int i=0; i<t; i++){
        scanf("%d", &arr[i]);
    }
    for(int j =0; j<t; j++){
        if(svn_findr(arr+j)==0)
            cnt++;
    }
    if(t%2==0){
        if(cnt>=t/2)
            printf("Beautiful\n");
        else
            printf("Ugly\n");
    }
    else{
        if(cnt>= (t/2)+1)
            printf("Beautiful\n");
        else
            printf("Ugly\n");
    }
    return 0;
}

int svn_findr(int* p)
{
    int* add = p;
    int val = *add;
    while(val>0){
        int temp = val%10;
        if(temp % 7 == 0)
            return 0;
        else
            val /= 10;
    }
    return 1;
}
