#ifndef __AL_EDGE__
#define __AL_EDGE__

typedef struct _edge {
    int v1;         // 간선이 연결하는 첫 번째 정점
    int v2;         // 간선이 연결하는 두 번째 정점
    int weight;     // 간선의 가중치
} Edge;

#endif
