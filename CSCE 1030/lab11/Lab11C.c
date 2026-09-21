#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return 1;
    }
    char target;
    int chars = 0, lines = 0, words = 0;

    while ((target = fgetc(file)) != EOF) {
        if (!isspace(target)) {
            chars++; // Count all characters except whitespaces
        }
        if (target == '\n') {
            lines++; // Count newlines
        }
        if (target == ' ' || target == '\t' || target == '\n') {
            words++; // Count words based on spaces, tabs, or newlines
        }
    }
    // If the last character is not a newline, count the last line
    if (chars > 0 && target != '\n') {
        lines++;
        words++; // Count the last word if it doesn't end with a newline
    }
    fclose(file);
    printf("Number of characters = %d\n", chars);
    printf("Number of words = %d\n", words);
    printf("Number of lines = %d\n", lines);
}