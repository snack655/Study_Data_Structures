#include <stdio.h>

int m[9][9] = { //maze
             {2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2} };

int Si, Sj, Ei, Ej, success, idx, Path_i[100], Path_j[100];

int visit(int i, int j) {
    static int path = 1;    // 찾은 경오르이 수 카운트
    m[i][j] = 1;
    // 지난간 길에는 1을 저장해둔다
    Path_i[idx] = i, Path_j[idx] = j; // 경로 Path를 저장
    idx++;
    //만약 도착점에 도달했다면
    if (i == Ei && j == Ej) {
        printf(" %d번째 찾은 경로\n", path++);
        for (int k = 0; k < idx; k++)//경로 출력
            printf("(%d %d)", Path_i[k], Path_j[k]);
        printf("\n");
        success = 1;
    }

    // ***미로를 본격적으로 탐색하는 코드***
    //오른쪽으로 탐색
    if (m[i][j + 1] == 0)
        visit(i, j + 1);
    //왼쪽으로 탐색
    if (m[i + 1][j] == 0)
        visit(i + 1, j);
    // 왼쪽으로 탐색
    if (m[i][j - 1] == 0)
        visit(i, j - 1);
    // 위쪽으로 탐색
    if (m[i - 1][j] == 0)
        visit(i - 1, j);

    idx--;
    m[i][j] = 0;
    return success;
}

int main() {
    printf("미로탈출 게임\n");
    Si = 1, Sj = 1;
    Ei = 7, Ej = 7;
    if (visit(Si, Sj) == 0)
        printf("못 찾았음\n");
    else
        printf("모든 경로를 찾았음\n");
    return 0;
}


