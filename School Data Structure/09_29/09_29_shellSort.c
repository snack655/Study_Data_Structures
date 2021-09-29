#include <stdio.h>

void shellSort(int arr[], int n) { // n : 11
    int i, j, tmp, gap;
    for(gap = n / 2; gap > 0; gap /= 2) { // gap = gap/2
        //if(!(gap % 2)) gap++; // 짝수면 홀수로
        for(i = gap; i < n; i++) { // 삽입정렬 응용
            tmp = arr[i];
            for(j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}
// gap이 5일 때 첫번째 수행 상황은?
// 5일때는
// 11 9 15 12 3 6 5  8 11 2  7
//  *           *            *
//  6 5  8 11 2 7 9 15 12 3 11

int main() {
    int arr[] = { 11, 9, 15, 12, 3, 6, 5, 8, 11, 2, 7 };
    int n = sizeof(arr) / sizeof(int);  // 11
    printf("%d개 데이터 정렬\n", n);
    shellSort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
    return 0;
}
