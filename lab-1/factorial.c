#include<stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
       return n *factorial(n - 1);
    }
}

void main(){
    int n, fact = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        fact *= i;
    }

    printf("iterative method %d \n", fact);
    printf("recursive method %d", factorial(n));
}