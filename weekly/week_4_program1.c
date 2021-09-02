#include<stdio.h>
int main()
{
    float s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,avg;
    scanf("%f", &s1);
    scanf("%f", &s2);
    scanf("%f", &s3);
    scanf("%f", &s4);
    scanf("%f", &s5);
    scanf("%f", &s6);
    scanf("%f", &s7);
    scanf("%f", &s8);
    scanf("%f", &s9);
    scanf("%f", &s10);
    printf("Student1's height : %f",s1);
    printf("\nStudent2's height : %f",s2);
    printf("\nStudent3's height : %f",s3);
    printf("\nStudent4's height : %f",s4);
    printf("\nStudent5's height : %f",s5);
    printf("\nStudent6's height : %f",s6);
    printf("\nStudent7's height : %f",s7);
    printf("\nStudent8's height : %f",s8);
    printf("\nStudent9's height : %f",s9);
    printf("\nStudent10's height : %f",s10);
    avg = (s1+s2+s3+s4+s5+s6+s7+s8+s9+s10)/10;
    printf("\nAverage height of all students : %f",avg);

    return 0;
}