#include <stdio.h>

int stack[100];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[100];
    int operand1, operand2, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {

        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        }
        else {
            operand2 = pop();
            operand1 = pop();

            if (postfix[i] == '+')
                result = operand1 + operand2;
            else if (postfix[i] == '-')
                result = operand1 - operand2;
            else if (postfix[i] == '*')
                result = operand1 * operand2;
            else if (postfix[i] == '/')
                result = operand1 / operand2;

            push(result);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
