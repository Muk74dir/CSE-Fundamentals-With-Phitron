#include<stdio.h>

int one_finder(int x, char y[]);
int seven_finder(int x, char y[]);
int nine_finder(int x, char y[]);


int main()
{
    char str[1000];
    scanf("%s", str);
    int l = strlen(str);
    if(one_finder(l, str) == 1 && seven_finder(l, str) == 1 && nine_finder(l, str))
        printf("YES");
    else
        printf("NO");
    return 0;
}


int one_finder(int x, char y[])
{
    for(int i = 0; i<x; i++){
        if(y[i] == '1')
            return 1;
    }
    return 0;

}

int seven_finder(int x, char y[])
{
    for(int i = 0; i<x; i++){
        if(y[i] == '7')
            return 1;
    }
    return 0;

}

int nine_finder(int x, char y[])
{
    for(int i = 0; i<x; i++){
        if(y[i] == '9')
            return 1;
    }
    return 0;

}
