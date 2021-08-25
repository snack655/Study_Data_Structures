#include <stdio.h>

typedef struct studentTag {
    // 이름, 나이, 시험 점수
    char name[10];
    int age;
    int score;
} student;

int main() {
    student s13 = { "kim", 17, 90 };
    student s12 = { "park", 17, 95 };
    
    // 구조체 변수 초기화
    // 구조체를 출력하는 printf()를 만들어보자.
    printf("이름 : %s\n", s13.name);
    printf("이름 : %s\n", s12.name);
    printf("나이 : %d\n", s13.age);
    printf("나이 : %d\n", s12.age);
    printf("점수 : %d\n", s13.score);
    printf("점수 : %d\n", s12.score);
    
    return 0;
}
