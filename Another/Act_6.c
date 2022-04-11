#include<stdio.h>

void swap(int *a, int *b) {
    int x;
    x = *a;
    *a = *b;
    *b = x;
}

int main() {

    int num1, num2;
    scanf_s("%d %d", &num1, &num2);
    swap(&num1, &num2);
    printf_s("%d %d ", num1, num2);

    return 0;
}