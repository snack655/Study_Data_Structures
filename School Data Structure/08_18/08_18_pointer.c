#include <stdio.h>


int main() {
    int i = 7;
    int *p, **pp;

    p = &i;
    pp = &p;
    
    printf("p\'s Address = %p\n", p);
    printf("pp\'s Address = %p\n", pp);
    (*p)++;
    printf("i = %d\n", i);
    printf("p\'s Address = %p\n", p);
    printf("pp\'s Address = %p\n", pp);
    
    return 0;
}
