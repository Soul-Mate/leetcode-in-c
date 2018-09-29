int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int i = 0, j = 1, count = 1;
    while (i < numsSize && j < numsSize) {
        if (nums[i] == nums[j]) j++;
        else {
            nums[count++] = nums[j];
            i++;
        }
    }
    return count;
}

int removeDuplicatesFast(int *nums, int numsSize) {
    int i, j = 0;
    int num;
    if (numsSize <= 1)
        return numsSize;
    for (i = 1; i < numsSize; i++) {
        if (nums[j] != nums[i]) {
            nums[++j] = nums[i];
        }
    }
    return j + 1;
}