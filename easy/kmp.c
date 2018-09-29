#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bf(char *haystack, char *needle) {
    size_t haystack_len, needle_len;
    needle_len = strlen(needle);
    if (needle_len == 0) return 0;
    int i = 0, j = i;
    haystack_len = strlen(haystack);
    while (i < haystack_len && j < needle_len) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == needle_len) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    printf("%d\n", bf("abbdabbc", "abc"));
}