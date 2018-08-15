#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// start from index 0 or start from index 1
/*int rob(int* nums, int numsSize) {*/

    /*int sum1 = 0, sum2 = 0;*/

    /*for (int i = 0; i < numsSize; i+=2) {*/
        /*sum1 += nums[i];*/
        /*if ((i + 1) < numsSize)*/
            /*sum2 += nums[i + 1];*/
    /*}*/

    /*return sum1 > sum2 ? sum1 : sum2;*/

/*}*/


int rob_max(int *nums, int start, int *memo);

int rob(int *nums, int numsSize) {

    int *memo = NULL;
    int max = 0;

    memo = (int *)malloc(numsSize * sizeof(*memo));
    if (!memo)
        return -1;

    memset(memo, 0, numsSize * sizeof(*memo));

    if (numsSize == 0)
        return 0;
    else if (numsSize == 1)
        return *nums;

    for (int i = 0; i < numsSize; i++) {
        rob_max(nums, i, memo);
    }

    for (int i = 0; i < numsSize; i++) {
        if (max < memo[i])
            max = memo[i];
    }

    return max;
}

int rob_max(int *nums, int start, int *memo) {
    int max = 0;

    if (start < 2)
        memo[start] = nums[start];
    else {
        for (int i = 0; i < start - 1; i++) {
            if (max < memo[i])
                max = memo[i];
        }
        memo[start] = nums[start] + max;
    }

    return 0;
}




int main(int argc, const char *argv[])
{
    /*int nums[4] = {2,1,1,2};*/
    int nums[4] = {1,2,3,1};
    /*int nums[5] = {2,7,9,3,1};*/
                     /*2,7,11,11,12*/

    /*int nums[5] = {2,7,9,3,1,3};*/
                     /*2,7,11,10,12,14*/
                     /*2,7,11,11,12,14*/
    printf(" %d \n", rob(nums, sizeof(nums) / sizeof(*nums)));

    return 0;
}
