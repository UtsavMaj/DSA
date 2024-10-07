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

int evaluatePrefix(char* expression) {
    int n;
    for (n = 0; expression[n] != '\0'; n++);  // Calculate length of expression

    // Start from the end of the expression
    for (int i = n - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');  // Convert char to int
        } else {
            // Pop the top two elements for operators
            int val1 = pop();
            int val2 = pop();

            switch (expression[i]) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
            }
        }
    }
    return pop();  // The final result is at the top of the stack
}

int main() {
    char expression[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", expression);

    printf("Prefix evaluation result: %d\n", evaluatePrefix(expression));

    return 0;
}
