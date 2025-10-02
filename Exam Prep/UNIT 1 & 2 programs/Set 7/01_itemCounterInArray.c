#include<stdio.h>

int main(){
    int array[] = {1, 2, 3, 3, 4, 5, 5, 5, 6, 8, 9};
    int target = 3;

    int count = 0;
    for (int i = 0; i < sizeof(array)/ sizeof(int); i++){
        if (array[i] == target){
            count++;
        }
    }
    printf("number %d appeard %d times", target, count);
    return 0;
}