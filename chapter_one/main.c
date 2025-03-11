#include <stdio.h>
#include <stdlib.h>

#define ARMS 6



int checkClockwise(int snowflake1[6], int snowflake2[6], int start) {
    int offset, startingIndex;
    for (offset = 0; offset < ARMS; offset++) {
        startingIndex = start + offset;
        if (startingIndex >= 6) startingIndex = startingIndex - 6;
        if (snowflake1[offset] != snowflake2[startingIndex]) {
            return 0;
        }
    }

    return 1;
}

int checkCounterClockwise(int snowflake1[6], int snowflake2[6], int start) {
    int offset, startingIndex;
    for (offset = 0; offset < ARMS; offset++) {
        startingIndex = start - offset;
        if (startingIndex <= -1) startingIndex = startingIndex + 6;
        if (snowflake1[offset] != snowflake2[startingIndex]) {
            return 0;
        }
    }
    return 1;
}

int areIdentical(int snowflake1[6], int snowflake2[6]) {
    int start;

    for(start = 0; start < 6; start++) {
        if (checkCounterClockwise(snowflake1, snowflake2, start)) {
            return 1;
        }

        if (checkClockwise(snowflake1, snowflake2, start)) {
            return 1;
        }
    }
    return 0;
}

void identifyIdentical(int snowflakes[2][6]) {
    int i, j; 
    if (areIdentical(snowflakes[0], snowflakes[1])) {
        printf("Two identical snowflakes found.\n");
        return;
    }
    printf("No two snowflakes are alike.\n");
}

int main() {
//   int a[5] = {1, 2, 3, 1, 5};
//    identifyIdentical(a, 5);

    int snowflakes [2][6] = {
        {1, 2, 3, 4, 5, 6},
        {3, 4, 5, 6, 1, 2}
    };

    identifyIdentical(snowflakes);

    return 0;
}
