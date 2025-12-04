#include <stdio.h>
#include <string.h>
#include "functions.h"
//Function to add a new expense
void addExpense(struct Expense expenses[], int *count)
{
    printf("\nEnter Expense Name: ");
    scanf(" %49[^\n]", expenses[*count].name); //Read string with spaces
    getchar();
    printf("\nEnter Amount: ");
    scanf("%f", &expenses[*count].amount); //Read amount spent
    printf("\nEnter Date: ");
    scanf(" %s", expenses[*count].date); //Read date
    (*count)++; //Increase the the total expense count
    printf("\nExpense Added Successfully!\n");
}
//Function to view all expenses
void viewExpenses(struct Expense expenses[], int count)
{
    if (count == 0)
    {
        printf("\nNo Expenses Recorded Yet!\n");
        return;
    }
    printf("\n-----YOUR EXPENSES-----\n");
    printf("S.No.  Name  \t  Amount  \t  Date\n");
    //Loop through all expenses and print them
    for (int i = 0; i < count; i++)
    {
        printf("%d.  %s  \t  Rs%.2f  \t  %s\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}
//Function to calculate total money spent
void totalSpent(struct Expense expenses[], int count)
{
    float sum = 0;
    //Sum all expense amounts
    for (int i = 0; i < count; i++)
    {
        sum += expenses[i].amount;
    }
    printf("\nTotal Money Spent: Rs%.2f\n", sum);
}
//Function to save expenses to a text file
void saveToFile(struct Expense expenses[], int count)
{
    //Open file in append mode so that the old data is not erased
    FILE *fp = fopen("expenses.txt", "a");
    if (fp == NULL)
    {
        printf("\nError Opening File!\n");
        return;
    }
    //Write each expense to the file
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s | %.2f | %s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
    //Calculate total before writing to file
    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += expenses[i].amount;
    }
    //Write total amount below expenses
    fprintf(fp, "Total Spent So Far: %.2f\n", total);
    //Separator for readability
    fprintf(fp, "----------------------------------\n") ;
    fclose(fp); //Close the file
    printf("\nExpenses Saved Successfully!\n");
}