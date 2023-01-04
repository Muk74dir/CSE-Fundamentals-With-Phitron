Answer - 1 :

#include<stdio.h>
int main()
{
    char str[20];
    scanf("%s", &str);
    int l = strlen(str);
    for(int i=0; i<l; i++)
    {
        if(str[i]>=65 && str[i]<=90)
            str[i] += 32;
        else
            str[i] -= 32;
    }
    printf("%s", str);
    return 0;
}
