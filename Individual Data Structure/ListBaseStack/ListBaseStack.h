#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node        //연결 리스트의 노드를 표현한 구조체
{
    Data data;
    struct _node * next;
} Node;

typedef struct _listStack       // 연결 리스트 기반 스택을 표현한 구조체
{
    Node * head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);     // 스택 초기화
int SIsEmpty(Stack * pstack);       // 스택이 비었는지 확인

void SPush(Stack * pstack, Data data);      // 스택의 push 연산
Data SPop(Stack * pstack);                  // 스택의 pop 연산
Data SPeek(Stack * pstack);                 // 스택의 peek 연산


#endif
