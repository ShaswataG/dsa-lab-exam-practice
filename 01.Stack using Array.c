#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int *s;
    int size;
    int top;
};

void initStack(struct Stack* s) {
    // printf("Enter size of stack : ");
    // scanf("%d", s->size);
    s->top = -1;
    s->size = 10;
    s->s = (int*) malloc(s->size * sizeof(int));
}

void push(struct Stack* s, int key) {
    if (s->top == s->size) {
        printf("Stack overflow.\n");
    } else {
        s->top++;
        s->s[s->top] = key;
    }
}

int pop(struct Stack* s) {
    int x = -1;
    if (s->top == -1) {
        printf("stack underflow.\n");
        return x;
    }
    x = s->s[s->top];
    s->top--;
    return x;
}

void display(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow.\n");
        return;
    } else {
        printf("Elements are : ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->s[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int key;
    struct Stack s;
    initStack(&s);
    while (1) {
        printf("Press 1 to push.\nPress 2 to pop.\nPress 3 to display.\nPress 4 to exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element you want to push : ");
            scanf("%d", &key);
            push(&s, key);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}