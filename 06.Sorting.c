#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n) {
    int flag = 0;
    for (int i = 0; i < n-1; i++) {
        flag = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void selectionSort(int a[], int n) {
    int min = 0;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(&a[i], &a[min]);
    }    
}

void insertionSort(int a[], int n) {
    int j, temp;
    for (int i = 0; i < n; i++) {
        j = i-1;
        temp = a[i];
        while (j >= 0 && temp < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    // int a[] = {6, 6, 6, 1, 7, 3, 1}, n = 7;
    // display(a, n);
    // bubbleSort(a, n);
    // selectionSort(a, n);
    // display(a, n);

    int choice, n;
    int* arr;
    while (1) {
        printf("\nMENU\nPress 1 to enter elements into the array.\nPress 2 to display.\nPress 3 for bubble sort.\nPress 4 for selection sort.\nPress 5 for insertion sort.\nPress 6 to reset the elements in the array.\nPress 7 to exit.\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
                printf("Enter number of elements : ");
                scanf("%d", &n);
                arr = (int*) malloc(n*sizeof(int));
                printf("Enter %d elements : ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            case 2 :
                display(arr, n);
                break;
            case 3 :
                bubbleSort(arr, n);
                break;
            case 4 :
                selectionSort(arr, n);
                break;
            case 5 :
                insertionSort(arr, n);
                break;
            case 6 :
                printf("Enter %d elements : ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            default :
                exit(0);
                break;
        }
    }
    return 0;
}