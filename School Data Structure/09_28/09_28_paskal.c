#include <stdio.h>
// 순열과 조합
#define N 10

long combi(int, int);    // 수학에서 조합(combination)
// 수학 확률과 통계 단원 순열(permutation)과 조합(combination)

int main() {
    int n, r, t;    // nPr 순영 공식, nCr 조합 공식
    for(n = 0; n <= N; n++) {
        for(t = 0; t < (N - n) * 3; t++)
            printf(" ");        // 이 for문은 앞의 부분 띄우기 이다. 가장 위의 1이 30칸 뛰워져 있는 이유! 그리고 3식 줄어든다!
        for(r = 0; r <= n; r++)
            printf("%3ld   ", combi(n, r)); // combi 함수에 값을 넣어서 출력!
        printf("\n");
    }
    return 0;
}

long combi(int n, int r) {
    int i;
    long c = 1;
    for(i = 1; i <= r; i++)
        c = c * (n - i + 1) / i; // 수학 공식 조합의 합으로 이루어 진다.
    return c;
}
