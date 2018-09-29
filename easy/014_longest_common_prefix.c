#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strs == NULL || strsSize == 0) {
        return "";
    }

    char *longestCommonPrefixStr = strs[0];
    size_t len = strlen(longestCommonPrefixStr);
    char *result = NULL;
    int i;
    for (i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < strlen(strs[i]) && j < len && longestCommonPrefixStr[j] == strs[i][j]) {
            j++;
        }
        if (j == 0) {
            return "";
        }
        if (i == strsSize - 1) {
            result = malloc(j);
            result = strncpy(result, longestCommonPrefixStr, j);
            break;
        }
    }
    return result == NULL ? longestCommonPrefixStr : result;
}

int main(int argc, const char *argv[]) {
    char *strs[] = {"c", "c"};
    char *result = longestCommonPrefix((char **) &strs, 2);
    printf("%s\n", result);
}