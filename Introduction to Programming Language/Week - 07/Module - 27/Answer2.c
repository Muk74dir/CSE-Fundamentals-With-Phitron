#include<stdio.h>
#include<math.h>
int i, j;
void sort(int l, int x[]);
int main()
{
    char s[100];
    scanf("%s", &s);
    int l = strlen(s);
    int arr[l];
    for(i=0; i<l; i++){
        arr[i] = s[i];
    }
    sort(l, arr);
    return 0;
}


void sort(int l, int x[])
{
    int i, j, temp, ind=0, val;
    for(i=0; i<l-1; i++){
        val = x[i];
        for(j=i+1; j<l; j++){
            if(val < x[j]){
                ind = j;
                temp = val;
                val = x[j];
            }
            else
                continue;
            x[i] = val;
            x[ind] = temp;
        }
    }

    for(i=0; i<l; i++){
        printf("%c", x[i]);
    }

}
