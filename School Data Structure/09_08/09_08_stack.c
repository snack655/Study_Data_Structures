#include <stdio.h>
#define SIZE 5      // 스택에 넣을 수 있는 최대 사이즈
void push(int);     // 스택에서 데이터 한 개 삽입
void pop();         // 스택에서 데이터 한 개 삭제
void display();     // 스택에 있는 데이터 보여주기

int stack[SIZE];
int top = -1;       // 스택에 저장할 위치

int main() {
    int val, choice;
    printf("\n----Menu----\n");
    while (1) {
        printf("1. push   2. pop    3. display   4. exit\n");
        printf("Choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1: // 스택에 push
            printf("데이터를 입력하세요 : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2: // 스택에서 pop
            pop();
            break;
        case 3: // 스택 내용 display
            display();
            break;
        case 4:  // 프로그램 종료 exit
            return 0;
        default:
                printf("다시 입력하세요.");
        }
    }
    return 0;
}

void push(int val) {    // 쪽지시험, 암기 필요
    if(top == SIZE - 1) // top >= SIZE - 1
        printf("스택이 가득참\n");
    else
        stack[++top] = val;
}

void pop() {    // 쪽지시험, 암기 필요
    if(top == -1)
        printf("스택이 비었음\n");
    else
        printf("%d이(가) 삭제됨\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("스택이 비었음\n");
    else
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    printf("\n");
    
}
