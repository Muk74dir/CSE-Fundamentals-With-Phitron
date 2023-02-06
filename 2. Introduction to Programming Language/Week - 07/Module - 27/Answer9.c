#include<stdio.h>
#include<math.h>
int i, j;
int pcnt(int* p);
double evnav(int t, int *p);
int main()
{
    int t=0, cnt = 0;
    scanf("%d", &t);
    int arr[t];
    for(i=0; i<t; i++)
        scanf("%d", &arr[i]);
    for(i=0; i<t; i++)
        if(pcnt(arr+i) == 0)
            cnt++;
    printf("Prime numbers: %d\n", cnt);
    printf("Average of all even integers: %.2f", evnav(t, arr));
    return 0;
}

int pcnt(int* p)
{
    int val = *p;
    if (val == 2) return 0;
    if (val == 0 || val == 1) return 1;
    for (int i = 2; i <= sqrt(val); i++) {
        if (val % i == 0) return 1;
    }
    return 0;
}

double evnav(int t, int* p)
{
    double avr = 0;
    int cnt = 0;
    for(int i = 0; i<t; i++){
        int* add = p[i];
        int val = add;
        if(val%2==0){
            avr += val;
            cnt++;
        }
    }
    return avr/cnt;
}
