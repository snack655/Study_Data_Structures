#include <stdio.h>

long factorial(long c)
{
    return((c == 0) ? 1 : c * factorial(c - 1));
}

int main() {
    long cnt = 0, n;
    
    for(cnt = 0; cnt <= 10; cnt++) {
        n = factorial(cnt);
        printf("%d != %d\n", cnt, n);
    }
    return 0;
}
