#include<stdio.h>
#include<string.h>

int main() {

    char word[100];
    printf("Input : ");
    scanf("%s", word);
    int lenght = strlen(word);
    printf("Output :");
    for(int i=lenght-1 ; i>=0 ; i--) {
        printf("%c", word[i]);
    }
    
    return 0;
}