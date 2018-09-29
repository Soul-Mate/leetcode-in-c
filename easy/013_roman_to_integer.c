#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

typedef struct _map {
    int arr[97];
    void *(*get)(struct _map *map, const char s);
} roman_map;

int hash_char(const char s) {
    int hash = 0;
    return (10 * hash + s) % 97;
}

void *roman_map_get(roman_map *map, const char s) {
    return (void *) &map->arr[hash_char(s)];
}

roman_map *init_roman_map() {
    roman_map *map;
    if (!(map = malloc(sizeof(roman_map))))
        return NULL;
    map->get = roman_map_get;
    map->arr[hash_char('I')] = 1;
    map->arr[hash_char('V')] = 5;
    map->arr[hash_char('X')] = 10;
    map->arr[hash_char('L')] = 50;
    map->arr[hash_char('C')] = 100;
    map->arr[hash_char('D')] = 500;
    map->arr[hash_char('M')] = 1000;
    return map;
}

int romanToInt(char *s) {
    int i;
    int result = 0;
    size_t len = strlen(s);
    roman_map *map = init_roman_map();
    for (i = 0; i < len; i++) {
        switch (s[i]) {
            case 'I':
                if (i + 1 < len && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    result += *(int *) map->get(map, s[i + 1]) - *(int *) map->get(map, s[i]);
                    i++;
                } else {
                    result += *(int *) map->get(map, s[i]);
                }
                break;
            case 'X':
                if (i + 1 < len && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    result += *(int *) map->get(map, s[i + 1]) - *(int *) map->get(map, s[i]);
                    i++;
                } else {
                    result += *(int *) map->get(map, s[i]);
                }
                break;
            case 'C':
                if (i + 1 < len && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    result += *(int *) map->get(map, s[i + 1]) - *(int *) map->get(map, s[i]);
                    i++;
                } else {
                    result += *(int *) map->get(map, s[i]);
                }
                break;
            default:
                result += *(int *) map->get(map, s[i]);
        }
    }
    free(map);
    return result;
}

// 速度最快的解法
int romanToIntFirst(char *s) {

    int num = 0, flag = 0, tem = 0, temold, i = 0, len;

    while (s[i] != '\0') {
        i++;
    }
    len = i - 1;
    switch (s[len]) {
        case 'I':
            tem = 1;
            break;
        case 'V':
            tem = 5;
            break;
        case 'X':
            tem = 10;
            break;
        case 'L':
            tem = 50;
            break;
        case 'C':
            tem = 100;
            break;
        case 'D':
            tem = 500;
            break;
        case 'M':
            tem = 1000;
            break;
    }
    num = temold = tem;
    for (len = i - 2; len >= 0; len--) {
        switch (s[len]) {
            case 'I':
                tem = 1;
                break;
            case 'V':
                tem = 5;
                break;
            case 'X':
                tem = 10;
                break;
            case 'L':
                tem = 50;
                break;
            case 'C':
                tem = 100;
                break;
            case 'D':
                tem = 500;
                break;
            case 'M':
                tem = 1000;
                break;
        }
        if (tem < temold) {
            num -= tem;
            temold = tem;
        } else {
            num += tem;
            temold = tem;
        }
    }

    return num;

}

// 大多数人的解法
int romanToIntMulti(char *s) {
    unsigned long length = strlen(s);
    int *intArray = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        char c = *(s + i);
        if (c == 'I') {
            intArray[i] = 1;
        } else if (c == 'V') {
            intArray[i] = 5;
        } else if (c == 'X') {
            intArray[i] = 10;
        } else if (c == 'L') {
            intArray[i] = 50;
        } else if (c == 'C') {
            intArray[i] = 100;
        } else if (c == 'D') {
            intArray[i] = 500;
        } else if (c == 'M') {
            intArray[i] = 1000;
        }
    }
    int res = 0;
    for (int i = 0; i < length; i++) {
        if ((i < length - 1) && intArray[i] < intArray[i + 1]) {
            res -= intArray[i];
        } else {
            res += intArray[i];
        }
    }
    return res;
}

int main(int argc, const char *argv[]) {
    int result = romanToInt("IVII");
    printf("IVII = %d\n", result);
}