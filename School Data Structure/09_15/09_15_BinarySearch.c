#include <stdio.h>
#include <stdlib.h>
//이분 탐색, 이진 탐색 : 정렬된 배열 속 데이터 찾기

int arr[100] = { 5, 7, 33, 66, 67, 88, 99, 120, 134, 156, 234 };
int n, k;   // k는 내가 찾을 숫자
int count = 0;

int binarySearch(int s, int e) {    // start end
    while (s <= e) {
        count++;
        int m = (s + e) / 2; // m은 middle
        if(arr[m] == k)
            return m;   // 찾은 배열의 인덱스 (위치)
        if(arr[m] > k)
            e = m - 1;
        else
            s = m + 1;
    }
    return -1;  // 결국 숫자를 못찾음
}

int main() {
    printf("찾을 숫자 입력 : ");
    scanf("%d", &k);    // k = 66;
    if(binarySearch(0, 10) != -1) {
        printf("%d번째에서 발견\n", binarySearch(0, 10));
        printf("%d번만에 찾았습니다\n", count);
    } else {
        printf("값을 찾지 못했어유..ㅜㅜ\n");
        printf("%d번만에 찾지 못했습니다..\n", count);
    }
    return 0;
}


