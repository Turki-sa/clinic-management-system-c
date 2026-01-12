#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void mainMenu(void);
void DataAnalysisMenu(void);
void addNewPatient(void);
void addNewDoctor(void);
int isStrictlyIncreasing(int arr[], int size);

struct Patient {
    int patientID;
    char fullName[50];
    char phone[20];
    int preferredDoctorID;
};

struct Doctor {
    int doctorID;
    char doctorName[50];
    char specialty[50];
    int availableAppointment;
    int patientIDAssigned;
};

struct Patient patients[100];
struct Doctor doctors[100];

int patientCount = 0;
int doctorCount = 0;

void addNewPatient(void) {
    if (patientCount >= 100) {
        printf("Patient list is full!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &patients[patientCount].patientID);

    printf("Enter Full Name: ");
    scanf(" %49[^\n]", patients[patientCount].fullName);

    printf("Enter Patient Phone Number: ");
    scanf(" %19s", patients[patientCount].phone);

    printf("Enter Preferred Doctor ID (or -1 for none): ");
    scanf("%d", &patients[patientCount].preferredDoctorID);

    printf("\nPatient added successfully!\n");
    patientCount++;
}

void addNewDoctor(void) {
    if (doctorCount >= 100) {
        printf("Doctor list is full!\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &doctors[doctorCount].doctorID);

    printf("Enter Doctor Name: ");
    scanf(" %49[^\n]", doctors[doctorCount].doctorName);

    printf("Enter Doctor Specialty: ");
    scanf(" %49[^\n]", doctors[doctorCount].specialty);

    printf("Enter Available Appointments: ");
    scanf("%d", &doctors[doctorCount].availableAppointment);

    printf("Enter Current Patient ID (or -1 for none): ");
    scanf("%d", &doctors[doctorCount].patientIDAssigned);

    printf("\nDoctor added successfully!\n");
    doctorCount++;
}

int isStrictlyIncreasing(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void DataAnalysisMenu(void) {
    int option2;
    int numOfElements;
    int arr[20];

    printf("\nData Analysis Tools Menu:\n");
    printf("1 - Check if a list of numbers is increasing\n");
    printf("2 - Back to main menu\n");
    printf("Enter your choice: ");
    scanf("%d", &option2);

    switch (option2) {
        case 1:
            printf("Enter the number of elements (max 20): ");
            scanf("%d", &numOfElements);

            while (numOfElements <= 1 || numOfElements > 20) {
                printf("Wrong number of elements (2-20): ");
                scanf("%d", &numOfElements);
            }

            printf("Enter %d integers: ", numOfElements);
            for (int i = 0; i < numOfElements; i++) {
                scanf("%d", &arr[i]);
            }

            if (isStrictlyIncreasing(arr, numOfElements)) {
                printf("The list is strictly increasing.\n");
            } else {
                printf("The list is NOT strictly increasing.\n");
            }
            break;

        case 2:
            mainMenu();
            break;

        default:
            printf("Wrong choice!\n");
            DataAnalysisMenu();
            break;
    }
}

void mainMenu(void) {
    int option;

    printf("\n--- Clinic Menu ---\n");
    printf("1 - Add a new patient\n");
    printf("2 - Add a new doctor\n");
    printf("3 - Print all patients information\n");
    printf("4 - Print all doctors information\n");
    printf("5 - Quit\n");
    printf("6 - Data Analysis Tool\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            addNewPatient();
            break;

        case 2:
            addNewDoctor();
            break;

        case 3:
            printf("\n--- All Patients List ---\n");
            printf("%-10s %-20s %-15s %-10s\n", "ID", "Name", "Phone", "Doc ID");
            printf("-----------------------------------------------------------\n");

            for (int i = 0; i < patientCount; i++) {
                if (patients[i].preferredDoctorID == -1) {
                    printf("%-10d %-20s %-15s %-10s\n",
                           patients[i].patientID,
                           patients[i].fullName,
                           patients[i].phone,
                           "None");
                } else {
                    printf("%-10d %-20s %-15s %-10d\n",
                           patients[i].patientID,
                           patients[i].fullName,
                           patients[i].phone,
                           patients[i].preferredDoctorID);
                }
            }
            break;

        case 4:
            printf("\n--- All Doctors List ---\n");
            printf("%-10s %-20s %-20s %-10s %-10s\n",
                   "ID", "Name", "Specialty", "Slots", "Pat ID");
            printf("----------------------------------------------------------------------------\n");

            for (int i = 0; i < doctorCount; i++) {
                if (doctors[i].patientIDAssigned == -1) {
                    printf("%-10d %-20s %-20s %-10d %-10s\n",
                           doctors[i].doctorID,
                           doctors[i].doctorName,
                           doctors[i].specialty,
                           doctors[i].availableAppointment,
                           "None");
                } else {
                    printf("%-10d %-20s %-20s %-10d %-10d\n",
                           doctors[i].doctorID,
                           doctors[i].doctorName,
                           doctors[i].specialty,
                           doctors[i].availableAppointment,
                           doctors[i].patientIDAssigned);
                }
            }
            break;

        case 5:
            printf("Exiting Program\n");
            return;

        case 6:
            DataAnalysisMenu();
            break;

        default:
            printf("Wrong option!\n");
            break;
    }
}

int main(void) {
    mainMenu();
    return 0;
}