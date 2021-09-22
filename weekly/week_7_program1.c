//รับค่าตัวเลข 2 จำนวน เก็บใน x และ y ตามลำดับ จากนั้นให้ทำการสลับค่ากัน โดยห้ามสร้างตัวแปรเพิ่ม (Level 5)
#include<stdio.h>

int main() {

    float x,y;
    printf("Input x : ");
    scanf("%f", &x);
    printf("Input y : ");
    scanf("%f", &y);
    x = x-y;
    y = y+x;
    x = y-x;
    printf("Swap two number\n");
    printf("Output : x = %.2f, y = %.2f",x,y);

    return 0;
}