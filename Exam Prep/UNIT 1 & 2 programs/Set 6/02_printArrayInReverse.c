#include<stdio.h>

int main(){
    int numArray[] = {0, 1 ,2 ,3 ,4 ,5, 6, 7, 8};
    for (int i = (sizeof(numArray)/ sizeof(int)) -1 ; i >= 0; i--){
        printf("%d\n", numArray[i]);
    }
    return 0;
}