#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef char ElemType;
typedef struct BNode
{
    ElemType data;
    struct BNode *left, *right;
} BNode, *BTree;

void createTree(BTree *t);
void preOrder(BTree T);

int main(int argc, char const *argv[]) {
    ElemType datas[] = {'A', 'B', '#', 'D', '#', '#', 'C', '#', '#'};
    int length = sizeof(datas) / sizeof(datas[0]);
    addAll(datas, length);
    BTree T;
    // 因为树的内容尚未初始化，所以传指针
    createTree(&T);
    preOrder(T);
    return 0;
}

void createTree(BTree *t) {
    char c;
    if (deque(&c)) {
        if (c == '#') {
            *t = NULL;
        } else {
            *t = (BTree) malloc(sizeof(BNode));
            if (!*t) exit(1);
            (*t) -> data = c;
            createTree(&(*t) -> left);
            createTree(&(*t) -> right);
        }
    }
}

void preOrder(BTree T) {
    if (T == NULL) {
        return;
    }
    printf("[%c] ", T -> data);
    preOrder(T -> left);
    preOrder(T -> right);
}
