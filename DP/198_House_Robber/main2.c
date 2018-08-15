#include <stdio.h>
#include <string.h>

int max(int a, int b) {

    return a > b ? a : b;
}


/* The "memo" store the current max_value we can rob.
 * This means that the value stored in memo will be Incremental. ( "10, 9" is impossible)
 * */
int rob(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    int memo[numsSize];

    memset(memo, 0, sizeof(memo));

    if (numsSize == 1)
        return nums[numsSize - 1];
    else {
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]); // update curremt max

        for (int j = 2; j < numsSize; j++) {
            memo[j] = max(nums[j] + memo[j - 2], memo[j - 1]); // update current maxnum in memo. Is last value(which we cannot rob in this moment) maxmum or current value + (j-2) value
        }

    }

    for (int i = 0; i < numsSize; i++)
        printf("memo[%d] = %d \n", i, memo[i]);

    return memo[numsSize - 1];
}




int main(int argc, const char *argv[])
{

    /*int nums[] = {2,1,1,2};*/
    /*int nums[] = {1,2,3,1};*/
    /*int nums[] = {2,7,9,3,1};*/
                  /*2,7,11,11,12*/

    int nums[] = {2,7,9,3,1,3};
          /* memo = 2,7,11,11,12,14 */
    printf("%d \n", rob(nums, sizeof(nums) / sizeof(*nums)));

    return 0;
}
