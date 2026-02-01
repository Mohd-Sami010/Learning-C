#include <stdio.h>

char stack[100];
int top = -1;

void push(char x) {
    top++;
    stack[top] = x;
}

char pop() {
    char x = stack[top];
    top--;
    return x;
}

int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x) {
    if ((x >= 'a' && x <= 'z') ||
        (x >= 'A' && x <= 'Z') ||
        (x >= '0' && x <= '9'))
        return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();  // remove '('
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
