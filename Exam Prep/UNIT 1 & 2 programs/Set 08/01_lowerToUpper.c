#include<stdio.h>
int IsVowel(int);
int main(){
    char string[] = "Mohd Sami Malik";

    for (int i = 0; i < sizeof(string)/ sizeof(char); i++){
        int ascii = string[i];
        if (ascii >= 97 && ascii <= 122 && IsVowel(ascii)){
            string[i] = ascii - 32;
        }
    }
    printf("%s", string);
    return 0;
}
int IsVowel(int alphaAscii){
    if (alphaAscii == 97 || alphaAscii == 101 || alphaAscii == 105 || alphaAscii == 111 || alphaAscii == 117){
        return 1;
    }
    return 0;
}