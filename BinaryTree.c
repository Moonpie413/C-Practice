#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef int ElemType;
typedef struct BNode
{
    ElemType data;
    struct BNode *left, *right;
} BNode, *BTree;


void createTree(BTree *t);

int main(int argc, char const *argv[]) {
    initQueue();
    add(1);
    add(2);
    printf("%d\n", queue -> front -> data);
    printf("%d\n", queue -> front -> next -> data);
    printf("%d\n", queue -> rear -> data);
    return 0;
}

void createTree(BTree *t) {

}
