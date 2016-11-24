#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[8];
    int age;
} Student, *Stu;

int main(int argc, char const *argv[]) {
    Student xiaoming;
    char test[8];
    int testInt[8];
    Stu stu = (Student*) malloc(sizeof(Student));
    // malloc(sizeof(Stu))是错误的，一个指针占4个字节
    xiaoming.age = 18;
    stu -> age = 19;
    printf("%d\n", xiaoming.age);
    printf("%d\n", stu -> age);
    printf("%d\n", (*stu).age);
    printf("sizeof Student: %d\n", sizeof(Student));
    printf("sizeof Stu: %d\n", sizeof(Stu));
    printf("sizeof char[8]: %d\n", sizeof(test));
    printf("sizeof int[8] : %d\n", sizeof(testInt));
    return 0;
}
