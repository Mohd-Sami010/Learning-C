#include<stdio.h>

int main(){
    int num1 = 5, num2 = 7;
    if (num1 > num2){
        printf("num2 is smallest");
    }
    else if (num1 < num2){
        printf("num1 is smallest");
    }
    else {
        printf("both are equal");
    }
    return 0;
}