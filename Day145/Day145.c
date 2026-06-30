//Problem Statement : Given a string consisting of lowercase English letters, find the first non-repeating character. 
// If every character repeats, print -1.
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[26] = {0};

    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[str[i] - 'a'] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}