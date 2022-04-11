#include<stdio.h>
int main() {

    int n,i,j,k;
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++) {
        for(j=0 ; j<i ;j++) {
            printf("* ");
        }
        for(k=0 ; k<2*(n-i)-1 ; k++) {
            if(i!=n) {
                printf("  ");
            }
        }
        if(i!=n) {
            for(j=0 ; j<i ;j++) {
                printf("* ");                
            }
        }
        if(i==n) {
            for(j=1 ; j<i ;j++) {
                printf("* ");
            }
        }
        printf("\n");
    }
    for(i=n-1 ; i>0 ; i--) {
        for(j=0 ; j<i ;j++) {
            printf("* ");
        }
        for(k=0 ; k<2*(n-i)-1 ; k++) {
            printf("  ");
        }
        for(j=0 ; j<i ;j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}