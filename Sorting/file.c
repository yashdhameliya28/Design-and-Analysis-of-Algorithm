#include<stdio.h>

void main(){
    FILE *fp, *fp1, *fp2;
    int n;

    fp = fopen("best.txt", "w");
    fp1 = fopen("worst.txt", "w");
    fp2 = fopen("average.txt", "w");

    for(int i=1; i<=100000; i++){
        fprintf(fp, "%d\n", i);
        fprintf(fp1, "%d\n", 100000-i+1);
        fprintf(fp2, "%d\n", rand());
    }
}