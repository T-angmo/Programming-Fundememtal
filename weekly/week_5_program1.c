#include<stdio.h>
#include<string.h>

int main() {

    char word[100];
    int lenght = 0;
    printf("Input : ");
    scanf("%s", word);
    for(int i=0 ; i<strlen(word) ;i++) {
        if(word[i] != ' ') {
            lenght++;
        }
    }
    printf("Output :");
    for(int i=lenght-1 ; i>=0 ; i--) {
        printf("%c", word[i]);
    }
    
    return 0;
}