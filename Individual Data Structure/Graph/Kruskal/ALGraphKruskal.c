#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2);

void GraphInit(ALGraph * pg, int nv)
{
    int i;
    
    pg->adjList = (List*)malloc(sizeof(List)*nv);
    
    pg->numV = nv;
    pg->numE = 0;
    
    for (i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }
    
    pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    
    PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph * pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList);

    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

int PQWeightComp(Edge d1, Edge d2) {
    return d1.weight - d2.weight;
}

int VisitVertex(ALGraph * pg, int visitV)
{
    if(pg->visitInfo[visitV] == 0)
    {
        pg->visitInfo[visitV] = 1;
        return TRUE;
    }
    
    return FALSE;
}

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    Edge edge = {fromV, toV, weight};       // 간선의 가중치 정보를 담음

    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;

    // 간선의 가중치 정보를 우선순위 큐에 저장
    PEnqueue(&(pg->pqueue), edge);
}

void ShowGraphEdgeInfo(ALGraph * pg) {
    int i;
    int vx;
    
    for(i = 0; i < pg->numV; i++) {
        printf("%c와 연결된 정점 : ", i + 65);
        
        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);
            
            while (LNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx + 65);
        }
        printf("\n");
    }
}


void ShowGraphEdgeWeightInfo(ALGraph * pg)      // 간선의 가중치 정보 출력
{
    PQueue copyPQ = pg->pqueue;
    Edge edge;
    
    while (!PQIsEmpty(&copyPQ))
    {
        edge = PDequeue(&copyPQ);
        printf("(%c - %c), w : %d \n", edge.v1+65, edge.v2+65, edge.weight);
    }
}

void RemoveWayEdge(ALGraph * pg, int fromV, int toV)        // 한쪽 방향의 간선 소멸
{
    int edge;
    
    if(LFirst(&(pg->adjList[fromV]), &edge)) {
        if(edge == toV) {
            LRemove(&(pg->adjList[fromV]));
            return;
        }
        
        while (LNext(&(pg->adjList[fromV]), &edge)) {
            if(edge == toV) {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}

void RemoveEdge(ALGraph * pg, int fromV, int toV)       // 간선의 소멸
{
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}

void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight) {
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}

// 인자로 전달된 두 정점이 연결되어 있다면 TRUE, 그렇지 않다면 FALSE 반환
int IsConnVertex(ALGraph * pg, int v1, int v2)
{
    Stack stack;
    int visitV = v1;
    int nextV;
    
    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);
    
    while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        int visitFlag = FALSE;
        
        // 정점을 돌아다니는 도중에 목표를 찾는다면 TRUE를 반환한다.
        if(nextV == v2) {
            // 함수가 반환하기 전에 초기화를 진핸한다.
            memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
            return TRUE;        // 목표를 찾았으니 TRUE를 반환!
        }
        
        if(VisitVertex(pg, nextV) == TRUE) {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        } else {
            while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
                // 정점을 돌아다니는 도중에 목표를 찾는다면 TRUE를 반환한다.
                if (nextV == v2) {
                    // 함수가 반환하기 전에 초기화를 진행한다.
                    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
                    return TRUE;        // 목표를 찾았으니 TRUE를 반환!
                }
                
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        
        if(visitFlag == FALSE) {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return FALSE;       // 여기까지 왔다는 것은 목표를 찾지 못했다는 것!
}

void ConKruskalMST(ALGraph * pg)        // 크루스칼 알고리즘 기반 MST의 구성
{
    Edge recvEdge[20];      // 복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;
    
    // MST를 형성할 때까지 아래의 while문을 반복
    while (pg->numE + 1 > pg->numV)     // MST 간선의 수 + 1 == 정점의 수
    {
        edge = PDequeue(&(pg->pqueue));
        RemoveEdge(pg, edge.v1, edge.v2);
        
        if (!IsConnVertex(pg, edge.v1, edge.v2))
        {
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
            recvEdge[eidx++] = edge;
        }
    }
    
    // 우선순위 큐에서 삭제된 간선의 정보를 회복
    for(i = 0; i < eidx; i++)
        PEnqueue(&(pg->pqueue), recvEdge[i]);
}

