#include<stdio.h>
int main() {

    int x,a[1000],sum,i,j;
    for(x=1 ; x<=10000 ; x++) {
        for(i=1,j=0,sum=0 ; i<x ; i++) {
            if(x%i == 0) {
                sum += i;
                j++;                
            }
        }
        if(sum == x) {
            printf("%d ",x);
        }
    }
    return 0;
}