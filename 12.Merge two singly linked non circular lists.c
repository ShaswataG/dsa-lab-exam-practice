#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node * merge(struct Node* p, struct Node* q) {
    struct Node * r;
    struct Node * head, * last;
    if (p->data < q->data) {
        head = last = p;
        p = p->next;
    } else {
        head = last = q;
        q = q->next;
    }
    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
        } else {
            last->next = q;
            last = q;
            q = q->next;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;
    return head;
}

int main() {
    return 0;
}