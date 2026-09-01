//Minimum Moves to Clean the Classroom. You are given a grid representing a classroom:
//S → starting position
//L → litter that must be collected
//R → reset area; restores energy to maximum
//X → obstacle
//. → empty space
//You are also given the student's maximum energy.
//Moving to an adjacent cell costs 1 energy. The student cannot move when energy becomes 0, unless they move onto an R cell, which restores energy.
//Return the minimum number of moves required to collect all litter. If impossible, return -1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LITTER 10

typedef struct {
    int r;
    int c;
    int energy;
    int mask;
} State;

int main() {
    int rows, cols, energy;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter maximum energy: ");
    scanf("%d", &energy);

    char grid[25][25];

    printf("Enter the classroom grid:\n");

    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
    }

    int startR = -1, startC = -1;
    int litterCount = 0;

    int litterID[25][25];

    // Initialize litter IDs
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            litterID[i][j] = -1;
        }
    }

    // Find S and number the L cells
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == 'S') {
                startR = i;
                startC = j;
            }

            if (grid[i][j] == 'L') {
                litterID[i][j] = litterCount;
                litterCount++;
            }
        }
    }

    // No litter
    if (litterCount == 0) {
        printf("Minimum moves = 0\n");
        return 0;
    }

    int totalMasks = 1 << litterCount;

    /*
        State = row, column, energy, mask

        mask:
        1 = litter still remains
        0 = litter already collected
    */

    int totalStates =
        rows * cols * (energy + 1) * totalMasks;

    char *visited = calloc(totalStates, sizeof(char));

    State *queue = malloc(totalStates * sizeof(State));

    int front = 0;
    int rear = 0;

    // Initially all litter is uncollected
    int initialMask = totalMasks - 1;

    queue[rear].r = startR;
    queue[rear].c = startC;
    queue[rear].energy = energy;
    queue[rear].mask = initialMask;
    rear++;

    int startIndex =
        (((startR * cols + startC) * (energy + 1) + energy)
         * totalMasks + initialMask);

    visited[startIndex] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int moves = 0;

    while (front < rear) {

        int levelEnd = rear;

        // Process all states having the same number of moves
        while (front < levelEnd) {

            State current = queue[front++];

            int r = current.r;
            int c = current.c;
            int e = current.energy;
            int mask = current.mask;

            // All litter collected
            if (mask == 0) {
                printf("Minimum moves = %d\n", moves);

                free(visited);
                free(queue);

                return 0;
            }

            // Cannot move without energy
            if (e == 0) {
                continue;
            }

            // Try four directions
            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols) {
                    continue;
                }

                // Cannot cross obstacle
                if (grid[nr][nc] == 'X') {
                    continue;
                }

                // Every move costs 1 energy
                int newEnergy = e - 1;

                // Reset area gives full energy
                if (grid[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Copy current litter mask
                int newMask = mask;

                // If we reach litter, collect it
                if (grid[nr][nc] == 'L') {

                    int id = litterID[nr][nc];

                    newMask = newMask & ~(1 << id);
                }

                // Calculate state index
                int index =
                    (((nr * cols + nc) * (energy + 1)
                      + newEnergy)
                     * totalMasks + newMask);

                // If this state has not been visited
                if (!visited[index]) {

                    visited[index] = 1;

                    queue[rear].r = nr;
                    queue[rear].c = nc;
                    queue[rear].energy = newEnergy;
                    queue[rear].mask = newMask;

                    rear++;
                }
            }
        }

        // One BFS level = one move
        moves++;
    }

    printf("Minimum moves = -1\n");

    free(visited);
    free(queue);

    return 0;
}
