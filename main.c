#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    FILE *input, *output;
    char a, s[30][30];
    int i = 0, j = 0, m = 0, n = 0, count = 0, b = 0;

    input = fopen("input.txt", "r");
    while (!feof(input)) {
        fscanf(input, "%c", &a);
        if (a == '1' || a == '0') {
            s[i][j] = a;
            j++;
        }
        if (a == '\n') {
            i++;
            j = 0;
        }
    }
    for (int n = 0; n < j; n++) {
        count = 0;
        for (int m = 0; m <= i; m++) {
            if (s[m][n] == '1' && count == 0) {
                count++;
                b = m + 1;
            }
            else if (s[m][n] == '1') {
                count++;
                if (count == 2) {
                    printf("%d: %d\n", b, m + 1);
                }
            }
        }
        if (count == 1) {
            printf("%d: %d\n", b, b);
        }
    }
    
    output = fopen("output.dot", "w");
    fprintf(output, "digraph Grah {\n");
    for (int n = 0; n < j; n++) {
        count = 0;
        for (int m = 0; m <= i; m++) {
            if (s[m][n] == '1' && count == 0) {
                count++;
                b = m + 1;
            }
            else if (s[m][n] == '1') {
                count++;
                if (count >= 2) {
                    fprintf(output, "%d -> %d\n", b, m + 1);
                }
            }
        }
        if (count == 1) {
            fprintf(output, "%d -> %d\n", b, b);
        }
    }
    for (int m = 0; m <= i; m++) {
        count = 0;
        for (int n = 0; n < j; n++) {
            if (s[m][n] == '1') {
                count++;
            }
        }
        if (count == 0) {
            fprintf(output, "%d\n", m + 1);
        }
    }
    fprintf(output, "}");
    fclose(output);

    return 0;
}
