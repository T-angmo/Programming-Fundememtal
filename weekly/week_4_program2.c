#include<stdio.h>
int main()
{
    int num;
    printf("Enter number of students : ");
    scanf("%d",&num);
    float height[num],avg=0;
    for(int i=0;i<num;i++)
    {
        scanf("%f", &height[i]);
    }
    for(int i=0;i<num;i++)
    {
        printf("Student %d's height : %f\n", i+1, height[i]);
    }
    for(int i=0;i<num;i++)
    {
        avg += height[i];
    }
    avg /=num;
    printf("Average height of all students : %f",avg);
    
    return 0;
}