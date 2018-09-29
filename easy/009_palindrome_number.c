#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// 耗时最快的解法
int isPalindromeNumberOne(int x) {
    if (x < 0)
        return 0;
    int div = 1;
    while (x / div >= 10) {
        div = div * 10;
    }
    while (x != 0) {
        int i = x / div;
        int r = x % 10;
        if (i != r)
            return 0;
        x = (x % div) / 10;
        div = div / 100;
    }
    return 1;
}

// 大多数人的解法
int isPalindromeMulti(int x) {
    int t = 0;
    int y = x;
    while (y != 0) {
        t = t * 10 + y % 10;
        y /= 10;
    }
    return t == x;
}

int isPalindrome(int x) {
    if (x > INT_MAX || x < INT_MIN || x < 0) {
        return 0;
    }
    char num[32];
    sprintf(num, "%d", x);
    int i;
    size_t len;
    for (i = 0, len = strlen(num); i < len / 2; i++) {
        if (num[i] != num[len - 1 - i])
            return 0;
    }
    return 1;
}

int main(int argc, const char *argv[]) {
    int result = isPalindrome(1221);
    printf("is palindrome number %s\n", result == 1 ? "true" : "false");
}