#include <stdio.h>
#include <string.h>
#include <assert.h>


/*
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 */

/*
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 *              because they are adjacent houses.
 */



int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {

    if (numsSize == 0)
        return 0;
    else if (numsSize == 1)
        return nums[numsSize - 1];
    else if (numsSize == 2)
        return max(nums[0], nums[1]);

    int memo[numsSize];
    int memo2[numsSize];

    memset(memo, 0, sizeof(memo));
    memset(memo2, 0, sizeof(memo2));


    /**
     * Because it's circule, so cannot both rob first house and last house.
     * We should caculate "house1 to (last - 1)" and "house2 to last one" individually
     */
    memo[0] = nums[0];
    memo[1] = max(nums[1], nums[0]);
    for (int i = 2; i < numsSize - 1; i++) {
        memo[i] = max(nums[i] + memo[i - 2], memo[i - 1]);
    }

    memo2[1] = nums[1];
    memo2[2] = max(nums[1], nums[2]);
    for (int i = 3; i < numsSize; i++) {
        memo2[i] = max(nums[i] + memo2[i - 2], memo2[i - 1]);
    }

    return max(memo[numsSize - 2], memo2[numsSize - 1]);
}


int main(int argc, const char *argv[]) {

    int nums[10][10] = {
        {1, 2, 3, 1},
        {2, 1, 1, 2},
        {2, 3, 2},
        {1, 2, 1, 1},
        {1, 3, 1, 3, 100},
        {4, 1, 2, 7, 5, 3, 1},
    };

    int size_ans[10][10] = {
        {4, 4},
        {4, 3},
        {3, 3},
        {4, 3},
        {5, 103},
        {7, 14},
        {0, 0},
    };

    for (int i = 0; i < 10; i++) {
        if (size_ans[i][0] == 0)
            break;

        assert(rob(nums[i], size_ans[i][0]) == size_ans[i][1]);
    }

    return 0;
}
