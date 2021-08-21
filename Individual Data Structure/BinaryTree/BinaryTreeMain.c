#include <stdio.h>
#include "BinaryTree.h"

int main()
{
    BTreeNode * bt1 = MakeBTreeNode();      // 노드 bt1 생성
    BTreeNode * bt2 = MakeBTreeNode();      // 노드 bt2 생성
    BTreeNode * bt3 = MakeBTreeNode();      // 노드 bt3 생성
    BTreeNode * bt4 = MakeBTreeNode();      // 노드 bt4 생성
    
    SetData(bt1, 1);        // bt1에 1 저장
    SetData(bt2, 2);        // bt2에 2 저장
    SetData(bt3, 3);        // bt3에 3 저장
    SetData(bt4, 4);        // bt4에 4 저장

    MakeLeftSubTree(bt1, bt2);          // bt2를 bt1의 왼쪽 자식 노드로
    MakeRightSubTree(bt1, bt3);         // bt3를 bt1의 오른쪽 자식 노드로
    MakeLeftSubTree(bt2, bt4);          // bt4를 bt2의 왼쪽 자식 노드로

    // bt1의 왼쪽 자식 노드의 데이터 출력
    printf("%d \n", GetData(GetLeftSubTree(bt1)));
    
    // bt1의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력
    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
    
    return 0;
}
