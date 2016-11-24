#include <stdio.h>
#include <stdlib.h>

typedef int *intp;

/*
传入的参数是一个二级指针
 */
void test(intp *p) {
    printf("%p\n", *p);
    printf("%d\n", **p);
}

int main(int argc, char const *argv[]) {
    intp p = (int*) malloc(sizeof(int));
    *p = 3;
    printf("%p\n", p);
    printf("%d\n", *p);
    test(&p);
    return 0;
}
