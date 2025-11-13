/*
Function Pointer Dispatch Table
You are building a simple math command handler. You are given two integers and a command code:
0 → Add
1 → Subtract
2 → Multiply
3 → Divide (integer division, assume non-zero)
Your task:
Create an array of function pointers, each pointing to one of the above operations.
Based on the command code, use the function pointer to invoke the correct operation.
Return the result.
 
❌ No if-else or switch-case
✅ Must use a function pointer array
*/

#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int execute_command(int a, int b, int cmd) {
    int(*arr[4])(int, int);
    arr[0] = add;
    arr[1] = sub;
    arr[2] = mul;
    arr[3] = divide;
    return arr[cmd](a, b);
}

int main() {
    int a, b, cmd;
    scanf("%d %d %d", &a, &b, &cmd);

    int result = execute_command(a, b, cmd);
    printf("%d", result);

    return 0;
}