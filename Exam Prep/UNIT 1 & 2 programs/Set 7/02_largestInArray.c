#include<stdio.h>

int main(){
    int array[] = {1, 2, 3, 3, 4, 5, 15, 5, 6, 8, 9};

    int largestNum = array[0];
    for (int i = 0; i < sizeof(array)/ sizeof(int); i++){
        if (array[i] > largestNum){
            largestNum = array[i];
        }
    }
    printf("Biggest num is %d", largestNum);
    return 0;
}