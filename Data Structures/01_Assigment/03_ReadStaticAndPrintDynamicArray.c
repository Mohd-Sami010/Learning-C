#include <stdio.h>
#include <stdlib.h>

int main(){
    int staticArr[] = {5, 7, 2, 8, 1, 87, 342, 5, 4};
    int arrSize = sizeof(staticArr)/sizeof(int);

    int *dynamicArr;
    dynamicArr = (int*) malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++){
        dynamicArr[i] = staticArr[i];
    }

    // Printing
    for (int i = 0; i< arrSize; i++){
        printf("%d, ", dynamicArr[i]);
    }
    free(dynamicArr);

    return 0;
}