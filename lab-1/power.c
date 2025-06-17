#include<stdio.h>

//a = base, b = power 
int power(int a, int b){
    if(b == 0){
        return 1;
    }
    else{
        return a * power(a, b-1);
    }
}

void main(){
    int base, pow, ans = 1;

    printf("Enetr base value : ");
    scanf("%d", &base);
    printf("Enter power value : ");
    scanf("%d", &pow);

    for(int i=1; i<=pow; i++){
        ans *= base;
    }

    printf("iterative method %d \n", ans);
    printf("recursive method %d", power(base, pow));
}