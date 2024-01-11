#include <stdio.h>

int main()
{
    int a=2;
    int d=4;
    int *b, *c;
    b = &d;
    c=&a;

    // swap
    *b = *b^*c;
    *c=*b^*c;
    *b=*b^*c;

    printf("b: %d, c:%d\n", *b, *c);
}