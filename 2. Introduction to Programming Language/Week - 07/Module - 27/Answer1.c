#include<stdio.h>
#include<math.h>
int main()
{
    int n, tgl = 0, sum= 0;
    scanf("%d", &n);
    for(int i=1, j=0; i<=n, j<n; i++, j++){
            if(j%3==0){
                if(tgl==0) tgl = 1;
                else tgl = 0;
            }
            if(tgl == 0) sum -= i;
            else sum += i;
    }
    printf("%d", sum);
    return 0;
}

