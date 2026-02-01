#include <stdio.h>
int main()
{
    char str[] = "(a+b)(c-d)";

    char stack[100];
    int top = -1;
    int isBalanced = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            stack[++top] = '(';
        }
        else if (str[i] == ')')
        {
            if (top == -1)
            {
                isBalanced = 0;
                break;
            }
            top--;
        }
    }
    if (top > -1) isBalanced = 0;
    
    if (isBalanced)
    {
        printf("All parenthesis matched");
    }
    else
    {
        printf("Parenthesis unmatched");
    }
}