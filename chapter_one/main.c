#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARMS 6
#define SIZE 100000

typedef struct snowflake_node {
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;

int checkClockwise(int snowflake1[6], int snowflake2[6], int start) {
    int offset, snow2Idx;
    for (offset = 0; offset < ARMS; offset++) {
        snow2Idx = start + offset;
        if (snow2Idx >= 6) snow2Idx = snow2Idx - 6;
        if (snowflake1[offset] != snowflake2[snow2Idx]) {
            return 0;
        }
    }

    return 1;
}

int checkCounterClockwise(int snowflake1[6], int snowflake2[6], int start) {
    int offset, snow2Idx;
    for (offset = 0; offset < ARMS; offset++) {
        snow2Idx = start - offset;
        if (snow2Idx <= -1) snow2Idx = snow2Idx + 6;
        if (snowflake1[offset] != snowflake2[snow2Idx]) {
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

void identifyIdentical(snowflake_node *snowflakes[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        while (snowflakes[i]->next != NULL) {
            int snowflake1[6];
            int snowflake2[6]; 
            memcpy(snowflake1, snowflakes[i]->snowflake, sizeof(int) * 6);
            memcpy(snowflake2, snowflakes[i]->next->snowflake, sizeof(int) * 6);
            if (areIdentical(snowflake1, snowflake2)) {
               printf("Twin snowflakes found\n"); 
            }
            snowflakes[i] = snowflakes[i]->next;
        }
    }
    printf("No two snowflakes are alike\n");
}

int code(int snowflake[]) {
    return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] + snowflake[4] + snowflake[5]) % SIZE;
}

int main() {
    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow;
    int n, i, j, snowflake_code;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        snow = malloc(sizeof(snowflake_node));
        if (snow == NULL) {
            printf("malloc err\n");
            return -1;
        }
        for (j = 0; j < 6; j++) {
            scanf("%d", &snow->snowflake[j]);
        }
        snowflake_code = code(snow->snowflake);
        snow->next = snowflakes[snowflake_code];
        snowflakes[snowflake_code] = snow;
    }

    identifyIdentical(snowflakes);
    return 0;
}
