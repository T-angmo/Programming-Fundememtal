//ให้นักศึกษาเขียนโปรแกรมเพื่อตรวจสอบว่าตัวเลขที่ป้อนเป็นตัวเลขจำนวนเฉพาะหรือไม่
//ถ้าเป็นจำนวนเฉพาะ แสดงผล “Prime Number”ถ้าไม่ใช่จำนวนเฉพาะ แสดงผล “Not Prime Number”
//โดยสร้าง และใช้งานฟังก์ชั่น isPrime()
#include<stdio.h>

int isPrime(int num) {
    int j;
    for(int i=1 ;i<=num ; i++) {
        if(num%i == 0) {
            j++;
        }
    }
    if(j == 2) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {

    int x;
    printf("Enter number : ");
    scanf("%d", &x);
    if(isPrime(x) == 1) {
        printf("Prime Number");
    }
    else {
        printf("Not Prime Number");
    }
    return 0;
}