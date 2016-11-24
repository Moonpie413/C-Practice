#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *NodePtr;

typedef struct Queue {
    NodePtr front, rear;
} Queue;

Queue *queue;

Status initQueue() {
    queue = (Queue*) malloc(sizeof(Queue));
    NodePtr head = (NodePtr) malloc(sizeof(Node));
    if (!queue || !head) {
        return 0;
    }
    queue -> front = queue -> rear = head;
    return 1;
}

Status add(ElemType e) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode -> data = e;
    newNode -> next = NULL;
    queue -> rear -> next = newNode;
    queue -> rear = newNode;
    return 1;
}
