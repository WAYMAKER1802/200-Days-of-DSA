//Find the Minimum and Maximum Number of Nodes Between Critical Points, a Medium linked-list problem.
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int value) {
    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

void nodesBetweenCriticalPoints(struct ListNode* head) {

    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        printf("[-1, -1]\n");
        return;
    }

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;

    int index = 1;

    int first = -1;
    int last = -1;

    int minDistance = 1000000;

    while (curr->next != NULL) {

        // Check whether current node is a critical point
        if ((curr->val > prev->val && curr->val > curr->next->val) ||
            (curr->val < prev->val && curr->val < curr->next->val)) {

            if (first == -1) {
                // First critical point
                first = index;
            } 
            else {
                // Distance from previous critical point
                int distance = index - last;

                if (distance < minDistance)
                    minDistance = distance;
            }

            last = index;
        }

        prev = curr;
        curr = curr->next;
        index++;
    }

    // Fewer than two critical points
    if (first == -1 || first == last) {
        printf("[-1, -1]\n");
    } 
    else {
        int maxDistance = last - first;

        printf("[%d, %d]\n", minDistance, maxDistance);
    }
}

int main() {

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    printf("Enter the node values: ");

    for (int i = 0; i < n; i++) {

        int value;
        scanf("%d", &value);

        struct ListNode* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Answer: ");

    nodesBetweenCriticalPoints(head);

    return 0;
}