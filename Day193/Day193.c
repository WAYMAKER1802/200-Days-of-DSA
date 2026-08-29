//Question : Given n pairs of parentheses, generate all combinations of well-formed parentheses.
#include <stdlib.h>
#include <string.h>

void generate(char** result, int* returnSize, char* current,
              int pos, int open, int close, int n)
{
    // If the string is complete
    if (pos == 2 * n)
    {
        current[pos] = '\0';

        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    // Add '(' if we still have opening brackets available
    if (open < n)
    {
        current[pos] = '(';

        generate(result, returnSize, current,
                 pos + 1, open + 1, close, n);
    }

    // Add ')' only if it will not make the string invalid
    if (close < open)
    {
        current[pos] = ')';

        generate(result, returnSize, current,
                 pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    // Maximum number of valid combinations for n <= 8 is 1430
    char** result = (char**)malloc(1430 * sizeof(char*));

    *returnSize = 0;

    char* current = (char*)malloc((2 * n + 1) * sizeof(char));

    generate(result, returnSize, current, 0, 0, 0, n);

    free(current);

    return result;
}