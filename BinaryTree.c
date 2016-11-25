#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*ElemType为整形时-1代表空值， 为char型时#代表空值*/
typedef int ElemType;
typedef struct BNode
{
    ElemType data;
    struct BNode *left, *right;
} BNode, *BTree;
typedef BNode* Position;

void createTree(BTree *t);
void preOrder(BTree T);
Position find(ElemType e, BTree T);

int main(int argc, char const *argv[])
{
    ElemType datas[] = {30, 15, -1, -1, 41, 33, -1, -1, 50, -1, -1};
    int length = sizeof(datas) / sizeof(datas[0]);
    addAll(datas, length);
    BTree T;
    // 因为树的内容尚未初始化，所以传指针
    createTree(&T);
    preOrder(T);
    printf("%d\n", find(50, T) -> data);
    getchar();
    return 0;
}

void createTree(BTree *t)
{
    int c;
    if (deque(&c))
    {
        if (c == -1)
        {
            *t = NULL;
        }
        else
        {
            *t = (BTree)malloc(sizeof(BNode));
            if (!*t)
                exit(1);
            (*t)->data = c;
            createTree(&(*t)->left);
            createTree(&(*t)->right);
        }
    }
}

void preOrder(BTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("[%d] ", T->data);
    preOrder(T->left);
    preOrder(T->right);
}

Position find(ElemType e, BTree T)
{   // 递归版本
    //if (T == NULL) return NULL;
    //if (e > T -> data) return find(e, T -> right);
    //if (e < T -> data) return find(e, T -> left);
    //if (e == T -> data) return T;
    // 递归版本结束

    // 非递归版本
    while (T) {
        if (e > T -> data) T = T -> right;
        if (e < T -> data) T = T -> left;
        if (e == T -> data) return T;
    }
    return NULL;
}
