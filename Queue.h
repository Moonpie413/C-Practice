#include <stdlib.h>

typedef char ElemType;
typedef int Status;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *NodePtr;

typedef struct Queue {
    NodePtr front, rear;
} Queue;

Queue *queue;
int size;

Status add(ElemType e) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode -> data = e;
    newNode -> next = NULL;
    if (queue == NULL) {
        queue = (Queue*) malloc(sizeof(Queue));
        if (!queue) return 0;
        queue -> front = queue -> rear = newNode;
    } else {
        queue -> rear -> next = newNode;
        queue -> rear = newNode;
    }
    size++;
    return 1;
}

Status addAll(ElemType datas[], int length) {
    if (datas == NULL || length < 1) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        add(datas[i]);
    }
    return 1;
}

Status deque(ElemType *element) {
    if (size < 1) {
        return 0;
    }
    if (queue -> front == queue -> rear) {
        *element = queue -> front -> data;
        free(queue);
        queue = NULL;
    } else {
        *element = queue -> front -> data;
        NodePtr p = queue -> front;
        queue -> front = queue -> front -> next;
        free(p);
    }
    size--;
    return 1;
}
