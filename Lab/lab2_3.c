#include<stdio.h>
int main()
{
    int lenght;
    printf("Enter number : ");
    scanf("%d", &lenght);
    for(int i=0;i<lenght;i++)
    {
        printf("*");
    }
    for(int i=0;i<(lenght-2);i++)
    {
        printf("\n*");
        for(int j=0;j<(lenght-2);j++)
        {
            printf(" ");
        }
        printf("*");
    }
    printf("\n");
    for(int i=0;i<lenght;i++)
    {
        printf("*");
    }

    return 0;
}