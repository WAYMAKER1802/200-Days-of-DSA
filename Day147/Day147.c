//Problem: Check if Two Strings are Anagrams
//Given two strings, determine whether they are anagrams of each other.
//Two strings are anagrams if they contain the same characters with the same frequency.
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int freq[26] = {0};

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if (strlen(str1) != strlen(str2)) {
        printf("Strings are Not Anagrams.\n");
        return 0;
    }

    for (int i = 0; str1[i] != '\0'; i++) {
        freq[str1[i] - 'a']++;
        freq[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("Strings are Not Anagrams.\n");
            return 0;
        }
    }

    printf("Strings are Anagrams.\n");

    return 0;
}