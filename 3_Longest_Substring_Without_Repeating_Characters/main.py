'''
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
'''


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        candicate = list()
        currentLong = 0
        stop = False

        if not len(s):
            return 0

        while (not stop):
            for idx, c in enumerate(s):
                if c in candicate:
                    s = s[s.index(c) + 1:]
                    del candicate[:]
                    break

                candicate.append(c)

                if currentLong < len(candicate):
                    currentLong = len(candicate)

                if idx == len(s) - 1:
                    stop = True
                    break

        return currentLong


if __name__ == '__main__':
    s = Solution()
    print s.lengthOfLongestSubstring("abcabcbb")


