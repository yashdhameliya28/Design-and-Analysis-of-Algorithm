#include<stdio.h>
// #define A 12 

int countDigit(int n, int count){
    
    if(n == 0){
        return count;
    }
    else{
        return count + countDigit(n / 10, count++);
    }
}

void main(){
    int count = 0, n;
    printf("Enter a number : ");
    scanf("%d", &n);

    // while(n != 0){
    //     count++;
    //     n = n/10;
    // }

    // printf("%d", A);
    printf("iterative method %d \n", count);
    printf("recursive method %d", countDigit(n, 0));
}