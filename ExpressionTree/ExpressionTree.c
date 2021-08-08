#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * pnode;
    
    int expLen = strlen(exp);
    int i;
    StackInit(&stack);
    
    for (i = 0; i < expLen; i++)
    {
        
        pnode = MakeBTreeNode();
        
        if (isdigit(exp[i]))
        {
            SetData(pnode, exp[i]-'0');
        }
        else
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }
        
        SPush(&stack, pnode);
    }
    
    return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
    int op1, op2;
    
    if (GetLeftSubTree(bt)==NULL && GetRightSubTree(bt) == NULL)    // 단말 노드라면
        return GetData(bt);
    
    
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));
    
    switch (GetData(bt))
    {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }
    return 0;
}

void ShowNodeData(int data)
{
    if(0<=data && data<=9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
    if(bt == NULL)
        return;
    
    if(bt->left != NULL || bt->right != NULL)
        printf(" ( ");
    
    ShowInfixTypeExp(bt->left);     // 첫 번째 피연산자 출력
    ShowNodeData(bt->data);         // 연산자 출력
    ShowInfixTypeExp(bt->right);    // 두 번째 피연산자 출력
    
    if(bt->left != NULL || bt->right != NULL)
        printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNodeData);
}
