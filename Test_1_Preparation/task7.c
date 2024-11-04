#include <stdio.h>

typedef struct {
    int numInClass;
    char name[20];
    int avgGrade;
} Student;

int main(void) {
    Student student = {1, "Ivan", 5};
    printf("%d %s %d", student.numInClass, student.name, student.avgGrade);
    return 0;
}
