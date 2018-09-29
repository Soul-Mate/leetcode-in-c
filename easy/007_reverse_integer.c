//
// Created by 徐元昌 on 2018/8/10.
//
#include <stdio.h>
#include <limits.h>


int reverse(int x) {
    int result = 0;
    int mod = 0;
    while (x != 0) {
        mod = x % 10;
        if (result > INT_MAX / 10 || result < INT_MIN / 10) {
            return 0;
        }
        result = result * 10 + mod;
        x /= 10;
    }
    return result;
}

int main(int argc, const char *argv[]) {
    int result = reverse(1534236469);
    printf("%d\n", result);
}