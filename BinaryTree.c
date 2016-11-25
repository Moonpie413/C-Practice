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
typedef BNode *Position;

// 根据队列给定的数据创建树 (前序遍历)
void createTree(BTree *t);
// 前序遍历树
void preOrder(BTree T);
// 根据给定的元素查找， 返回找到的位置的地址
Position find(ElemType e, BTree T);
// 查找树中最小的元素
Position findMin(BTree T);
// 查找树中最大的元素
Position findMax(BTree T);
// 插入一个数据
BTree insert(ElemType e, BTree T);
// 删除一个节点
BTree delete (ElemType e, BTree T);

int main(int argc, char const *argv[])
{
    ElemType datas[] = {30, 15, -1, -1, 41, 33, -1, -1, 50, -1, -1};
    int length = sizeof(datas) / sizeof(datas[0]);
    addAll(datas, length);
    BTree T;
    // 因为树的内容尚未初始化，所以传指针
    // 如果传递的树的指针的值，则初始化只在函数的作用域中有效，所以必须传指针的指针
    // 跟insert的区别是insert中会有返回值，所以会把值传回来
    createTree(&T);
    preOrder(T);
    printf("test find: %d\n", find(50, T)->data);
    printf("test findMin: %d\n", findMin(T)->data);
    printf("test findMax: %d\n", findMax(T)->data);
    insert(100, T);
    insert(16, T);
    delete(16, T);
    delete(100, T);
    delete(30, T);
    preOrder(T);

    printf("\n");
    printf("press any key to exit~~~");
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
{ // 递归版本
    //if (T == NULL) return NULL;
    //if (e > T -> data) return find(e, T -> right);
    //if (e < T -> data) return find(e, T -> left);
    //if (e == T -> data) return T;
    // 递归版本结束

    // 非递归版本
    while (T)
    {
        if (e > T->data)
            T = T->right;
        if (e < T->data)
            T = T->left;
        if (e == T->data)
            return T;
    }
    return NULL;
}

Position findMin(BTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->left)
        findMin(T->left);
    else
        return T;
}

Position findMax(BTree T)
{
    if (T)
    {
        while (T->right)
            T = T->right;
    }
    return T;
}

BTree insert(ElemType e, BTree T)
{
    if (T == NULL)
    {
        T = (BTree)malloc(sizeof(BNode));
        T->data = e;
        T->left = T->right = NULL;
    }
    else
    {
        if (e > T->data)
        {
            T->right = insert(e, T->right);
        }
        else if (e < T->data)
        {
            T->left = insert(e, T->left);
        }
    }
    return T;
}

BTree delete (ElemType e, BTree T)
{
    if (!T)
        printf("create Tree firest!'");
    Position tmp;
    if (e > T->data)
        T->right = delete (e, T->right);
    if (e < T->data)
        T->left = delete (e, T->left);
    if (e == T->data)
    {
        if (T->left && T->right)
        {
            tmp = findMax(T->left);
            T->data = tmp->data;
            T->left = delete (T->data, T->left);
        }
        else
        {
            tmp = T;
            if (!T->left)
            {
                T = T->right;
            }
            else if (!T->right)
            {
                T = T->left;
            }
            free(T);
        }
    }
    return T;
}