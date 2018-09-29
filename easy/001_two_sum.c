#include <stdlib.h>
#include <stdio.h>

/**
 * 解法一 暴力枚举
 * @param const int * nums
 * @param int numsSize
 * @param int target
 * @return int * result
 */
int *twoSumSolution1(const int *nums, int numsSize, int target) {
    int i, j, *result;
    result = malloc(sizeof(int) * 2);
    for (i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        for (j = i + 1; j < numsSize; j++) {
            if (diff == nums[j]) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}

// --------------------------------------------------------------------------------------------------------------

typedef struct _obj {
    int val;
    int index;
} obj;

int cmp(const void *a, const void *b) {
    return ((obj *) a)->val - ((obj *) b)->val;
}

/**
 * 解法二 快排 + 双指针搜索
 * @param const int * nums
 * @param int numsSize
 * @param int target
 * @return int * result
 */
int *twoSumSolution2(const int *nums, int numsSize, int target) {
    int i;
    int *result;
    obj *v = malloc(sizeof(*v) * numsSize);
    for (i = 0; i < numsSize; i++) {
        v[i].index = i;
        v[i].val = nums[i];
    }
    qsort(v, (size_t) numsSize, sizeof(*v), cmp);

    i = 0;
    int j = numsSize - 1;
    result = malloc(sizeof(int) * 2);
    while (i < j) {
        int diff = target - v[i].val;
        if (diff > v[j].val) {
            if (i < j) i++;
        } else if (diff < v[j].val) {
            if (j > i) j--;
        } else {
            result[0] = v[i].index;
            result[1] = v[j].index;
            break;
        }
    }
    free(v);
    return result;
}

// --------------------------------------------------------------------------------------------------------------
#ifndef HASH_SIZE
#define HASH_SIZE 10000
#endif
typedef struct _m {
    int vals[HASH_SIZE];

    void (*put)(struct _m *, int, int);

    int (*get)(struct _m *, int);
} m;

int hash(int k) {
    int mod = k % HASH_SIZE;
    return mod < 0 ? mod + HASH_SIZE : mod;
}

void put(m *map, int k, int v) {
    map->vals[hash(k)] = v;
}

int get(m *map, int k) {
    return map->vals[hash(k)];
}

/**
 * 解法三 hash表
 * @param const int * nums
 * @param int numsSize
 * @param int target
 * @return int * result
 */
int *twoSumSolution3(const int *nums, int numsSize, int target) {
    int *result = malloc(sizeof(int) * 2);
    m *map = malloc(sizeof(*map));
    map->put = put;
    map->get = get;
    int i;
    for (i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        int index;
        if ((index = map->get(map, diff)) > 0) {
            result[0] = --index;
            result[1] = i;
            break;
        } else {
            map->put(map, nums[i], i + 1);
        }
    }
    return result;
}

int main(int argc, const char *argv[]) {
    int nums[5] = {-1,-2,-3,-4,-5};
    int *result = twoSumSolution3((int *) &nums, 5, -8);
    printf("[%d, %d]\n", result[0], result[1]);
}