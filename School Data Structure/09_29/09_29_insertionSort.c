#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, tmp;
    for(i = 1; i < n; i++) {
        tmp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}

int main() {
    int arr[] = { 11, 9, 15, 12, 3, 6, 5, 8, 11, 2, 7 };
    int n = sizeof(arr) / sizeof(int);  // 11
    printf("%d개 데이터 정렬\n", n);
    insertionSort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
    return 0;
}
