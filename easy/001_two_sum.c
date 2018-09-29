#include <stdlib.h>
#include <stdio.h>

typedef struct obj {
    int val;
    int index;
};

int compare(const void *a, const void *b) {
    return ((struct obj *) a)->val - ((struct obj *) b)->val;
}

int *twoSum(int *nums, int numSize, int target) {
    int i, j, diff, *result;
    struct obj *objs = malloc(sizeof(*objs) * numSize);
    for (i = 0; i < numSize; i++) {
        objs[i].index = i;
        objs[i].val = nums[i];
    }
    qsort(objs, numSize, sizeof(*objs), compare);
    i = 0;
    j = numSize - 1;
    result = malloc(sizeof(int) * 2);
    while (i < j) {
        diff = target - objs[i].val;
        if (diff > objs[j].val) {
            if (i < j) i++;
        } else if (diff < objs[j].val) {
            if (j > i) j--;
        } else {
            result[0] = objs[i].index;
            result[1] = objs[j].index;
            break;
        }
    }
    free(objs);
    return result;
}

int main(int argc, const char *argv[]) {
    int nums[5] = {2, 5, 7, 7, 9};
    int *result = twoSum((int *) &nums, 5, 12);
    printf("[%d, %d]\n", result[0], result[1]);
}