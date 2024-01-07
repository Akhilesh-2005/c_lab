#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void writeStudentData(FILE *file, struct Student student) {
    fprintf(file, "%s %d %.2f\n", student.name, student.rollNumber, student.marks);
}

void readStudentData(FILE *file) {
    struct Student student;

    printf("\nReading student data from file:\n");

    while (fscanf(file, "%s %d %f", student.name, &student.rollNumber, &student.marks) != EOF) {
        printf("Name: %s\n", student.name);
        printf("Roll Number: %d\n", student.rollNumber);
        printf("Marks: %.2f\n\n", student.marks);
    }
}

int main() {
    FILE *file;
    struct Student student;
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    file = fopen("student_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter student data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", student.name);
        printf("Roll Number: ");
        scanf("%d", &student.rollNumber);
        printf("Marks: ");
        scanf("%f", &student.marks);

        writeStudentData(file, student);
    }

    fclose(file);
    printf("Student data written to file successfully.\n");

    file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    readStudentData(file);

    fclose(file);

    return 0;
}
