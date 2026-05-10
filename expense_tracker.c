#include <stdio.h>
#include <stdlib.h>

// Colors
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// Structure
struct Expense {
    char item[50];
    float amount;
};

struct Expense e[100];
int count = 0;

// Functions
void line() {
    printf(BLUE "+--------------------------------------+\n" RESET);
}

void title(char text[]) {
    line();
    printf(BLUE "| %-36s |\n" RESET, text);
    line();
}

void pauseScreen() {
    printf(YELLOW "\nPress Enter to continue..." RESET);
    getchar();
    getchar();
}

// Add Expense
void addExpense() {

    printf("\n Enter Expense Name : ");
    scanf("%s", e[count].item);

    printf(" Enter Amount       : ");
    scanf("%f", &e[count].amount);

    count++;

    printf(GREEN "\n ✔ Expense Added Successfully!\n" RESET);
}

// Display Expenses
void displayExpenses() {

    float total = 0;

    if (count == 0) {
        printf(RED "\n No expenses found!\n" RESET);
        return;
    }

    line();

    for (int i = 0; i < count; i++) {

        printf(" %-15s : Rs. %.2f\n",
               e[i].item,
               e[i].amount);

        total += e[i].amount;
    }

    line();

    printf(GREEN "\n Total Expense = Rs. %.2f\n" RESET, total);
}

// Main
int main() {

    int choice;

    while (1) {

        system("cls || clear");

        title("EXPENSE TRACKER SYSTEM");

        printf(YELLOW " 1. Add Expense\n" RESET);
        printf(YELLOW " 2. View Expenses\n" RESET);
        printf(YELLOW " 3. Exit\n" RESET);

        line();

        printf(CYAN " Enter your choice: " RESET);
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addExpense();
                pauseScreen();
                break;

            case 2:
                displayExpenses();
                pauseScreen();
                break;

            case 3:
                printf(GREEN "\n Thank You!\n" RESET);
                exit(0);

            default:
                printf(RED "\n Invalid Choice!\n" RESET);
                pauseScreen();
        }
    }

    return 0;
}