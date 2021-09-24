#include <stdio.h>
#include "ALGraphKruskal.h"

int main() {
    ALGraph graph;
    GraphInit(&graph, 6);       // 정점 A, B, C, D, E, F, G 생성
    
    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, B, C, 2);
    AddEdge(&graph, A, C, 12);
    AddEdge(&graph, A, D, 8);
    AddEdge(&graph, D, C, 6);
    AddEdge(&graph, A, F, 11);
    AddEdge(&graph, F, D, 4);
    AddEdge(&graph, D, E, 3);
    AddEdge(&graph, E, C, 7);
    AddEdge(&graph, F, E, 13);
    
    ConKruskalMST(&graph);      // MST로 변환
    ShowGraphEdgeInfo(&graph);
    ShowGraphEdgeWeightInfo(&graph);
    
    GraphDestroy(&graph);
    return 0;
}
