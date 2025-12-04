#include <stdio.h>
#include "functions.h"
int main()
{
    struct Expense expenses[MAX]; //Array to store all expenses
    int count = 0; //Current number of expenses
    int choice = 0; //User menu choice
    //Controled while loop which runs until user chooses 5
    while (choice != 5)
    {
        //Display menu
        printf("\n======DAILY EXPENSE TRACKER======\n");
        printf("1. Add New Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Total Amount Spent\n");
        printf("4. Save Expenses to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        //Handle user choice using switch
        switch (choice)
        {
            case 1:
            addExpense(expenses, &count); //Call function to add expense
            break;
            case 2:
            viewExpenses(expenses, count); //Call function to view expenses
            break;
            case 3:
            totalSpent(expenses, count); //Call function to calculate total
            break;
            case 4:
            saveToFile(expenses, count); //Call function to save expenses
            break;
            case 5:
            printf("\nEXIT...THANK YOU!\n"); //Exit message
            break;
            default:
            printf("\nInvalid Choice! Please Try Again.\n"); //Invalid input
        }
    }
    return 0;
}