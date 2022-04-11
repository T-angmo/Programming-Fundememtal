#include<stdio.h>
int main()
{
    int num1,num2,a[1000],b,i=0;
    printf("Enter first number : ");
    scanf("%d", &num1);
    printf("Enter second number : ");
    scanf("%d", &num2);
    int n=1;
    for(;(n<num1)&&(n<num2);n++)
    {
        if((num1%n == 0)&&(num2%n == 0))
        {
            // printf("%d ", n);
            num1/=n;
            num2/=n;
            // printf(" num1=%d ", num1);
            // printf(" num2=%d ", num2);
            a[i]=n;
            i++;
            n=1;         
        }
    }
    printf("Greatest common divisor = ");
    int c=1;
    for(int j=0;j<i;j++)
    {
        c*=a[j];
    }
    printf("%d", c);

    return 0;
}