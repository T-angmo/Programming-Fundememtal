// ให้นักศึกษา เขียนโปรแกรม รับ string 1 ชุด แล้ว แสดงผล string โดยถ้ามี ตัวอักษรติดกันซ้ำกัน ให้ตัดออกเหลือเพียง 1 ตัว เช่น
// input : ABCCCDDEFGGGGGGHHHIJKL
// output : ABCDEFGHIJKL

#include<stdio.h>
#include<string.h>

int main() {

    char string[100],*p;
    int lenght = 0,i=0;
    printf("Input : ");
    scanf("%s",string);
    p=string;
    lenght = strlen(string);
    while(*p != '\0') {
        if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            if(*p == *(p+1)) {
                for(int j=i ; j<lenght ; j++) {
                    string[j] = string[j+1];
                }
                i--;
                p--;
            }
        }
        p++;
        i++;
    }
    // for(int i=0 ; i<lenght ; i++) {
    //     if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
    //         if(string[i-1] == string[i]) {
    //             for(int j=i ; j<lenght ; j++) {
    //                 string[j] = string[j+1];
    //             }
    //             i--;
    //         }
            
    //     }
    // }
    printf("Output : ");
    printf("%s",string);

    return 0;
}