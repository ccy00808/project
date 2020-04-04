#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void BackTrack(int *nums, bool *mark, int *path, int deep, int maxDeep)
{
    if(deep >= maxDeep) {
        for (int i = 0; i < maxDeep; ++i) {
            printf("%d\t", path[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < maxDeep; ++i) {
        if (mark[i] == true) {
            continue;
        }

        mark[i] = true;
        path[deep++] = nums[i];

        BackTrack(nums, mark, path, deep, maxDeep);

        mark[i] = false;
        --deep;
    }
}

int main()
{
    int nums[6] = {1, 2, 3, 4, 5, 6};
    bool mark[10] = {false};
    int path[10] = {0};
    BackTrack(nums, mark, path, 0, 6);
     return 0;
}