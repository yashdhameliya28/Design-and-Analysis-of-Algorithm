#include<stdio.h>

void printFibonacci(int a,int b,int n){
    
    if(n == 0){
        return;
    }
    
    int c = a + b;
    printf("%d\t", c);
    printFibonacci(b, c, n-1);    
}

void main(){
    // int n, n1=0, n2=1, n3=1;
    // printf("Enter a number : ");
    // scanf("%d", &n);    
    
    // for(int i=1; i<n-1; i++){
    //     printf("%d, ", n3);
    //     n1 = n2;
    //     n2 = n3;    
    //     n3 = n1 + n2;
    // }
    int a=0, b=1;
    printf("%d\t", a);
    printf("%d\t", b);
    int n = 7;
    printFibonacci(a, b, n-2 );
}