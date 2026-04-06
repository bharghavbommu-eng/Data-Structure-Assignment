#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5, i;

    push(0);

    for(i = 1; i < n; i++) {
        while(top != -1 && arr[i] > arr[peek()]) {
            printf("%d → %d\n", arr[pop()], arr[i]);
        }
        push(i);
    }

    while(top != -1) {
        printf("%d → -1\n", arr[pop()]);
    }

    return 0;
}