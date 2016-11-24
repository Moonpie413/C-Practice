#include <stdio.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} Sqlist;

Status GetElem(Sqlist L, int i, ElemType *e)
{
    if (L.length == 0 || i < 0 || i > L.length - 1) return ERROR;
    *e = L.data[i];
    return OK;
}

Status insert(Sqlist *L, int i, ElemType e) {
    int k;
    if (L -> length = MAXSIZE) return ERROR;
    /* 可插入的位置 0 ～ 最大长度加1 */
    if (i < 0 || i > L -> length + 1) return ERROR;
    for (k = L -> length - 1; k > i; k--) {
        L -> data[k + 1] = L -> data[k];
    }
    L -> data[i] = e;
    L -> length ++;
    return OK;
}

int main(int argc, char const *argv[]) {
    Sqlist *slist;
    insert(*slist, 0, *ElemType);
    return 0;
}
