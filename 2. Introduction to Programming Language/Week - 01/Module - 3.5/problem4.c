#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if (80<=a && a<=100){
        printf("A+");
    }
    else if (70<=a && a< 80){
        printf("A");
    }
    else if (60<=a && a< 70){
        printf("A-");
    }
    else if (50<= a && a< 60){
        printf("B");
    }
    else if (40<= a && a< 50){
        printf("C");
    }
    else if (33<=a && a<40){
        printf("D");
    }
    else{
        printf("F");
    }
    getch();
}
