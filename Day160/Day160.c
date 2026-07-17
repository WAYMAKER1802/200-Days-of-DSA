//Problem : Given a string s, determine if it is a palindrome after:
//Converting all uppercase letters to lowercase.
//Removing all non-alphanumeric characters.
//Return true if it is a palindrome, otherwise false.
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {

        while (left < right && !isalnum(s[left]))
            left++;

        while (left < right && !isalnum(s[right]))
            right--;

        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }

    return true;
}