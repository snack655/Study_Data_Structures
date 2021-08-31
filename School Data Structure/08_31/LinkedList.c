#include <stdio.h>
#include <stdlib.h>     // malloc free 함수가 선언된 헤더 파일

typedef struct NODE ND;
struct NODE {               // 연결 리스트의 노드 구조체
    struct NODE * next;     // 다음 노드의 주소를 저장할 포인터
    int data;               // 데이터를 저장할 멤버
};

int main()
{
    struct NODE * head = malloc(sizeof(struct NODE));       // 머리 노드 생성
    // ND* head = malloc(sizeof(ND))                        // 머리 노드는 데이터를 저장하지 않음
    
    struct NODE * node1 = malloc(sizeof(struct NODE));      // 첫 번째 노드 생성
    head->next = node1;                                     // 머리 노드 다음은 첫 번째 노드
    node1 -> data = 10;                                     // 두 번째 노드에 10 저장
    
    struct NODE * node2 = malloc(sizeof(struct NODE));      // 첫 번째 노드 생성
    node1->next = node2;
    node2 -> data = 20;
    
    node2->next = NULL;
    
    struct NODE * curr = head->next;
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    
    free(node2);        // 노드 메모리 헤제
    free(node1);        // 노드 메모리 헤제
    free(head);         // 노드 메모리 헤제
    
}
