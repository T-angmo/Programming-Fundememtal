//66. จงเขียนโปรแกรมเพื่อรับข้อมูลเป็น string ไปเรื่อยๆ จนกว่าจะพิมพ์เครื่องหมาย . หลังจากนั้นให้จัดเก็บข้อมูลลงในไฟล์ชื่อ c:\temp\data.txt ดังตัวอย่าง (Level 4)
#include<stdio.h>
#include<stdlib.h>

int main() {

    char data[1000],data1[1000];
    printf("Input data string : ");
    scanf("%[^.]", data);
    FILE*fp;
    fp = fopen("c:tempdata.txt","w");
    if(fp != NULL) {
        fprintf(fp,"%s", data);
        fclose(fp);
        printf("Successfully");
    }

    // FILE * fptr;
    // fptr = fopen("c:tempdata.txt", "r");
    // if(fptr == NULL) {
    //     printf("Error in open file\n");
    //     exit(1);
    // }
    // fscanf(fptr, "%[^.]", data1); //อ่านข้อมูลตัวแปร data ขึ้นจากไฟล์
    // printf("%s", data1);
    // fclose(fptr);
    
    return 0;
}