#include <stdio.h>
#include <ctype.h>  // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

void push(int data) {
    stack[++top] = data;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(expression[i])) {
            push(expression[i] - '0');  // Convert char to int
        } else {
            // Pop the top two elements for operators
            int val1 = pop();
            int val2 = pop();

            switch (expression[i]) {
                case '+':
                    push(val2 + val1);
                    break;
                case '-':
                    push(val2 - val1);
                    break;
                case '*':
                    push(val2 * val1);
                    break;
                case '/':
                    push(val2 / val1);
                    break;
            }
        }
    }
    return pop();  // The final result is at the top of the stack
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    printf("Postfix evaluation result: %d\n", evaluatePostfix(expression));

    return 0;
}
