#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define MAX 100 //Maximum number of expenses
//Structure to store expense details
struct Expense 
{
    char name[50]; //Name of the expense
    float amount; //Amount spent
    char date[15]; //Date of the expense
};
void addExpense(struct Expense expenses[], int *count); //Function to add a new expense
void viewExpenses(struct Expense expenses[], int count); //Function to view all expenses
void totalSpent(struct Expense expenses[], int count); //Calculate total money spent
void saveToFile(struct Expense expenses[], int count); //Save all expenses to a text file
#endif
