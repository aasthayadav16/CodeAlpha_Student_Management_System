
#include <stdio.h>

struct Student {
    int roll_no;
    char name[100];
    int age;
    float marks;
};

void inputStudentInfo(struct Student s[], int n) {

    for(int i = 0; i < n; i++) {

        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll_no);

        printf("Enter Name: ");
        scanf(" %99[^\n]", s[i].name);

        printf("Enter Age: ");
        scanf("%d", &s[i].age);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void printStudentInfo(struct Student s) {

    printf("\nRoll Number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Marks: %.2f\n", s.marks);
}

void displayStudents(struct Student s[], int n) {

    printf("\n===== STUDENT DETAILS =====\n");
    for(int i = 0; i < n; i++) {
        
        printf("\nStudent %d\n", i + 1);

        printStudentInfo(s[i]);
    }
}

int main() {

    struct Student s[5];
    int choice;
    int dataEntered = 0;

    do {

        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Enter Student Details\n");
        printf("2. Display Student Details\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                inputStudentInfo(s, 5);
                dataEntered = 1;
                printf("\nStudent details entered successfully!\n");
                break;

            case 2:
                if(dataEntered == 1) {
                    displayStudents(s, 5);
                }
                else {
                    printf("\nPlease enter student details first!\n");
                }
                break;

            case 3:
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}
