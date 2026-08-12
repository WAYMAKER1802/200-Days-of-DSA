//Problem : You are given n activities. Each activity has a start time and an end time. Select the maximum number of activities that can be performed by one person, 
// assuming that a person can work on only one activity at a time.
//An activity can be selected only if its start time is greater than or equal to the end time of the previously selected activity.
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }

    // Sort activities by end time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (end[j] > end[j + 1]) {
                int temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    // Select activities greedily
    int count = 1;
    int lastEnd = end[0];

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastEnd) {
            count++;
            lastEnd = end[i];
        }
    }

    printf("Maximum number of activities = %d\n", count);

    return 0;
}