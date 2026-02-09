## Checking Balanced Parantheses Using Stack in C

## INTRODUCTION
This document describes a C program that checks whether a given mathematical expression contains a balanced number of parentheses. The program uses the **stack data structure** implemented using an array and follows the **LIFO(Last In First Out)** principle.
In this program, a stack is used to keep track of opening brackets while scanning the expression.
## OBJECTIVES
To write a C program that check whether a given mathematical expression has a balanced number of parentheses using the **stack data structure.**

## DATA STRUCTURES USED

## Stack Definition

The stack is implemented using an array of characters.
```bash
#define MAX 100
char stack[MAX];
int top = -1;
```
**Explanation**

. stack[MAX]

Stores opening brackets encountered in the expression.

. top 

Keeps tracks of index of the topmost element in the stack.

. top=-1 indicates that the stack is empty.

The stack is used to temporarily store opening bracket until a corresponding closing bracket is found.

## DESCRIPTION OF FUNCTIONS IMPLEMENTED

1. **push(char ch)**

**Purpose:**

Pushes an opening bracket onto the stack.

**Description**

The top index is incremented first and then the character is sorted at that position.
```bash
void push(char ch){
stack[++top]=ch;
}
```
2. **pop()**

**Purpose:**

Removes and returns the top element from the stack.

**Description:**

The character at the current top position is returned and then top is decremented.
```bash
char pop(){
return stack[top --];
}
```
3. **isMatching(char open, char close)**

**Purpose:**

Checks whether an opening bracket matches the corresponding closing brackets.

**Description**

Returns 1 if the brackets match, otherwise return 0.
```bash
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}
```
4. **isBalanced(char exp[])**

**Purpose:**

Determine whether the given expression has balanced parentheses.

**Description:**

. Scan the expression character by character.
. Pushes opening brackets onto the stack.
. Pops and matches brackets when a closing bracket is found.
. Return 1 if balanced, otherwise 0.
```bash
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
```
## ORGANIZATION OF THE main() FUNCTION
The main() function is organised as follow:

1. Declares a character array to store the input expression.

2. Accepts the expression from the user.

3. Calls the isBalanced() function.

4. Display whether the expression is balanced or not.

```bash
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
```
## SAMPLE OUTPUT
Sample Run 1
```bash
Enter expression: a + (b - c) * (d
Expression has NOT BALANCED parentheses
```
Sample Run 2
```bash
Enter expression: a + (b - c) * (d
Expression has NOT BALANCED parentheses
```

## CONCLUSION
The program successfully checks whether a mathematical expression has balanced parantheses using a stack. It correctly detects missing, extra or mismatched brackets by following the LIFO principle of stack operartions.
