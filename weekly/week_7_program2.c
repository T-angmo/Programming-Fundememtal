//รับค่าตัวเลข 2 จำนวน เก็บใน x และ y ตามลำดับ จากนั้นให้ทำการสลับค่ากัน โดยห้ามสร้างตัวแปรเพิ่ม (Level 5)
//XOR operator
#include<stdio.h>

void swapWithXOR (int a,int b) {
    a = a^b;
    b = a^b;
    a = a^b;
    printf("Output : x = %d, y = %d",a,b);
}

int main () {

    int x,y;
    printf("Input x : ");
    scanf("%d", &x);
    printf("Input y : ");
    scanf("%d", &y);
    printf("Swap two number\n");    
    swapWithXOR(x,y);

    return 0;
}