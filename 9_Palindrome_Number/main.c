#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int y = x;

    int a = 0;

    while (x > 0) {
        int b = x % 10;
        a = a * 10 + b;
        x /= 10;
    }

    return a == y;
}


int main(int argc, const char *argv[])
{
	assert(isPalindrome(121) == true);
	assert(isPalindrome(1000000001) == true);

    return 0;
}
