#include <stdio.h>

int main() {
    char str[] = "Hello";   // 배열의 이름은 주소
    char * p;
    p = str;
    
    while (*p)
        putchar(*p++); // 문자 출력 후 주소 증가
    return 0;
}


