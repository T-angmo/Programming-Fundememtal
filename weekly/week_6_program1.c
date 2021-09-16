//66. จงเขียนโปรแกรมเพื่อรับข้อมูลเป็น string ไปเรื่อยๆ จนกว่าจะพิมพ์เครื่องหมาย . หลังจากนั้นให้จัดเก็บข้อมูลลงในไฟล์ชื่อ c:\temp\data.txt ดังตัวอย่าง (Level 4)
#include<stdio.h>
#include <stdlib.h>
//#include<conio.h>

int main() {

    char data[1000]; //, data1[1000];
    printf("Input data string : ");
    scanf("%[^.]", data);
    //printf("\n%s\n", data);
    FILE * fptr;
    fptr = fopen("c:tempdata.txt", "w");
    //ถ้าเปิดแฟ้มข้อมูลได้สำเร็จจะให้ค่า file pointer (fp) != NULL
    if(fptr == NULL) {
        printf("Error in open file\n");
        exit(1); //(EXIT_FAILURE);
    }
    fprintf(fptr, "%s", data); //บันทึกข้อมูลลงไฟล์
    fclose(fptr);
        //printf("\nb\n");
    // FILE * fp;
    // fp = fopen("c:tempdata.txt", "r");
    // if(fp == NULL) {
    //     printf("Error in open file\n");
    //     exit(1);
    // }
    // fscanf(fp, "%[^.]", data1); //อ่านข้อมูลตัวแปร data ขึ้นจากไฟล์
    // printf("%s", data1);
    // fclose(fp);
    //printf("Enter contents to store in file : \n");
    //เมื่อปิดไฟล์สำเร็จ fclose() = 0(NULL)
     
    return 0;
}