//Problem Statement: Given an array of distinct integers candidates and a target integer target,
// return all unique combinations of candidates where the chosen numbers sum to target.
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* path, int pathSize,
               int*** result, int* returnSize, int** returnColumnSizes) {

    if (target == 0) {
        (*result) = realloc(*result, (*returnSize + 1) * sizeof(int*));
        (*returnColumnSizes) = realloc(*returnColumnSizes,
                                       (*returnSize + 1) * sizeof(int));

        (*result)[*returnSize] = (int*)malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++)
            (*result)[*returnSize][i] = path[i];

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];

        backtrack(candidates,
                  candidatesSize,
                  target - candidates[i],
                  i,
                  path,
                  pathSize + 1,
                  result,
                  returnSize,
                  returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;
    *returnColumnSizes = NULL;

    int** result = NULL;

    int* path = (int*)malloc(target * sizeof(int));

    backtrack(candidates,
              candidatesSize,
              target,
              0,
              path,
              0,
              &result,
              returnSize,
              returnColumnSizes);

    free(path);

    return result;
}