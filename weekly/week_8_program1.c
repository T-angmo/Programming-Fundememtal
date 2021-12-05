// 75.จงเขียนโปรแกรมหาค่า x + y โดยรับมาจาก “a.txt” และแสดงใน “b.txt” (Level 4)
// a.txt    b.txt
// 5 5      10
// 6 2      8

#include<stdio.h>
#include<stdlib.h>

int main() {

    int x, y, x1, y1, sum;
    char num[50];
    printf("Enter value x : ");
    scanf("%d", &x);
    printf("Enter value y : ");
    scanf("%d", &y);
    // printf("x %d\n", x);
    // printf("y %d\n", y);

    FILE *fp;
    //เก็บค่า x y ใน a.txt
    fp = fopen("a.txt", "w");
    itoa(x, num, 10);   //itoa(int, char, int base) //int to char
    fputs(num, fp);
    fputs("\n", fp);
    // printf("num x %s\n", num);
    itoa(y, num, 10);
    fputs(num, fp);
    // printf("num y %s\n", num);
    fclose(fp);

    //อ่านค่า x y จาก a.txt
    fp = fopen("a.txt", "r");
    fscanf(fp, "%s", num);
    x1 = atoi(num);     //int = atoi(char)  //char to int
    fscanf(fp, "%s", num);
    y1 = atoi(num);
    fclose(fp);
    // printf("x1 %d\n", x1);
    // printf("y1 %d\n", y1);

    //คำนวณ
    sum = x1 + y1;

    FILE *fptr;
    //เก็บค่า sum ใน b.txt
    fptr = fopen("b.txt", "w");
    itoa(sum, num, 10);
    fputs(num, fptr);
    fclose(fptr);

    //อ่านค่า sum จาก b.txt
    fptr = fopen("b.txt", "r");
    fscanf(fptr, "%s", num);
    sum = atoi(num);
    fclose(fptr);

    //แสดงค่าที่อ่านได้จาก b.txt
    printf("Read from b.txt = %d", sum); 

    return 0;
}