#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Queue {
    int *a;
    int front, rear, size;
};

void initQueue(struct Queue* q) {
    q->size = MAX;
    q->a = (int*) malloc(MAX * sizeof(int));
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, int key) {
    if ((q->rear+1)%MAX == q->front) {
        printf("Queue full.\n");
        return;
    } else {
        q->rear = (q->rear+1)%MAX;
        q->a[q->rear] = key;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == q->rear) {
        printf("Queue empty.\n");
        return -1;
    }
    int x = q->a[(q->front+1)%MAX];
    q->front = (q->front+1)%MAX;
    return x;
}

void display(struct Queue q) {
    if (q.front == q.rear) {
        printf("Queue empty.\n");
    } else {
        for (int i = q.front+1; i <= q.rear; i = (i+1)%MAX) {
            printf("%d ", q.a[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int x;
    int a;
    struct Queue q;
    initQueue(&q);
    while (1) {
        printf("Press 1 to enqueue.\nPress 2 to dequeue.\nPress 3 to display\nPress 4 to exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed : ");
            scanf("%d", &x);
            enqueue(&q, x);
            break;
        case 2:
            a = dequeue(&q);
            if (a == -1) {
                printf("Queue empty.\n");
            } else {
                printf("Dequeued element is : %d\n", a);
            }
            break;
        case 3:
            display(q);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}