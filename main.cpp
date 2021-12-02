#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>


union test {
    short value;
    char va[2];
} ;

void TestAct(test &t)
{
    std::cout << "val = " << t.va[0] << t.va[1] << std::endl;

    if (t.va[0] == 1 || t.va[0] == 2) {
        std::cout << "name\n";
    }

    printf("%d  %d", t.va[0], t.va[1]);
}

int main()
{
    
    char dummy = 0;
    char *stack = (char *)malloc(128);
    memcpy(stack, &dummy, 128);
    printf("chenchuanying%s****%d\n", stack, strlen(stack));

    test t;
    t.value = 0x0102;

    std::cout << sizeof(short) << std::endl;
    
    TestAct(t);
}
