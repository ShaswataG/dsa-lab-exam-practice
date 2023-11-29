#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// struct Node* head = NULL;

void Insert(struct Node **start, int x) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (*start == NULL) {
        *start = temp;
    } else {
        struct Node* q;
        struct Node* p = *start;
        while (p) {
            q = p;
            p = p->next;
        }
        q->next = temp;
    }
}

void Display(struct Node* p) {
    if (!p) {
        printf("List is empty.\n");
    } else {
        while (p) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void Delete(struct Node** start, int key) {
    if (!start) {
        printf("List is empty.\n");
    } else {
        struct Node* q = NULL;
        struct Node* p = *start;
        while (p && p->data != key) {
            q = p;
            p = p->next;
        }
        if (p) {
            if (q) q->next = p->next;
            if (p == *start) *start = p->next;
            free(p);
        } else {
            printf("Element not found.\n");
        }
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    int x;
    while (1) {
        printf("Press 1 to insert.\nPress 2 to display.\nPress 3 to delete.\nPress 4 to exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to enter : ");
            scanf("%d", &x);
            Insert(&head, x);
            break;
        case 2:
            Display(head);
            break;
        case 3:
            printf("Enter the element you want to delete : ");
            scanf("%d", &x);
            Delete(&head, x);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}