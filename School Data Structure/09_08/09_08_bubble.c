#include <stdio.h>

void swap(int * num1, int * num2) {
    int t = *num1;
    *num1 = *num2;
    *num2 = t;
}

void bubble1(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n  - i; j++) {
            if(a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
            }
        }
    }
}

int main() {
    int a[5] = {5, 4, 3, 2, 1};
    bubble1(a, 5);
    printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
}
