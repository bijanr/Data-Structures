#include <stdio.h>

typedef struct student {
    int roll;
    char name[128];
    float marks1;
    float marks2;
    float sum;
}S;

int main()
{
    S P;
    P.marks1 = 89;
    P.marks2 = 99;
}