#include<stdio.h>
#include<string.h>

int main() {

    char string[100];
    int n=0,integer,status=0;
    printf("Input : ");
    scanf("%s", string);
    printf("Output : ");
    for(int i=0 ; i<strlen(string) ; i++) {
        if(string[i]=='0' && n == 0) {
            status = 1;
        }
        else if(string[i]>='0' && string[i]<='9') {
            // printf("-a\n");
            integer = string[i]-'0';
            n = (n*10)+integer;
            status = 0;
            // printf("n=%d\n",n);
        }
        else if((string[i]>='a' && string[i]<='z') || (string[i]>='A' && string[i]<='Z')) {
            if(n==0 && status==0) {
                // printf("-b\n");
                printf("%c", string[i]);
            }
            else if(n>0 && status==0) {
                //printf("-c\n");
                for(int j=0 ; j<n ; j++) {
                    printf("%c", string[i]);
                }
            }
            n=0;
        }
    }
    
    return 0;
}