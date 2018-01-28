
/**
 * https://leetcode.com/problems/hamming-distance/description/
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 *
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are different. */



int hammingDistance(int x, int y) {

    int xor = x ^ y;
    int ret = 0;

    while (xor) {
        ret += (xor & 0x1); // if bit[0] equals 1, then hamming distance plus one.
        xor >>= 1;
    }
    return ret;
}
