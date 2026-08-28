//Question : Given a string s containing uppercase and lowercase English letters, remove any two adjacent characters if they are the same letter but different cases.
//Keep doing this until no such pair remains.
#include <stdio.h>
#include <string.h>

void makeGood(char s[])
{
    int top = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (top > 0 &&
            (s[top - 1] - s[i] == 32 ||
             s[i] - s[top - 1] == 32))
        {
            // Remove the previous character
            top--;
        }
        else
        {
            // Push current character
            s[top] = s[i];
            top++;
        }
    }

    s[top] = '\0';
}

int main()
{
    char s[1000];

    printf("Enter the string: ");
    scanf("%999s", s);

    makeGood(s);

    printf("Good string: %s\n", s);

    return 0;
}