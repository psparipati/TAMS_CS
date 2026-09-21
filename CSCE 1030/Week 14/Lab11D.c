#include <stdio.h>

int main(int argc, char* argv[]) {
    #define METERS_TO_FEET 3.28084
    #define convert(x) (x * METERS_TO_FEET)
    if (argc != 2) {
        printf("Invalid number of arguments passed to program: %d\n", argc - 1);
        return 1;
    }
    FILE *file;
    file = fopen("meters.txt", "r");
    if (file == NULL) {
        printf("Unable to open input file\n");
        return 1;
    }
    FILE *output;
    output = fopen(argv[1], "w");
    if (output == NULL) {
        printf("Unable to open output file\n");
        fclose(file);
        return 1;
    }
    while (!feof(file)) {
        float meters;
        if (fscanf(file, "%f", &meters) == 1) {
            fprintf(output, "%.3f\n", convert(meters));
        }
    }
    fclose(file);
    fclose(output);
    return 0;
}
