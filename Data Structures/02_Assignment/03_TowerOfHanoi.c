#include <stdio.h>
void TowerOfHanoi(int discsToMove, int towerA, int towerB, int towerC){
    if (discsToMove > 0){
        TowerOfHanoi(discsToMove-1, towerA, towerC, towerB);
        printf("Move a disc from tower%d to tower%d\n", towerA, towerC);
        TowerOfHanoi(discsToMove-1, towerB, towerA, towerC);
    }
}
int main(){
    TowerOfHanoi(3, 1, 2, 3);
    return 0;
}