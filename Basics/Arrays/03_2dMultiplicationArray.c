#include<stdio.h>

int main(){
    int n1, n2, n3;
    int arr[3][10];

    printf("Enter 3 numbers with spaces: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    // int mul[3] = {2, 7, 9};
    int mul[3] = {n1, n2, n3};

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = mul[i] * (j+1);
        }
    }
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 10; j++){
            printf("%d * %d = %d\n",mul[i],j+1, arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}