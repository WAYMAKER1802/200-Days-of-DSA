//Climbing Stairs. You are climbing a staircase with n steps. You can climb either 1 step or 2 steps at a time.
//Find the number of distinct ways you can reach the top.
#include <stdio.h>

int climbStairs(int n)
{
    if (n <= 2)
        return n;

    int dp[n + 1];

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;

    printf("Enter number of stairs: ");
    scanf("%d", &n);

    int result = climbStairs(n);

    printf("Number of ways = %d\n", result);

    return 0;
}