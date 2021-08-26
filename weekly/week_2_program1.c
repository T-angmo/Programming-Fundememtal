#include<stdio.h>
int main()
{
    float num1,num2,num3;
    scanf("%f %f %f", &num1, &num2, &num3);
    if(num1<num2 && num1<num3)
    {
        if(num2<num3)
        {
            printf("%f", num1+num2);
        }
        else{
            printf("%f", num1+num3);
        }
    }
    else if(num2<num1 && num2<num3)
    {
         if(num1<num3)
        {
            printf("%f", num2+num1);
        }
        else{
            printf("%f", num2+num3);
        }
    }
    else
    {
         if(num1<num2)
        {
            printf("%f", num3+num1);
        }
        else{
            printf("%f", num3+num2);
        }
    }

    return 0;
}