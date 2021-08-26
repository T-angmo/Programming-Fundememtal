#include<stdio.h>

int main()
{
    int i;
    printf("Enter number: ");
    scanf("%d", &i);
    int num[i],num1[i];
    for(int j=0;j<i;j++)
    {
        scanf("%d", &num[j]);
        num1[j]=num[j];
    }
    for(int k=1;k<i;k++)
    {
        if(num[k-1]<num[k])
        {
            num[k]=num[k-1];
        }
    }
    int a=num[i-1];
    printf("a=%d\n", a);
    // for (int z = 0; z < i; z++)
    // {
    //     printf("%d ", num[z]);
    // }
    // printf("\n");
    // for (int x = 0; x < i; x++)
    // {
    //     printf("%d ", num1[x]);
    // }
    // int b;
    int count = 0;
    int check = 0;
    for(int m=0;m<i;m++)
    {
        if(num1[m]==a && check == 0)
        {  
            check++;
        }
        else
        {
            num1[count++] = num1[m];
        }  
    }
    for(int k=1;k<(i-1);k++)
    {
        if(num1[k-1]<num1[k])
        {
            num1[k]=num1[k-1];
        }
    }
    int b=num1[i-2];
    printf("b=%d\n", b);
    printf("%d", a+b);

    return 0;
}