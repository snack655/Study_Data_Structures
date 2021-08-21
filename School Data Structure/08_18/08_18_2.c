#include <stdio.h>
extern int i;
void func2();
void func1()
{
    i++;
    printf("extern func1 i = %d \n", i);
    func2();
}

void func2()
{
    i++;
    printf("extern func2 i = %d \n", i);
}
