#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int main()
{
    char dummy = 0;
    char *stack = (char *)malloc(128);
    memcpy(stack, &dummy, 128);
    printf("chenchuanying%s****%d\n", stack, strlen(stack));
}