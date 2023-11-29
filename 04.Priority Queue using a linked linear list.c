#include<stdio.h>
#include<stdlib.h>

struct  Node {
    int data;
    struct Node* next;
};

struct Node* front, * rear;

void enqueue(struct Node* p, int x) {
    struct Node* temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (!p) {
        front = temp;
        rear = temp;
    } else {
        struct Node* q = NULL;
        while (p && x > p->data) {
            q = p;
            p = p->next;
        }
        if (p == front) {
            temp->next = front;
            front = temp;
        } else if (!p) {
            temp->next = p;
            q->next = temp;
            rear = temp;
        } else {
            temp->next = p;
            q->next = temp;
        }
    }
}

int dequeue(struct Node* p) {
    int x = -1;
    if (!p) {
        return -1;
    } else {
        struct Node* t = p;
        front = front->next;
        x = t->data;
        free(t);
        return x;
    }
}

void display(struct Node* p) {
    if (!p) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements are : ");
        while (p) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    front = rear = NULL;
    while (1) {
        printf("\nMENU\nPress 1 to enqueue.\nPress 2 to dequeue.\nPress 3 to display.\nPress 4 to exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue : ");
            scanf("%d", &x);
            enqueue(front, x);
            break;
        case 2:
            x = dequeue(front);
            if (x == -1) {
                printf("Queue is empty.\n");
            } else {
                printf("Dequeued element is : %d\n", x);
            }
            break;
        case 3:
            display(front);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}