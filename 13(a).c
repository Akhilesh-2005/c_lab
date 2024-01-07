#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "sample.txt";

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(file, "Hello, this is a sample text written to the file.\n");
    fprintf(file, "You can add more lines as needed.\n");
    
    fclose(file);
    printf("Data written to the file successfully.\n");

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("Reading from the file:\n");
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}
