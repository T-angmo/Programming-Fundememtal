#include<stdio.h>
int main()
{
    int num,sum=0;
    scanf("%d",&num);
    while(num>9)
    {
        while(num>0)
        {
            sum+=num%10;
	        num/=10;
        }
        num=sum;
        sum=0;
    }
    printf("%d",num);

    return 0;
}