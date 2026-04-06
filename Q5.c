#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if((rear + 1) % MAX == front) {
        printf("Queue Full\n");
    } else {
        if(front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

// Dequeue
void dequeue() {
    if(front == -1) {
        printf("Queue Empty\n");
    } else {
        printf("Removed: %d\n", queue[front]);
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

// Peek
void peek() {
    if(front == -1)
        printf("Queue Empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

// Display
void display() {
    if(front == -1) {
        printf("Queue Empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while(1) {
            printf("%d ", queue[i]);
            if(i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, x;

    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}