/*Write a program to check if any given mathematical expression ha balanced number of
parentheses or not?
Run the program by testing following expression-
⇒a + (b − c) ∗ (d
⇒m + [a − b ∗ (c + d ∗ {m)]
⇒a + (b − c)*/

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}


int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0; 

            char open = pop();
            if (!isMatching(open, ch))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    gets(exp);   

    if (isBalanced(exp))
        printf("Expression has BALANCED parentheses\n");
    else
        printf("Expression has NOT BALANCED parentheses\n");

    return 0;
}
/*cd prog_1
clang question1.c -o question1
./question1
*/