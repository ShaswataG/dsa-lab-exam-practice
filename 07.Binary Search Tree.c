#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* lchild, * rchild;
};

struct Node* root;

struct Node* insert(struct Node* p, int x) {
    if (!p) {
        struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
        temp->data = x;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    if (x < p->data) p->lchild = insert(p->lchild, x);
    else if (x > p->data) p->rchild = insert(p->rchild, x);
    return p;
}

void preorder(struct Node* p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node* p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node* p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main() {
    root = NULL;
    int choice, key;
    while (1) {
        printf("Press 1 to enter element.\nPress 2 for preorder traversal.\nPress 3 for inorder traversal.\nPress 4 for postorder traversal.\nPress 5 to exit.\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2 :
                if (!root) {
                    printf("Binary search tree is empty.\n");
                } else {
                    printf("Preorder : ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 3 :
                if (!root) {
                    printf("Binary search tree is empty.\n");
                } else {
                    printf("Inorder : ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4 :
                if (!root) {
                    printf("Binary search tree is empty.\n");
                } else {
                    printf("Postorde : ");
                    postorder(root);
                    printf("\n");
                }
                break;
            default :
                exit(0);
                break;
        }
    }
    return 0;
}