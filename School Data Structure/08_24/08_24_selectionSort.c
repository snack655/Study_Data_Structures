#include <stdio.h>

// call by reference
void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void input(int a[], int cnt)
{
   for (int i = 0; i < cnt; i++)
      scanf("%d", &a[i]);
}

void output(int a[], int cnt)
{
   for (int i = 0; i < cnt; i++)
      printf("%d ", a[i]);
}

void selectionSort(int a[], int cnt) {
    for(int i = 0; i < cnt - 1; i++) {
        for(int j = i+1; j < cnt; j++)
            if(a[i] > a[j]) // 오름차순 5 > 2
                swap(&a[i], &a[j]);
    }
}

int main() {
    int n;
    int a[100];
    scanf("%d", &n);
    input(a, n);
    selectionSort(a, n);
    output(a, n);
    return 0;
}


