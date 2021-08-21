#include <stdio.h>
#include "SimpleHeap.h"

int main()
{
    Heap heap;
    HeapInit(&heap);                // 힙의 초기화
    
    HInsert(&heap, 'A', 1);         // 문자 'A'를 최고의 우선순위로 저장
    HInsert(&heap, 'B', 2);         // 문자 'B'를 두 번째 우선순위로 저장
    HInsert(&heap, 'C', 3);         // 문자 'C'를 세 번째 우선순위로 저장
    printf("%c \n", HDelete(&heap));
    
    HInsert(&heap, 'A', 1);         // 문자 'A'를 한 번 더 저장
    HInsert(&heap, 'B', 2);         // 문자 'B'를 한 번 더 저장
    HInsert(&heap, 'C', 3);         // 문자 'C'를 한 번 더 저장
    printf("%c \n", HDelete(&heap));
    
    while (!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));
    
    return 0;
}
