#include <stdio.h>
#include <string.h>

// Constant to define maximum number of lectures
#define MAX_LECTURES 5

// Structure to store lecture details
typedef struct {
    char lecturerName[50];
    char subjectName[50];
    char courseName[50];
} Lecture;

// Function Prototypes
void initializeLecture(Lecture* lecture, const char* lecturerName, const char* subjectName, const char* courseName);
void addLecture(Lecture lectures[], int* count);
void displayLectures(const Lecture lectures[], int count);
void clearInputBuffer();

int main() {
    Lecture lectures[MAX_LECTURES];
    int lectureCount = 0;
    int choice;

    // Main menu loop
    do {
        printf("\n===== Lecture Management Menu =====\n");
        printf("1. Add Lecture\n");
        printf("2. Display All Lectures\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear newline left in input buffer

        switch (choice) {
            case 1:
                if (lectureCount < MAX_LECTURES) {
                    addLecture(lectures, &lectureCount);
                } else {
                    printf(" Maximum of %d lectures reached!\n", MAX_LECTURES);
                }
                break;
            case 2:
                displayLectures(lectures, lectureCount);
                break;
            case 3:
                printf(" Exiting Lecture Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to initialize lecture values (like constructor)
void initializeLecture(Lecture* lecture, const char* lecturerName, const char* subjectName, const char* courseName) {
    strcpy(lecture->lecturerName, lecturerName);
    strcpy(lecture->subjectName, subjectName);
    strcpy(lecture->courseName, courseName);
}

// Function to add a new lecture
void addLecture(Lecture lectures[], int* count) {
    char lecturerName[50], subjectName[50], courseName[50];

    printf("\n--- Add Lecture ---\n");
    printf("Enter Lecturer Name: ");
    fgets(lecturerName, sizeof(lecturerName), stdin);
    lecturerName[strcspn(lecturerName, "\n")] = '\0'; // Remove newline

    printf("Enter Subject Name : ");
    fgets(subjectName, sizeof(subjectName), stdin);
    subjectName[strcspn(subjectName, "\n")] = '\0';

    printf("Enter Course Name  : ");
    fgets(courseName, sizeof(courseName), stdin);
    courseName[strcspn(courseName, "\n")] = '\0';

    initializeLecture(&lectures[*count], lecturerName, subjectName, courseName);
    (*count)++;

    printf(" Lecture added successfully!\n");
}

// Function to display all lecture details
void displayLectures(const Lecture lectures[], int count) {
    if (count == 0) {
        printf("\n No lectures available.\n");
        return;
    }

    printf("\n All Lecture Details:\n");
    for (int i = 0; i < count; i++) {
        printf("\n--- Lecture %d ---\n", i + 1);
        printf("Lecturer Name : %s\n", lectures[i].lecturerName);
        printf("Subject Name  : %s\n", lectures[i].subjectName);
        printf("Course Name   : %s\n", lectures[i].courseName);
    }
}

// Helper function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
