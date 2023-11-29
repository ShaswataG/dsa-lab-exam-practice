#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int a[], int n) {
    int temp = a[n];
    int i = n;
    while (i > 0 && temp > a[i/2]) {
        a[i] = a[i/2];
        i /= 2;
    }
    a[i] = temp;
}

void Delete(int a[], int n) {
    int x = a[0];
    a[0] = a[n];
    a[n] = x;
    int i = 0, j = 2*i+1;
    while (j < n-1) {
        if (a[j+1] > a[j]) j++;
        if (a[i] < a[j]) {
            swap(&a[i], &a[j]);
            i = j;
            j = 2*i+1;
        } else {
            break;
        }
    }
}

void heapSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        insert(a, i);
    }
    for (int i = n-1; i > 1; i--) {
        Delete(a, i);
    }
}

void merge(int a[], int l, int mid, int h) {
    int k = l;
    int i = l, j = mid+1;
    int b[h+1];
    while (i <= mid && j <= h) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= h) {
        b[k++] = a[j++];
    }
    for (int i = l; i <= h; i++) a[i] = b[i];
}

void mergeSort(int a[], int l, int h) {
    if (l < h) {
        int mid = (l+h)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, h);
        merge(a, l, mid, h);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {6, 3, 4, 9, 10, 11, 9}, n = 7;
    display(a, n);
    // heapSort(a, n);
    mergeSort(a, 0, 6);
    display(a, n);
    return 0;
}