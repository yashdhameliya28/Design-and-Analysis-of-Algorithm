#include<stdio.h>

int sumOfN(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n + sumOfN(n-1);
    }
}

void main(){
    int n, sum = 0;
    
    printf("Enter a number : ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        sum += i;
    }

    printf("iterative method %d \n", sum);
    printf("recursive method %d", sumOfN(n));
}