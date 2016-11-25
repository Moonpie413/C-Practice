#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(int argc, char const *argv[]) {
    int *p = (int*) malloc(sizeof(int));
    *p = 3;
    printf("%d\n", *p);
    free(p);
    printf("%d\n", *p);
    queue = (Queue*) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("not null \n");
    }
    free(queue);
    if (queue == NULL) {
        printf("NULL\n");
    }
    return 0;
}
