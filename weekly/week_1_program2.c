#include<stdio.h>
int main()
{
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    if(a>=b && a>=c)
    {
        printf("%f", a);
    }
    else if(b>=a && b>=c)
    {
        printf("%f", b);
    }
    else if(c>=a && c>=b)
    {
        printf("%f", c);
    }
    
    return 0;
}