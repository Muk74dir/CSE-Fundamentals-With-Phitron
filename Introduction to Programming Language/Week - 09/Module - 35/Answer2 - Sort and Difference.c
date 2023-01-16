#include<stdio.h>
#include<stdbool.h>
int main()
{
    int t;
    scanf("%d", &t);
    int asnd[t];
    int dsnd[t];
    for(int i=0; i<t; i++)
        scanf("%d", &asnd[i]);
    for(int i=0; i<t; i++)
        scanf("%d", &dsnd[i]);

    int i, j, temp, ind=0, val;
    for(i=0; i<t-1; i++){
        val = asnd[i];
        for(j=i+1; j<t; j++){
            if(val > asnd[j]){
                ind = j;
                temp = val;
                val = asnd[j];
            }
            else
                continue;
            asnd[i] = val;
            asnd[ind] = temp;
        }
    }

    for(i=0; i<t-1; i++){
        val = dsnd[i];
        for(j=i+1; j<t; j++){
            if(val < dsnd[j]){
                ind = j;
                temp = val;
                val = dsnd[j];
            }
            else
                continue;
            dsnd[i] = val;
            dsnd[ind] = temp;
        }
    }

    for(int k=0; k<t; k++)
        printf("%d ", asnd[k] - dsnd[k]);


    return 0;
}
