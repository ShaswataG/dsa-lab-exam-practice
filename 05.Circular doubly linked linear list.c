#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev, * next;
};

struct Node* head, * tail;

void insertBeginning(struct Node* p, int x) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = temp->next = NULL;
    if(!p) {
        head = temp;
        head->prev = head;
        head->next = head;
        tail = head;
    } else {
        temp->next = head;
        tail->next = temp;
        head->prev = temp;
        head = temp;
    }
}

void insertEnd(struct Node* p, int x) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = temp->next = NULL;
    if (!p) {
        head = temp;
        head->prev = head->next = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        temp->next = head;
        tail = temp;
        head->prev = tail;
    }
}

void insertAfterNode(struct Node* p, int pos, int x) {

    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    struct Node* q = NULL;
    for (int i = 0; p && i <= pos-1; i++) {
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->prev = q;
    temp->data = x;
    temp->next = p;
    p->prev = temp;
}

int deleteBeginning(struct Node* p) {
    struct Node* t = head;
    if (!p) {
        return -1;
    } else {
        int x = t->data;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(t);
        return x;
    }
}

int deleteEnd(struct Node* p) {
    struct Node* t = tail;
    if (!p) {
        return -1;
    } else {
        int x = t->data;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(t);
        return x;
    }
}

int deleteAfterNode(struct Node* p, int pos) {
    if (!p) {
        return -1;
    } else {
        struct Node* q = NULL;
        for (int i = 0; p && i < pos-1; i++) {
            q = p;
            p = p->next;
        }
        struct Node* t = p;
        int x = t->data;
        if (q) q->next = p->next;
        else {
            tail->next = p->next;
            head = p->next;
        }
        p->next->prev = q;
        free(t);
        return x;
    }
}

void display(struct Node* p) {
    if (!p) {
        printf("List is empty.\n");
    } else {
        printf("Elements are : ");
        do {
            printf("%d ", p->data);
            p = p->next;
        } while (p != head);
        printf("\n");
    }
}

int main() {
    int choice, x, a, b, pos, key;
    while (1) {
        printf("\nMENU\nPress 1 to insert.\nPress 2 to delete.\nPress 3 to display.\nPress 4 to exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1 :
            printf("Press 1 to insert at the beginning\nPress 2 to insert at the end.\nPress 3 to insert by position.\n");
            scanf("%d", &a);
            switch (a)
            {
            case 1 :
                printf("Enter value you want to enter : ");
                scanf("%d", &key);
                insertBeginning(head, key);
                break;
            case 2 :
                printf("Enter value you want to enter : ");
                scanf("%d", &key);
                insertEnd(head, key);
                break;
            case 3 :
                printf("Enter node position after which you want to enter element : ");
                scanf("%d", &pos);
                printf("Enter value you want to enter : ");
                scanf("%d", &key);
                insertAfterNode(head, pos, key);
                break;            
            default:
                exit(0);
                break;
            }
            break;
        case 2 :
            printf("Press 1 to delete at the beginning.\nPress 2 to delete at the end.\nPress 3 to delete by position.\n");
            scanf("%d", &b);
            switch(b) {
                case 1 :
                    x = deleteBeginning(head);
                    if (x == -1) {
                        printf("List is empty.\n");
                    } else {
                        printf("Deleted element is : %d\n", x);
                    }
                    break;
                case 2 :
                    x = deleteEnd(head);
                    if (x == -1) {
                        printf("List is empty.\n");
                    } else {
                        printf("Deleted element is : %d\n", x);
                    }
                    break;
                case 3 :
                    printf("Enter position of node you want to delete : ");
                    scanf("%d", &pos);
                    x = deleteAfterNode(head, pos);
                    if (x == -1) {
                        printf("List is empty.\n");
                    } else {
                        printf("Deleted element is : %d\n", x);
                    }
                    break;
                default :
                    exit(0);
            }
            break;
        case 3 :
            display(head);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}