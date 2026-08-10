//Problem: Assign Cookies. You have n children, and each child has a greed factor g[i]. You also have m cookies, where each cookie has a size s[i].
//A child is satisfied if: cookie size >= child's greed factorl. Each child can receive at most one cookie. Find the maximum number of satisfied children.
#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findContentChildren(int g[], int n, int s[], int m)
{
    sort(g, n);
    sort(s, m);

    int child = 0;
    int cookie = 0;
    int satisfied = 0;

    while (child < n && cookie < m)
    {
        if (s[cookie] >= g[child])
        {
            satisfied++;
            child++;
            cookie++;
        }
        else
        {
            cookie++;
        }
    }

    return satisfied;
}

int main()
{
    int n, m;

    printf("Enter number of children: ");
    scanf("%d", &n);

    int g[n];

    printf("Enter greed factors:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &g[i]);
    }

    printf("Enter number of cookies: ");
    scanf("%d", &m);

    int s[m];

    printf("Enter cookie sizes:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &s[i]);
    }

    int result = findContentChildren(g, n, s, m);

    printf("Maximum satisfied children = %d\n", result);

    return 0;
}