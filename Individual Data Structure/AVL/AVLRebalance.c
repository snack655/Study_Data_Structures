#include <stdio.h>
#include "BinaryTree3.h"

// LL회전
BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);
    
    return cNode;
}

// RR회전
BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}

// LR회전
BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    ChangeLeftSubTree(pNode, RotateRR(cNode));
    return RotateLL(pNode);
}

// RL회전
BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode * bst) {
    int leftH;
    int rightH;
    
    if(bst == NULL)
        return 0;
    
    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));
    
    if (leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

// 두 서브 트리의 높이의 차를 반환
int GetHeightDiff(BTreeNode * bst)
{
    int lsh;
    int rsh;
    
    if(bst == NULL)
        return 0;
    
    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    return lsh - rsh;
}

// 트리의 균형을 잡는다
BTreeNode * Rebalance(BTreeNode ** pRoot) {
    int hDiff = GetHeightDiff(*pRoot);
    
    if(hDiff > 1)
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    
    if(hDiff < -1)
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
    
    return *pRoot;
}
