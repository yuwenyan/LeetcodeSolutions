/**
 * Easy
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int *) malloc(2*sizeof(int));
    for (int i = 0; i < numsSize-1; ++i) {
        for (int j = i+1; j < numsSize; ++j) {
            if (*(nums+i)+*(nums+j) == target) {
                *result = i;
                *(result+1) = j;
            }
        }
    }
    return result;
}


int main(void)
{
    int testInput[3] = {3, 2, 4};
    int testTarget = 6;
    int testOutput[2] = {1, 2};
    int* output;

    output = twoSum(testInput, 3, 6);

    printf("Expected output:\n");
    for (int i=0; i<2; ++i) {
        printf("%i  ", testOutput[i]);
    }
    printf("\nTest output:\n");
    for ( int i=0; i<2; ++i) {
        printf("%i  ", *(output+i));
    }
    printf("\n");

    free(output);
    return 0;
}