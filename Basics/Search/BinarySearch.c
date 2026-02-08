#include <stdio.h>

int main(){
    int array[] = {1, 3, 4, 5, 7, 12, 13, 14, 18, 21};
    int target = 18;

    int low = 0, high = 9;
    while (low <= high){
        int mid = (high + low) / 2;
        
        if (array[mid] > target) high = mid -1;
        else if (array[mid] < target) low = mid+1;

        else{
            printf("Target found at index %d", mid);
            break;
        }
    }
}