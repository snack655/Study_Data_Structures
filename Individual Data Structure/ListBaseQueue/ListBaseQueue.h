#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
} Node;

typedef struct _lQueue
{
    Node * front;       // 그림을 통해서 F라 표현한 멤버
    Node * rear;        // 그림을 통해서 R이라 표현한 멤버
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);    // enqueue 연산 담당 함수
Data Dequeue(Queue * pq);               // dequeue 연산 담당 함수
Data QPeek(Queue * pq);

#endif
