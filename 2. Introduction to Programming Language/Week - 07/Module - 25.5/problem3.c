#include<stdio.h>
#include<math.h>

int i, j;

void cost_finder(int l, char x[]);
int power(int x);

int main()
{
    char str[30];
    scanf("%s", &str);
    int l = strlen(str);
    cost_finder(l, str);
    return 0;
}

int power(int x)
{
    int cnt=0;
    while(x>0){
        if(x%2 == 0){
            cnt ++;
            x = x / 2;
        }
        else
            break;
    }
    return cnt;
}

void cost_finder(int l, char x[])
{
    int sum = 0, cnt, dd;
    for(i=0; i<l; i++){
        sum += (x[i] - 96);
    }
    cnt = power(sum);
    dd = pow(2, cnt);
    if(dd == sum)
        printf("YES");
    else
        printf("NO");

}

