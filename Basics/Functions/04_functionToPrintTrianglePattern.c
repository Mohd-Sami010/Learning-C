#include<stdio.h>

void PrintPattern(int numOfLines){
    for (int i = 1; i < numOfLines +1; i++){
        for (int j =0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
}
int main(){
    int lines = 5;
    PrintPattern(lines);
}