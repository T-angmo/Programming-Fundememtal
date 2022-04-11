#include<stdio.h>
int main()
{
    int a,b[1000],i=0;
    printf("Enter number : ");
    scanf("%d", &a);
    int n=2;
    for(;a>1;n++)
    {
        if(a%n == 0)
        {
            a/=n;
            // printf("%d ", n);
            b[i]=n;
            i++;
            n=1;         
        }
    }
    printf("Factoring Result : ");
    for(int j=0;j<i;j++)
    {
        if(j!=0)
        {
            printf(" x ");
        }
        printf("%d", b[j]);
    }

    return 0;
}