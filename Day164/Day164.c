//Problem Statement : Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
int singleNumber(int* nums, int numsSize) {

    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }

    return ans;
}