#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void SwapVal(int *arr, int low, int hig)
{
    int temp = arr[low];
    arr[low] = arr[hig];
    arr[hig] = temp;
    return ;
}

int Partition(int *arr, int low, int hig)
{
    int val = arr[low];
    while (low < hig) {
        while (low < hig && val <= arr[hig]) {
            --hig;
        }

        SwapVal(arr, low, hig);

        while (hig > low && val >= arr[low]) {
            ++low;
        }
        SwapVal(arr, low, hig);
    }
    return low;
}

void QuackSort(int *arr, int low, int hig)
{
    if (low >= hig) {
        return;
    }

    int mid = Partition(arr, low, hig);
    QuackSort(arr, low, mid - 1);
    QuackSort(arr, mid + 1, hig);
}

int main()
{
    int nums[10] = {9,8,7,6,5,4,3,2,1,19};

    QuackSort(nums, 0, 9);

    for (int i = 0; i < 10; ++i) {
        printf("%d\t", nums[i]);
    }

    printf("\n");

}