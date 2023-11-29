#include<stdio.h>

int LSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (key == a[i]) return i;
    }
    return -1;
}

int BSearch(int a[], int n, int key) {
    int l, r, mid;
    l = 0, r = n-1;
    while (l <= r) {
        mid = (l+r)/2;
        if (key == a[mid]) return mid;
        else if (key < a[mid]) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of elements in the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int key;
    printf("Enter element to be searched : ");
    scanf("%d", &key);
    // int index = LSearch(a, n, key);
    int index = BSearch(a, n, key);
    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("%d is found at index %d.\n", key, index);
    }
    return 0;
}