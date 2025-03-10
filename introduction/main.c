#include <stdio.h>

#define MAX_LINES 100

int shortestLineIndex(int lines[], int n) {
    int j;
    int shortest = 0;
    for (j = 0; j < n; j++){
        if (lines[j] < lines[shortest]) {
            shortest = j;
        }
    }
    return shortest;
}

int solve(int lines[], int n, int m) {
    int i, shortest;
    for (i = 0; i < m; i++) {
        shortest = shortestLineIndex(lines, n);
        printf("Shortest line index: %d\n", lines[shortest]);
        lines[shortest]++;
    }
    return 0;
}

int main() {
    int lines[MAX_LINES];
    int n, m, i;
    scanf("%d%d", &n, &m);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &lines[i]);
    }

    solve(lines, n, m);
    return 0;
}
